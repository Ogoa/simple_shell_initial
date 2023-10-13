#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;

void *_realloc(void *ptr, size_t old_size, size_t new_size);
void _memcpy(char *dest, const char *src, size_t nmemb);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, char c);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_getenv(const char *name);
int get_full_path(char **full_path, size_t *n, const char *file,
		const char *path_dir);
int _putchar(char c);
int print(const char *str);
int _fgetc(int fd);
int free_arr(char **arr);
void tokenize_args(char **command, char ***argv, int *argc);
int get_program(char **path, char **full_path, size_t *m, char **command);
int builtins(char **argv);
int check_builtin(char ***argv, char **full_path);

#endif /* ifndef MAIN_H */
