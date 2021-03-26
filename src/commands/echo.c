/*
Title: A simple shell
Author: The Ky Lien
Purpose: Prints out the arguements

references:
*/

#include <stdio.h>


void echo(char **param, int paramLen)
{
    for(int i=1; i<paramLen; i++) {
        printf("%s ", param[i]);
    }
        printf("\n");
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/