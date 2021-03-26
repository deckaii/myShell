/*
Title: A simple shell
Author: The Ky Lien
Purpose: Change working directory or print current working directory.

references:
- https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/
- https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.bpxbd00/rtgtc.htm - getcwd
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void change_dir(char **param, int paramLen, char *path) 
{
    if(paramLen == 1) { // print current directory if only 'cd' is entered
        printf("%s\n", path);
    }
    else if(chdir(param[1])==0) {
        getcwd(path, 100);
    }
    else { // print error if directory does not exist
        printf("Error: Directory '%s' does not exist!\n", param[1]);
    }
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/