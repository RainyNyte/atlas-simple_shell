#include "simple_shell.h"

/**
 * check_path - function to check the user's input against the path to find if the command provided exists
 * @toks: pointer to the array of tokens from the users input
 *
 * Return: toks array or if failed to find the command in the path
 */

char *check_path(char *toks)
{
	char **path_toks = malloc(size_of(path_toks[0]));
	char *path = getenv("PATH");

	
}