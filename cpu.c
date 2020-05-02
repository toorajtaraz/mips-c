/*
 * =====================================================================================
 *
 *       Filename:  cpu.c
 *
 *    Description: sc cpu eml 
 *
 *        Version:  1.0
 *        Created:  04/30/2020 17:20:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TOORAJ TARAZ (TOORAJ_TRZ), TOORAJ.INFO@GMAIL.COM
 *   Organization:  RC|FUM
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"
#include <stdbool.h>
bool overflow = false;
uint32_t reg[33];
byte *all_program_memories[33];
uint32_t data_memory[1000];
int program_counter = 0;
void init()
{
    reg[0] = 0;
    for (int i = 1; i < 32; i++)
    {
        reg[i] = -1;
    }
    overflow = false;
    for (int i = 0; i < 100; i++)
    {
        data_memory[i] = -1;
    }
    program_counter = 0;
}
void general_handler(int number_of_commands);
void get_input()
{
    int n;
    scanf("%d",&n);
    general_handler(n);
    for (int i = 0; i < n; i++)
        scanf("%32s\n", all_program_memories[i]);
}
void alu(int alu_fun, int address1, int address2, int dist)
{
    if (alu_fun == ADD) 
    {
        reg[dist] = reg[address1] + reg[address2];
        return;
    }
    if (alu_fun == SUB)
    {
        reg[dist] = reg[address1] - reg[address2];
        return;
    }
    if (alu_fun == AND)
    {
        reg[dist] = reg[address1] & reg[address2];
        return;
    }
    if (alu_fun == OR)
    {
        reg[dist] = reg[address1] | reg[address2];
        return;
    }
    if (alu_fun == SLT)
    {
        if (reg[address1] < reg[address2])
        {
            reg[dist] = 1;
        }
        else
        {
            reg[dist] = 0;
        }
        
        return;
    }
}

void alui(int alu_fun, int address1, int address2, int32_t immidiate)
{
    if (alu_fun == ADDI)
    {
        reg[address2] = reg[address1] + immidiate;
        return;
    }
    if (alu_fun == ANDI)
    {
        reg[address2] = reg[address1] & immidiate;
        return;
    }
    if (alu_fun == ORI)
    {
        reg[address2] = reg[address1] | immidiate;
        return;
    }
    if (alu_fun == SLTI)
    {
        if (reg[address1] < immidiate)
        {
            reg[address2] = 1;
        }
        else
        {
            reg[address2] = 0;
        }
        
        return;
    }
}

int get_addres(int start_p, int bound)
{
    char *start = (char*) &all_program_memories[program_counter][start_p];
    int total = 0;
    int i = 0;
    while (i < bound)
    {
        total <<= 1;
        if (*start++ == '1')
            total ^= 1;
        i++;
    }
    return total;
}
void sw(int source, int target, int offset)
{
    data_memory[source + offset] = reg[target];
}
void lw(int source, int target, int offset)
{
    reg[target] = data_memory[source + offset];
}
void beq(int source, int target, int goto_add)
{
    if (source == target)
    {
        program_counter = goto_add;
    }
    
}
void bne(int source, int target, int goto_add)
{
    if (source != target)
    {
        program_counter = goto_add + 1;
    }
}
void jump(int addres)
{
    program_counter = addres;
}
int handle_2c (int start_p, int bound)
{
    if (all_program_memories[program_counter][start_p] == '0')
    {
        return 1;
    }
    
    char *start = (char*) &all_program_memories[program_counter][start_p];
    int total = 0;
    int i = 0;
    while (i < bound)
    {
        if (start[i] == '1')
            start[i] = '0';
        else
            start[i] = '1';
        i++;
    }
    i--;
    bool cary = false;
    if (start[i] == '0')
    {
        start[i] = '1';
        return -1;
    }
    else 
        cary = true; 
    i--;
    while (i >= 0 && cary)
    {
        if (start[i] == '0')
        {
            start[i] = '1';
            cary = false;
        }
        else
        {
            start[i] = '0';
        }
        i--; 
    }
    
    return -1;
}
void control_unit()
{
    //R type
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '0' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '0')
    {
        //ADD
        if (all_program_memories[program_counter][26] == '1' && all_program_memories[program_counter][27] == '0' && all_program_memories[program_counter][28] == '0' && all_program_memories[program_counter][29] == '0' && all_program_memories[program_counter][30] == '0' && all_program_memories[program_counter][31] == '0')
        {
            alu(ADD, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //SUB
        if (all_program_memories[program_counter][26] == '1' && all_program_memories[program_counter][27] == '0' && all_program_memories[program_counter][28] == '0' && all_program_memories[program_counter][29] == '0' && all_program_memories[program_counter][30] == '1' && all_program_memories[program_counter][31] == '0')
        {
            alu(SUB, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //OR
        if (all_program_memories[program_counter][26] == '1' && all_program_memories[program_counter][27] == '0' && all_program_memories[program_counter][28] == '0' && all_program_memories[program_counter][29] == '1' && all_program_memories[program_counter][30] == '1' && all_program_memories[program_counter][31] == '0')
        {
            alu(OR, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //AND
        if (all_program_memories[program_counter][26] == '1' && all_program_memories[program_counter][27] == '0' && all_program_memories[program_counter][28] == '0' && all_program_memories[program_counter][29] == '1' && all_program_memories[program_counter][30] == '0' && all_program_memories[program_counter][31] == '0')
        {
            alu(AND, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //SLT
        if (all_program_memories[program_counter][26] == '1' && all_program_memories[program_counter][27] == '0' && all_program_memories[program_counter][28] == '1' && all_program_memories[program_counter][29] == '0' && all_program_memories[program_counter][30] == '1' && all_program_memories[program_counter][31] == '0')
        {
            alu(SLT, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
    }
    //I type
    //SW
    if (all_program_memories[program_counter][0] == '1' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '1' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '1' && all_program_memories[program_counter][5] == '1')
    {
        sw(get_addres(6, 5), get_addres(11, 5), get_addres(16, 12));
    }
    //LW
    if (all_program_memories[program_counter][0] == '1' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '0' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '1' && all_program_memories[program_counter][5] == '1')
    {
        lw(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //ADDI
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '1' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '0')
    {
        int temp = handle_2c(16, 16);
        alui(ADDI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16) * temp);
    }
    //SLTI
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '1' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '1' && all_program_memories[program_counter][5] == '0')
    {
        int temp = handle_2c(16, 16);
        alui(SLTI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16) * temp);
    }
    //ANDI
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '1' && all_program_memories[program_counter][3] == '1' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '0')
    {
        int temp = handle_2c(16, 16);
        alui(ANDI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //ORI
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '1' && all_program_memories[program_counter][3] == '1' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '1')
    {
        int temp = handle_2c(16, 16);
        alui(ORI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16) * temp);
    }
    //BEQ
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '0' && all_program_memories[program_counter][3] == '1' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '0')
    {
        beq(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //BNE
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '0' && all_program_memories[program_counter][3] == '1' && all_program_memories[program_counter][4] == '0' && all_program_memories[program_counter][5] == '1')
    {
        bne(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //J type
    //J
    if (all_program_memories[program_counter][0] == '0' && all_program_memories[program_counter][1] == '0' && all_program_memories[program_counter][2] == '0' && all_program_memories[program_counter][3] == '0' && all_program_memories[program_counter][4] == '1' && all_program_memories[program_counter][5] == '0')
    {
        jump(get_addres(6, 26));
    }
}

void sign_extender()
{
}
void general_handler (int number_of_commands)
{
    for (int i = 0; i < number_of_commands; i++)
    {
        all_program_memories[i] =  calloc(100, sizeof(byte));
    }
    
}
int main()
{
}