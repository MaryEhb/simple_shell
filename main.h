#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

int check_path(char *command);
char *_getenv(char **env, char *command);
char *get_path(char **envp, char *command);
int command_exists(char *command);
void _printenv(char **envp);
void exec_command(char *line, char *progname, char **envp);

#endif