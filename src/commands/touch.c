/*
Title: A simple shell
Author: The Ky Lien
Purpose: Create a new file with the name given in arguement1

references:
- https://www.programiz.com/c-programming/library-function/string.h/strcat
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void touch(char **param)
{
    FILE *fptr;
    fptr = fopen(param[1], "rb+");
    if(fptr == NULL) {
        fptr = fopen(param[1], "wb");
    }
    else {
        printf("File '%s' already exists!\n", param[1]);
    }
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/