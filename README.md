This repository contains files for the group project `0x16. C - Simple shell`<br>
In this project, we implement a simple shell that functions in a similar way to the bash shell. It takes in commands, interpretes them, gives the results and repeats this cycle.<br>
The directory contains several C source files and one header file.





`main.h`<br>
This header file contains all the function prototypes of functions used across all the source files in this directory.





`getline.c`<br>
This source file contains a custom implementation of the `getline` function provided in the C standard library.<br>
`_getline` reads an entire line of text from an input stream. On success, it returns the number of characters read, otherwise it returns `-1` on failure or upon encountering the `EOF`.<br>
The function prototype is:
```
ssize_t _getline(const char **lineptr, size_t *n, FILE *stream);
```
The function assigns the address of the buffer createdto hold the line that has been read to`lineptr`. `n` indicates the size of the buffer currently pointed to by `lineptr` at the time of the function call. `stream` is a pointer to a stream of the `FILE` structure. This can either be the `stdin` or a text file.





`strtok.c`<br>
This source file contains a custom implementation of the `strtok` function provided in the C standard library.<br>
`_strtok` extracts tokens from a given string (where the tokens are parts of the string that appear in between the specified delimiters). On success, it returns the address of the token otherwise it returns a `NULL` pointer.<br>
The function prototype is:
```
char *_strtok(const char *str, const char *delim);
```
On the first call of `_strtok`, `str` must be a valid pointer (non-null) while on subsequent calls of the function, it should be `NULL`.<br>
`delim` is a string specifying the individual bytes that are delimiters in the initial string passed into the function. `_strtok` maintains an internal state of `str` that was passed into the function at the first call.





`realloc.c`<br>
This source file contains a custom implemetation of the `realloc` function provided in the C standard library.<br>
`_realloc` resizes a given memory block and copies over any existing data from the existing memory block into the new one. On success, it returns the address of the new memory block otherwise on failure `NULL` is returned.<br>
The function prototype is:
```
void *_realloc(void *ptr, size_t old_size, size_t new_size);
```
`ptr` is a pointer to the memory block that is to be resized. `old_size` is the number of bytes `ptr` currently occupies at the time of the function call while `new_size` is the number of bytes you want to resize it to.<br>
If `ptr` is null or `new_size` is `0`, `_realloc` will be equivalent to `malloc`.<br>
If `new_size` is `0`, `_realloc` will be equivalent to `free`.





`memcpy.c`<br>
This source file contains a custom implementation of the `memcpy` function provided int the C standard library.<br>
`_memcpy` copies each byte from on memory block to another memory block.<br>
The function prototype is:
```
void _memcpy(char *dest, const char *src);
```
`dest` is a pointer to the memory block where eacah byte contained in `src` is to be copied to.





`strchr.c`<br>
This source file contains a custom implementation of the `strchr` function provided in the C standard library.<br>
`_strchr` finds the occurrence of a character in a given string. On success, it returns the address of the character in the string, otherwise it returns `NULL` if no match has been found.
The function prototype is:
```
char *_strchr(const char *str, char c);
```
`str` is the string that is being parsed in search of an occurrence of the character `c`.





`strdup.c`
This source file contains a custom implementation of the `strdup` function provided in the C standard library.<br>
`_strdup` creates a duplicate of a string by copying it to a new memory block. On success, the function returns the address to the duplicated string, otherwise `NULL` is returned.<br>
The function prototype is:
```
char *_strdup(const char *str);
```

`str` is the string that is to be duplicated.  



`_putchar.c`<br>
This source file contains the implementation of the `putchar` function provided in the C standard library.<br>  
`_putchar` writes an individual character to the standard output on success.<br>
The function prototype is:
```
int _putchar(char c);
```
`c` is the character literal to be printed.  

`builtin.c`<br>
This source file contains the implementation of the `builtins` function, which handles the implementation of shell built-in functions.<br>
`builtins` handles the implementation of shell built-in functions

Function Prototype:
```
int builtins(char **argv);
```
`**argv` is the pointer to the array of argument strings

`fgetc.c`<br>
This source file contains the implementation of the `_fgetc` function, which reads a character from a file.<br>
`_fgetc` Read a character from a fileThe function returns the character read as an integer. It returns EOF (End of File) if no character has been read, or if there was an error in reading.<br>

Function Prototype:
```
int _fgetc(int fd);
```
`fd` is the file descriptor

`get_path.c`<br>
This source file contains the implementation of the `get_full_path` function, which creates the absolute path for a file based on the given file name and PATH directory.<br>

Function Prototype:
```
int get_full_path(char **full_path, size_t *n, const char *file, const char *path_dir);
```
`full_path` is the buffer to store address of the string with the full directory path <br>
`n`is the size of the buffer in bytes<br>
`file` is the name of the file<br>
`path_dir` is the PATH directory<br>




`getenv.c`
This source file contains a custom implementation of the `getenv` function provided in the C standard library.<br>
`_getenv` finds the specified variable among the set environment variables and returns it in the `name=value` format.<br>
The function prototype is:
```
char *_getenv(const char *name);
```
`str` is the NAME of the environment variable you want to find.
