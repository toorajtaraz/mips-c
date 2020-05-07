# mips-c

mips-c is a C program for simulating mips processors.

## Supported instructions
```
R type :
+add
+sub
+or
+and
+slt
J type :
+j
I type :
+sw
+lw
+addi
+slti
+andi
+ori
+beq
+bne
```
### NOTE
Supported syntax is a bit diffrent for easier assembling !
There is a sample program that will find max and min values in an array, the array is :
```
[1, 5, -3, 4, 2, 7, 8, 9, 10, 1000]
```
## Installation

clone and then compile using gcc

```bash
gcc-9 assemble_and_run.c cpu.c assembler.c -o run.out
./run.out
```