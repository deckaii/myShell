#ifndef COMMANDS
#define COMMANDS

// function prototypes
void change_dir(char **param, int paramLen, char *path);
void dir();
void echo(char **param, int paramLen);

// batchfile
void get_param_batch(char *filename);
int cfileexists(char * filename);

#endif