#ifndef IO_REDIRECTION_H
#define IO_REDIRECTION_H

// I/O redirection
void redirect(char **param, int paramLen);
void exec_command(char *inp, char *out, char **array, int flag);

#endif