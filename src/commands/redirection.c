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
            free(array);
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
    char **array = (char **)malloc(MAX_WORD_LENGTH*sizeof(char));
    int index=0;
    int flag;

    // checks for the correct use of the redirection
    if(strcmp(param[0], ">") == 0 || strcmp(param[0], ">") == 0) {
        printf("Incorrect usage!\n");
    } else {
        for (int i=1; i<paramLen-1; i++) {
            printf("%d\n", i);
            printf("%s\n", param[i-1]);
            if(strcmp(param[i], "<") == 0) { // input redirection
                flag = 1;
                inp = param[i+1];

                for(int j=0; j<paramLen; j++) {
                    if(j != i) {
                        array[index] = param[j];
                    }
                    index++;
                }
                
            } else if(strcmp(param[i], ">") == 0) { // output redirection
                flag = 2;
                out = param[i+1];
                
                for(int j=0; j<paramLen; j++) {
                    if(j != i) {
                        array[index] = param[j];
                    }
                    index++;
                }

            } else if(strcmp(param[i], ">>") == 0) { // new file redirect
                flag = 3;
                out = param[i+1];
                
                for(int j=0; j<paramLen; j++) {
                    if(!(j == i)) {
                        array[index] = param[j];
                    }
                }
            }
        }
    }
    exec_command(inp, out, array, flag);
}