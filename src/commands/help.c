#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help(char *path)
{
    char cmd[150] = "more ";
    strcat(cmd, path);
    strcat(cmd, "/../manual/readme");
    system(cmd);
}