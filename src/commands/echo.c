#include <stdio.h>


void echo(char **param, int paramLen)
{
    for(int i=1; i<paramLen; i++) {
        printf("%s ", param[i]);
    }
        printf("\n");
}