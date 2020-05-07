/*
 * =====================================================================================
 *
 *       Filename:  assembler.c
 *
 *    Description: generate machine code  
 *
 *        Version:  1.0
 *        Created:  05/06/2020 21:52:37
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
#include <string.h>
#include "./assembler.h"

void decToBinary(int n, char *start, int bits)
{
    int flag = 0;
    if (n < 0)
    {
        flag = 1;
        n *= -1;
    }
    int count = 0;
    for (int i = bits - 1; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            start[count] = '1';
        else
            start[count] = '0';
        count++;
    }
    if (flag)
    {
        char onesComp[bits+1];
        int carry = 1;
        for (int i = 0; i < bits; i++)
        {
            if (start[i] == '1')
            {
                onesComp[i] = '0';
            }
            else if (start[i] == '0')
            {
                onesComp[i] = '1';
            }
        }
        onesComp[bits] = '\0';
        for (int i = bits - 1; i >= 0; i--)
        {
            if (onesComp[i] == '1' && carry == 1)
            {
                start[i] = '0';
            }
            else if (onesComp[i] == '0' && carry == 1)
            {
                start[i] = '1';
                carry = 0;
            }
            else
            {
                start[i] = onesComp[i];
            }
        }
    }
}
int reg_num(char *str1)
{
    if (strcmp(str1, "ze") == 0)
    {
        return zero;
    }
    if (strcmp(str1, "at") == 0)
    {
        return at;
    }
    if (strcmp(str1, "v0") == 0)
    {
        return v0;
    }
    if (strcmp(str1, "v1") == 0)
    {
        return v1;
    }
    if (strcmp(str1, "a0") == 0)
    {
        return a0;
    }
    if (strcmp(str1, "a1") == 0)
    {
        return a1;
    }
    if (strcmp(str1, "a2") == 0)
    {
        return a2;
    }
    if (strcmp(str1, "a3") == 0)
    {
        return a3;
    }
    if (strcmp(str1, "t0") == 0)
    {
        return t0;
    }
    if (strcmp(str1, "t1") == 0)
    {
        return t1;
    }
    if (strcmp(str1, "t2") == 0)
    {
        return t2;
    }
    if (strcmp(str1, "t3") == 0)
    {
        return t3;
    }
    if (strcmp(str1, "t4") == 0)
    {
        return t4;
    }
    if (strcmp(str1, "t5") == 0)
    {
        return t5;
    }
    if (strcmp(str1, "t6") == 0)
    {
        return t6;
    }
    if (strcmp(str1, "t7") == 0)
    {
        return t7;
    }
    if (strcmp(str1, "t8") == 0)
    {
        return t8;
    }
    if (strcmp(str1, "t9") == 0)
    {
        return t9;
    }
    if (strcmp(str1, "s0") == 0)
    {
        return s0;
    }
    if (strcmp(str1, "s1") == 0)
    {
        return s1;
    }
    if (strcmp(str1, "s2") == 0)
    {
        return s2;
    }
    if (strcmp(str1, "s3") == 0)
    {
        return s3;
    }
    if (strcmp(str1, "s4") == 0)
    {
        return s4;
    }
    if (strcmp(str1, "s5") == 0)
    {
        return s5;
    }
    if (strcmp(str1, "s6") == 0)
    {
        return s6;
    }
    if (strcmp(str1, "s7") == 0)
    {
        return s7;
    }
    if (strcmp(str1, "k0") == 0)
    {
        return k0;
    }
    if (strcmp(str1, "k1") == 0)
    {
        return k1;
    }
    if (strcmp(str1, "fp") == 0)
    {
        return fp;
    }
    if (strcmp(str1, "gp") == 0)
    {
        return gp;
    }
    if (strcmp(str1, "sp") == 0)
    {
        return sp;
    }
    if (strcmp(str1, "ra") == 0)
    {
        return ra;
    }
    return -1;
}
void print_final(char *final)
{
    for (int i = 0; i < 32; i++)
    {
        printf("%c", final[i]);
    }
}
char *print_single_command(char *cmd, char *final)
{
    char type[5];
    for (int i = 0; i < 5; i++)
    {
        type[i] = '\0';
    }

    char par1[3];
    par1[2] = '\0';
    char par2[3];
    par2[2] = '\0';
    char par3[3];
    par3[2] = '\0';
    int imm;
    int i = 0;
    while (i < 32 && cmd[i] != ' ')
    {
        i++;
    }
    i--;
    int j = 0;
    while (j <= i)
    {
        type[j] = cmd[j];
        j++;
    }
    puts("\n\n");
    i++;
    while (i < 32 && cmd[i] == ' ')
    {
        i++;
    }
    if (strcmp(type, ADD) == 0)
    {
        printf("add detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        final[21] = '0';
        final[22] = '0';
        final[23] = '0';
        final[24] = '0';
        final[25] = '0';
        final[26] = '1';
        final[27] = '0';
        final[28] = '0';
        final[29] = '0';
        final[30] = '0';
        final[31] = '0';
        par1[0] = cmd[i];
        i++;
        par1[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i];
        i++;
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par3[0] = cmd[i];
        i++;
        par3[1] = cmd[i];
        i++;
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par3), &final[11], 5);
        decToBinary(reg_num(par1), &final[16], 5);
        print_final(final);
        return final;
    }
    if (strcmp(type, SUB) == 0)
    {
        printf("sub detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        final[21] = '0';
        final[22] = '0';
        final[23] = '0';
        final[24] = '0';
        final[25] = '0';
        final[26] = '1';
        final[27] = '0';
        final[28] = '0';
        final[29] = '0';
        final[30] = '1';
        final[31] = '0';
        par1[0] = cmd[i];
        i++;
        par1[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i];
        i++;
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par3[0] = cmd[i];
        i++;
        par3[1] = cmd[i];
        i++;
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par3), &final[11], 5);
        decToBinary(reg_num(par1), &final[16], 5);
        print_final(final);
        return final;
    }
    if (strcmp(type, OR) == 0)
    {
        printf("or detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        final[21] = '0';
        final[22] = '0';
        final[23] = '0';
        final[24] = '0';
        final[25] = '0';
        final[26] = '1';
        final[27] = '0';
        final[28] = '0';
        final[29] = '1';
        final[30] = '0';
        final[31] = '1';
        par1[0] = cmd[i];
        i++;
        par1[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i];
        i++;
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par3[0] = cmd[i];
        i++;
        par3[1] = cmd[i];
        i++;
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par3), &final[11], 5);
        decToBinary(reg_num(par1), &final[16], 5);
        print_final(final);
        return final;
    }
    if (strcmp(type, AND) == 0)
    {
        printf("and detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        final[21] = '0';
        final[22] = '0';
        final[23] = '0';
        final[24] = '0';
        final[25] = '0';
        final[26] = '1';
        final[27] = '0';
        final[28] = '0';
        final[29] = '1';
        final[30] = '0';
        final[31] = '0';
        par1[0] = cmd[i];
        i++;
        par1[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i];
        i++;
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par3[0] = cmd[i];
        i++;
        par3[1] = cmd[i];
        i++;
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par3), &final[11], 5);
        decToBinary(reg_num(par1), &final[16], 5);
        print_final(final);
        return final;
    }
    if (strcmp(type, SLT) == 0)
    {
        printf("slt detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        final[21] = '0';
        final[22] = '0';
        final[23] = '0';
        final[24] = '0';
        final[25] = '0';
        final[26] = '1';
        final[27] = '0';
        final[28] = '1';
        final[29] = '0';
        final[30] = '1';
        final[31] = '0';
        par1[0] = cmd[i];
        i++;
        par1[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i];
        i++;
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par3[0] = cmd[i];
        i++;
        par3[1] = cmd[i];
        i++;
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par3), &final[11], 5);
        decToBinary(reg_num(par1), &final[16], 5);
        print_final(final);
        return final;
    }
    if (strcmp(type, J) == 0)
    {
        printf("j detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '1';
        final[5] = '0';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[6], 26);
        print_final(final);
        return final;
    }
    if (strcmp(type, SW) == 0)
    {
        printf("sw detected !\n\n");
        final[0] = '1';
        final[1] = '0';
        final[2] = '1';
        final[3] = '0';
        final[4] = '1';
        final[5] = '1';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, LW) == 0)
    {
        printf("lw detected !\n\n");
        final[0] = '1';
        final[1] = '0';
        final[2] = '0';
        final[3] = '0';
        final[4] = '1';
        final[5] = '1';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, ADDI) == 0)
    {
        printf("addi detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '1';
        final[3] = '0';
        final[4] = '0';
        final[5] = '0';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, SLTI) == 0)
    {
        printf("slti detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '1';
        final[3] = '0';
        final[4] = '1';
        final[5] = '0';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, ANDI) == 0)
    {
        printf("andi detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '1';
        final[3] = '1';
        final[4] = '0';
        final[5] = '0';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, ORI) == 0)
    {
        printf("ori detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '1';
        final[3] = '1';
        final[4] = '0';
        final[5] = '1';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par2), &final[6], 5);
        decToBinary(reg_num(par1), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, BEQ) == 0)
    {
        printf("beq detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '1';
        final[4] = '0';
        final[5] = '0';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par1), &final[6], 5);
        decToBinary(reg_num(par2), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    if (strcmp(type, BNE) == 0)
    {
        printf("bne detected !\n\n");
        final[0] = '0';
        final[1] = '0';
        final[2] = '0';
        final[3] = '1';
        final[4] = '0';
        final[5] = '1';
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par1[0] = cmd[i++];
        par1[1] = cmd[i++];
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        par2[0] = cmd[i++];
        par2[1] = cmd[i];
        i++;
        while (i < 32 && cmd[i] == ' ')
        {
            i++;
        }
        char num[10] = {'\0'};
        int j = 0;
        while (i < 32 && cmd[i] != ' ')
        {
            num[j] = cmd[i];
            j++;
            i++;
        }
        decToBinary(reg_num(par1), &final[6], 5);
        decToBinary(reg_num(par2), &final[11], 5);
        int n;
        sscanf(num, "%d", &n);
        decToBinary(n, &final[16], 16);
        print_final(final);
        return final;
    }
    return final;
}

