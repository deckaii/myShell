/*
Title: A simple shell
Author: The Ky Lien
Purpose: List contents of current working directory

references:
- https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void dir()
{
    struct dirent *de;
    DIR *dir = opendir(".");

    if (dir == NULL) { // returns if can't open directory
        printf("Directory does not exist");
    }
    else {
        while ((de = readdir(dir)) != NULL) {
            if (de->d_type == DT_DIR)
                printf("<DIR>   %s\n", de->d_name);
            else
                printf("<FILE>  %s\n", de->d_name);
        }
    
    closedir(dir);
    }
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/