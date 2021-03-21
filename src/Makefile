all: myshell

myshell: myshell.c
	-@gcc -o keysh myshell.c ./commands/commands.h ./features/batchfile.h ./features/io_redirection.h ./commands/dir.c ./commands/cd.c ./commands/echo.c ./commands/help.c ./features/redirection.c ./features/batch.c -g
