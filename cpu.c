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
void alu(int alu_fun, uint8_t address1, uint8_t address2)
{
}

void alui(int alu_fun, uint8_t address1, uint32_t immidiate)
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
            /* code */
        }
        //SUB
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '0' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            /* code */
        }
        //OR
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '1' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            /* code */
        }
        //AND
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '0' && program_memory[29] == '1' && program_memory[30] == '0' && program_memory[31] == '0')
        {
            /* code */
        }
        //SLT
        if (program_memory[26] == '1' && program_memory[27] == '0' && program_memory[28] == '1' && program_memory[29] == '0' && program_memory[30] == '1' && program_memory[31] == '0')
        {
            /* code */
        }
    }
    //I type
    //SW
    if (program_memory[0] == '1' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '1')
    {
    }
    //LW
    if (program_memory[0] == '1' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '1')
    {
    }
    //ADDI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '0' && program_memory[5] == '0')
    {
    }
    //SLTI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '0')
    {
    }
    //ANDI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '0')
    {
    }
    //ORI
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '1' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '1')
    {
    }
    //BEQ
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '0')
    {
    }
    //BNE
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '1' && program_memory[4] == '0' && program_memory[5] == '1')
    {
    }
    //J type
    //J
    if (program_memory[0] == '0' && program_memory[1] == '0' && program_memory[2] == '0' && program_memory[3] == '0' && program_memory[4] == '1' && program_memory[5] == '0')
    {
    }
}

void sign_extender()
{
}

int main()
{
}