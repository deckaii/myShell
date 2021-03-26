/*
Title: A simple shell
Author: The Ky Lien
Purpose: Run commands from batchfile to shell

references:
- https://www.tutorialspoint.com/c_standard_library/c_function_freopen.htm
- https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
- https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_WORD_LENGTH 200

void exec_command(char *inp, char *out, char **array, int flag) {
    pid_t pid = fork();

    if(pid < 0) {
        printf("Error! Unable to fork\n");
    } else if(pid == 0) {
        if(flag == 1) {
            freopen(inp, "r", stdin);
            execvp(array[0], array);
            fclose(stdin);
        } else if(flag == 2) {
            // printf("%s, %s", array[0], array[1]);
            freopen(out, "w+", stdout);
            execvp(array[0], array);
            fclose(stdout);
        } else if(flag == 3) {
            freopen(out, "a+", stdout);
            execvp(array[0], array);
            fclose(stdout);
        }

        if(execvp(array[0], array) == -1) {
            printf("Error\n");
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void redirect(char **param, int paramLen) {

    char *inp;
    char *out;
    int index=0;
    int flag;

    // checks for the correct use of the redirection
    if(strcmp(param[0], ">") == 0 || strcmp(param[0], ">") == 0) {
        printf("Incorrect usage!\n");
    } else {
        for (int i=1; i<paramLen-1; i++) {
            // printf("%s\n", param[i]); // Test to see what Param[i] is
            if(!(strcmp(param[i], "<"))) { // input redirection
                flag = 1;
                inp = param[i+1];
                param[i] = NULL;
                
            } else if(!(strcmp(param[i], ">"))) { // output redirection
                flag = 2;
                out = param[i+1];
                param[i] = NULL;

            } else if(!(strcmp(param[i], ">>"))) { // new file redirect
                flag = 3;
                out = param[i+1];
                param[i] = NULL;
            }
        }
    }
    exec_command(inp, out, param, flag);
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/