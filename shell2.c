#include "main.h"

/**
 * main - Execute the simple shell program
 * @argc: Number of arguments passed into the program in the terminal
 * @argv: Array of the arguments passed into the program
 * @envp: Array of environment variables passed into the program
 *
 * Return: Always 0 (Successful exit)
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv,
		char **envp)
{
	int my_argc = 0;
	char **my_argv;
	char *command = NULL; /* The command fed to the shell */
	size_t n = 0; /* Size, in bytes, of the 'command' buffer */
	char *path;
	pid_t pid;
	char *full_path = NULL;
	size_t m = 0;
	int flag = 0;
	int wstatus;
	int interact = isatty(STDIN_FILENO);

	while (1)
	{
		if (interact)
			print("($) ");
		if (_getline(&command, &n, STDIN_FILENO) == -1)
			perror("getline");
		tokenize_args(&command, &my_argv, &my_argc);
		path = _getenv("PATH"); /* Extract the PATH directories */
		flag = get_program(&path, &full_path, &m, &my_argv[0]); /* Get program */
		if (check_builtin(&my_argv, &full_path))
			continue;
		if (flag)
			pid = fork();
		else
			perror("not found");
		if (pid == 0)
		{
			if (execve(full_path, my_argv, envp) == -1)
			{
				perror("execve");
				return (-1);
			}
		}
		else
		{
			wait(&wstatus);
		}
		free_arr(my_argv);
		free(full_path);
		if (!interact)
			break;
	}
	free_arr(envp);
	return (0);
}

/**
 * check_builtin - Execute the builtin() function
 * @argv: Pointer to the argv array
 * @full_path: Pointer to the full_path variable
 *
 * Return: 1 on success, otherwise 0
 */
int check_builtin(char ***argv, char **full_path)
{
	if (*argv == NULL || argv == NULL)
		return (0);
	if (builtins(*argv))
	{
		free_arr(*argv);
		if (*full_path)
			free(*full_path);
		return (1);
	}
	return (0);
}

/**
 * get_program - Evaluates if an executable function for the given
 * shell command exists
 * @path: String holding the value of the PATH environment variable
 * @full_path: Pointer to hold the address of the constructed path
 * to the executable file for the command
 * @m: Pointer to the size of the full_path buffer
 * @command: Pointer to the shell command
 *
 * Return: 1 on success, otherwise 0 on failure
 */
int get_program(char **path, char **full_path, size_t *m, char **command)
{
	char *path_token;
	const char *delim = ":";
	struct stat st;

	if (*path == NULL || path == NULL || *command == NULL || command == NULL)
		return (0);
	*full_path = NULL;
	path_token = _strtok(*path, delim);
	while (path_token)
	{
		if (get_full_path(full_path, m, *command, path_token) == 0)
		{
			if (stat(*full_path, &st) == 0)
				return (1);
		}
		path_token = _strtok(NULL, delim);
	}
	return (0);
}

/**
 * tokenize_args - Extract tokens from the command that has been passed to
 * the shell
 * @command: The command string, to be tokenized
 * @argv: Pointer to the array to be populated with addresses
 * of the tokens
 * @argc: The number of tokens in the command
 *
 * Return: Nothing
 * Description: At the time of this function invocation, argc will always
 * have a value of 0
 * argv is an array of pointers that has been created in the calling function
 */
void tokenize_args(char **command, char ***argv, int *argc)
{
	char *token;
	const char *delim = " \n";

	if (command == NULL || *command == NULL || argv == NULL)
		return;
	/* Count the number of tokens */
	token = _strtok(*command, delim);
	while (token)
	{
		(*argc)++;
		token = _strtok(NULL, delim);
	}
	*argv = (char **)malloc(sizeof(char *) * (*argc + 1));
	if (*argv == NULL) /* In case malloc fails */
		return;
	*argc = 0;
	/* Extract the tokens */
	token = _strtok(*command, delim);
	while (token)
	{
		(*argv)[(*argc)++] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	(*argv)[*argc] = NULL;
}

/**
 * free_arr - Frees any memory that is occupied
 * @arr: Pointer to an array of arrays
 *
 * Return: 0 on success, 1 on failure
 */
int free_arr(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return (1);
	while (*(arr + i))
	{
		free(*(arr + i));
		i++;
	}
	if (arr)
		free(arr);
	return (0);
}
