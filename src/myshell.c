/*
Title: A simple shell
Author: The Ky Lien
Purpose: A shell that can run commands, take in batchfiles, uses I/O
redirection and has background execution capabilities.

references:
- Lab4b | https://ca216.computing.dcu.ie/labs/lab4b/
- https://www.youtube.com/watch?v=z4LEuxMGGs8&t=287s Simple shell in C
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>

// including header files
#include "./features/io_redirection.h"
#include "./features/batchfile.h"
#include "./commands/commands.h"

// declaring global variables
#define MAX_WORD_LENGTH 200

// declaring functions
void init_shell(char *filename);
void run_prompt(char path[]);
void read_command(char **param, int *paramLen);
int redirect_exist(char **param, int paramLen);

// declaring a global environmental variable
extern char **environ;

int main(int argc, char** argv)
{
    char *filename=NULL;

    // gets the batchfile name
    if (argc > 1) {
        filename = argv[1];
    }

    init_shell(filename);

    return 0;
}

void init_shell(char *filename)
{
    // declare variable that holds the directory of the external shell functions
    char *shellFunction = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    strcat(shellFunction, "/bin/");

    // gets the working directory path
    char *path = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    char *path_ptr = &path[0];
    getcwd(path_ptr, 100);

    // adding shell path to environmental variables
    char environ_path[255];
    strcat(environ_path, "shell=");
    strcat(environ_path, path);
    strcat(environ_path, "/keyline");
    putenv(environ_path);

    // gets the shell path
    char shell_path[255];
    strcat(shell_path, path);


    // checks and executes batchfile if exist
    if(filename != NULL) {
        get_param_batch(filename);
        return;
    }

    while (1) {

        char **param = (char **)malloc(150*sizeof(char));
        int paramLen = 0;
        // initiates the command prompt and read any arguements
        run_prompt(path);
        read_command(param, &paramLen);


        if(paramLen > 0) {
            if(strcmp(param[paramLen-1], "&") == 0){
                if(fork()!=0) {
                    wait(NULL);
                }
                else {
                    param[paramLen-1] = NULL;
                    strcat(shellFunction, param[0]);
                    execv(shellFunction, param);
                }
            }
            if(redirect_exist(param, paramLen) == 1) {
                redirect(param, paramLen);
            }
            else if(strcmp(param[0], "cd") == 0) { // cd command
                change_dir(param, paramLen, path_ptr);
            }
            else if(strcmp(param[0], "dir") == 0) {
                dir();
            }
            else if(strcmp(param[0], "clr") == 0) {
                system("clear");
            }
            else if(strcmp(param[0], "environ") == 0) {
                for (char **env = environ; *env!=0; env++) {
                    char *thisEnv = *env;
                    printf("%s\n", thisEnv);
                }
            }
            else if(strcmp(param[0], "echo") == 0) {
                echo(param, paramLen);
            }
            else if(strcmp(param[0], "help") == 0) {
                help(shell_path);
            }
            else if(strcmp(param[0], "pause") == 0) {
                char ch;
                printf("Press ENTER key to Continue\n");
                scanf("%c", &ch);
            }
            else if(strcmp(param[0], "quit") == 0) {
                break;
            }

            // free parameters and set paramLen to 0
            free(param);
        }
    }

    free(path);
    free(shellFunction);
}

void run_prompt(char path[])
{
    // reference: https://www.geeksforgeeks.org/static-variables-in-c/
    static int first_time = 1;

    // if its the first time the run_prompt is called then clear
    // system and print out prompt details else print the command line
    if(first_time) {
        system("clear");

        puts("Keysh Version 0.0.0.1");
        puts("Press ctrl+c or enter \"quit\" to terminate shell\n");
        first_time = 0;
    }

    printf("\033[32mshell-user:\033[22;34m%s\033[0m $ ", path);
}

void read_command(char **param, int *paramLen)
{
    // reference: https://www.geeksforgeeks.org/fgetc-fputc-c/
    // reference: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    char line[1024] = "";
    int count = 0, i = 0;
    char *array[100];
    char *tok;

    // gets user input and break it up into tokens
    while (1) {
        int c = fgetc(stdin);
        line[count++] = (char) c;
        if(c == '\n') break;
    }

    if (count==1) {
        return;
    }
    tok = strtok(line, " \n");

    // parses the command into words
    while (tok != NULL) {
        array[i++] = strdup(tok);
        tok = strtok(NULL, " \n");
    }
    *paramLen = i;

    // add words to parameters list
    for(int j=0; j<i; j++) {
        param[j] = array[j];
    }

    param[i] = NULL;
}

int redirect_exist(char **param, int paramLen) {
    for(int i=0; i<paramLen; i++) {
        if(strcmp(param[i], ">") == 0 || strcmp(param[i], "<") == 0 || strcmp(param[i], ">>") == 0)
            return 1;
    }
    return 0;
}

/* 
Name: The Ky Lien
SID: 19321566

Declaration of Plagiarism:
https://drive.google.com/file/d/1hf0x9vBHD8r-X1Ob_1fE1I_xAtjTYkZQ/view

*/