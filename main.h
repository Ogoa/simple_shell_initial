#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void *_realloc(void *ptr, size_t old_size, size_t new_size);
void _memcpy(char *dest, const char *src, size_t nmemb);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, char c);
char *_strdup(const char *str);

#endif /* ifndef MAIN_H */
