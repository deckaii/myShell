#ifndef COMMANDS_H
#define COMMANDS_H

// function prototypes
void change_dir(char **param, int paramLen, char *path);
void dir();
void echo(char **param, int paramLen);
void help(char *path);

#endif