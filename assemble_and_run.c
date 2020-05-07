/*
 * =====================================================================================
 *
 *       Filename:  assemble_and_run.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/07/2020 17:01:55
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
#include "assembler.h"
int count_lines(char *filename)
{
    FILE *flp;
    int count = 0;
    char c;
    flp = fopen(filename, "r");
    if (flp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
    for (c = getc(flp); c != EOF; c = getc(flp))
        if (c == '\n')
            count = count + 1;

    fclose(flp);
    printf("The file %s has %d lines\n ", filename, count);

    return count;
}
int main()
{
    puts("please enter path yout assembly file :\n\n");
    char path[100];
    for (int i = 0; i < 100; i++)
    {
        path[i] = '\0';
    }
    scanf("%s", path);
    int lines = count_lines(path);
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Could not open file %s", path);
        return -1;
    }
    char cmd[32];
    char **final = malloc(sizeof(char *) * lines + 1);
    while (final == NULL)
    {
        final = malloc(sizeof(char *) * lines + 1);
    }
    for (int i = 0; i < lines + 1; i++)
    {
        final[i] = calloc(33,sizeof(char));
    }
    
    int k = 0;
    while (fgets(cmd, 32, file) != NULL)
    {
        print_single_command(cmd,final[k++]);
    }
    fclose(file);
    puts("\n\n");
    puts("start running...\n");
    run(final, lines + 1);
    
    return 0;
}

