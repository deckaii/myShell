#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void redirect(char **param, int paramLen)
{
    for(int i=0; i<paramLen; i++) {
        if(strcmp(param[i], ">") == 0) {
            FILE *fd = fopen(param[i + 1], O_CREAT | O_APPEND | O_WRONLY);

        }
    }
}