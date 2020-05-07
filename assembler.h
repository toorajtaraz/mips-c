/*
 * =====================================================================================
 *
 *       Filename:  assembler.h
 *
 *    Description: assembling mips code 
 *
 *        Version:  1.0
 *        Created:  04/30/2020 17:19:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TOORAJ TARAZ (TOORAJ_TRZ), TOORAJ.INFO@GMAIL.COM
 *   Organization:  RC|FUM
 *
 * =====================================================================================
 */


#define ADD "add"
#define SUB "sub"
#define OR "or "
#define AND "and"
#define SLT "slt"
#define J "j  "
#define SW "sw"
#define LW "lw"
#define ADDI "addi"
#define SLTI "slti"
#define ANDI "andi"
#define ORI "ori"
#define BEQ "beq"
#define BNE "bne"

#define zero 0
#define at 1
#define v0 2
#define v1 3
#define a0 4
#define a1 5
#define a2 6
#define a3 7
#define t0 8
#define t1 9
#define t2 10
#define t3 11
#define t4 12
#define t5 13
#define t6 14
#define t7 15
#define t8 24
#define t9 25
#define s0 16
#define s1 17
#define s2 18
#define s3 19
#define s4 20
#define s5 21
#define s6 22
#define s7 23
#define k0 26
#define k1 27
#define fp 30
#define sp 29
#define gp 28
#define ra 31



void print_single_command(char *cmd);