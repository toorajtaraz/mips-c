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
uint32_t reg[32];
byte program_memory[33];
byte data_memory[33];
int program_counter = 0;
void init()
{
    reg[0] = 0;
    for (int i = 1; i < 32; i++)
    {
        reg[i] = -1;
    }
    overflow = false;
    for (int i = 0; i < 33; i++)
    {
        program_memory[i] = -1;
        data_memory[i] = -1;
    }
    program_counter = 0;
}

void get_input()
{
    scanf("%33s", program_memory);
    program_memory[32] = '\0';
}
void alu(int alu_fun, int address1, int address2, int dist)
{
}

void alui(int alu_fun, int address1, int address2, int32_t immidiate)
{
}

int get_addres(int start_p, int bound)
{
    char *start = &program_memory[start_p];
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
}
void lw(int source, int target, int offset)
{
}
void beq(int source, int target, int goto_add)
{
}
void bne(int source, int target, int goto_add)
{
}
void jump(int addres)
{
}
void control_unit()
{
    //R type
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '0' && program_memory[4] == '0' && program_memory[5] == '0')
    {
        //ADD
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '0' && program_memory[30] == '0' && program_memory[31] == '0')
        {
            alu(ADD, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //SUB
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '0' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            alu(SUB, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //OR
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '1' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            alu(OR, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //AND
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '1' && program_memory[30] == '0' && program_memory[31] == '0')
        {
            alu(AND, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
        //SLT
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '1' && program_memory[29] == '0' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            alu(SLT, get_addres(6, 5), get_addres(11, 5), get_addres(16, 5));
        }
    }
    //I type
    //SW
    if (program_memory[0] == '1' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '1')
    {
        sw(get_addres(6, 5), get_addres(11, 5), get_addres(16, 12));
    }
    //LW
    if (program_memory[0] == '1' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '1')
    {
        lw(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //ADDI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '0' && program_memory[5] == '0')
    {
        alui(ADDI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //SLTI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '0')
    {
        alui(SLTI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //ANDI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '0')
    {
        alui(ANDI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //ORI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '1')
    {
        alui(ORI, get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //BEQ
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '0')
    {
        beq(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //BNE
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '1')
    {
        bne(get_addres(6, 5), get_addres(11, 5), get_addres(16, 16));
    }
    //J type
    //J
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '0')
    {
        jump(get_addres(6, 26));
    }
}

void sign_extender()
{
}

int main()
{
}