/*
Title: A simple shell
Author: The Ky Lien
Purpose: Run commands from batchfile to shell

references:
- https://www.zentut.com/c-tutorial/c-file-exists/
- https://stackoverflow.com/questions/7920932/how-to-use-fgets-and-store-every-line-of-a-file-using-an-array-of-char-pointer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 200

int cfileexists(char * filename){
    /* try to open file to read */
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

void get_param_batch(char *filename)
{
    ssize_t read; size_t len = 0;
    if(cfileexists(filename) == 1) { // checks if the file exists in the directory
        FILE *file = fopen(filename, "r");
        char line[100];
        char **param = (char **)malloc(MAX_WORD_LENGTH*sizeof(char));
        char *sh_path = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
        strcat(sh_path, "/bin/");

        char *eof;
        while((eof = fgets(line, sizeof(line), file)) != NULL) {
            char *array[100];
            char *tok;
            int i=0;

            tok = strtok(line, " \n");

            // parses the command into words
            while (tok != NULL) {
                array[i++] = strdup(tok);
                tok = strtok(NULL, " \n");
            }

            // add words to parameters list
            for(int j=0; j<i; j++) {
                // printf("%s\n", array[j]);
                param[j] = array[j];
            }
            
            // printf("%s\n", line);
            if(fork()!=0) {
                wait(NULL);
            }
            else {
                strcat(sh_path, param[0]);
                execv(sh_path, param);
                free(param);
                free(sh_path);
            }

        }

        fclose(file);
        free(param);
        free(sh_path);
    }
    else {
        printf("Usage: ./myshell <filename>\n");
    }
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/