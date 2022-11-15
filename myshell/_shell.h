#ifndef "SHELL_H"
#define "SHELL_H"

/* builtin header files */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fnctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* function prototypes */
char **tokstr(char *str, int type);
char *find_path(char **env);
void add_path(char **cmd, char env, int *sts);
void check_builtin(char **tk, char **env__attribute__((unused)), int *sts);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif /* SHELL_H */
