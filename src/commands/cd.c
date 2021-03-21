#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void change_dir(char **param, int paramLen, char *path) 
{
    if(paramLen == 1) {
        printf("%s\n", path);
    }
    else if(chdir(param[1])==0) {
        getcwd(path, 100);
    }
    else {
        printf("Error: Directory '%s' does not exist!\n", param[1]);
    }
}