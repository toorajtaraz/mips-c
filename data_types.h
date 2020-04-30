/*
 * =====================================================================================
 *
 *       Filename:  data_types.h
 *
 *    Description: data types for sc cpu eml 
 *
 *        Version:  1.0
 *        Created:  04/30/2020 17:18:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TOORAJ TARAZ (TOORAJ_TRZ), TOORAJ.INFO@GMAIL.COM
 *   Organization:  RC|FUM
 *
 * =====================================================================================
 */

#include <stdint.h>

typedef unsigned char byte;
typedef enum
{
    ADD,
    SUB,
    OR,
    AND,
    SLT,
    ADDI,
    SLTI,
    ANDI,
    ORI,
} alu_op;