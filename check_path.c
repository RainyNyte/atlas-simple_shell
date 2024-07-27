#include "simple_shell.h"

/**
 * check_path - function to check the user's input against the path to find if the command provided exists
 * @toks: pointer to the array of tokens from the users input
 *
 * Return: 0 on success or 1 on fail
 */

int check_path(char *command)
{
	char *path = getenv("PATH");
	char *drifter;
	char *p;
	char **path_toks;
	size_t len = strlen(path);
	size_t max_toks = 1;
	int i = 0;
	int j = 0;
	int l = 0;

	for (p = path; *p; p++)
	{
		if (*p == ':')
		{
			max_toks++;
		}
	}
	path_toks = malloc((max_toks + 1) * sizeof(char *));
	if (path_toks == NULL)
	{
		return (1);
	}
	drifter = strtok(path, ":");
	while (drifter != NULL)
	{
		path_toks[i++] = drifter;
		drifter = strtok(NULL, ":");
	}
	path_toks[i] = NULL;

	while (path_toks[l] != NULL)
	{
		if (command == path_toks[l])
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	free(path_toks);

	return (1);
}