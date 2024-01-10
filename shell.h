#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv, char **envp);
void print_hello_world(void);
int _strlen(char *stg);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
void *_realloc_mem(void *ptr, unsigned int old_size, unsigned int new_size);
void sign_handlr(int sign);
char *find_path(char **envp);
int _strcmp(char *s1, char *s2);
void find_env(char **envp);
void free_func(char **double_pointer);
int string_words(char *str);
char **string_extract(char *str, char *delim);
void func_test(char *buffer, char **envp);
int _atoi(char *stg);
int func_exit(char **array_words, char *buffer);
int parac(char **arry, char **envp);
int path_check(char **array_words, char *e_path);

#endif
