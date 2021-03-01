#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void change_dir(char **param, int paramLen, char *path) 
{
    if(paramLen == 1) {
        printf("%s\n", path);
    }
    else {
        chdir(param[1]);
        getcwd(path, 100);
    }
}