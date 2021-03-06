/*
Title: A simple shell
Author: The Ky Lien
Purpose: Print out the help manual for shell using the more filter

references:
- https://www.programiz.com/c-programming/library-function/string.h/strcat
*/         

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

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/