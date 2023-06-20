#include "main.h"

/**
 *_getline - is the implementation of the POSIX getline function
 *used for reading user input and can adjust allocation and reallocation
 *when buffer being read to grows beyond the given num_byte read
 *@lineptr: is the pointer to the beginning of array of strings which
 *give access to reading of other string in that array
 *@n: is the num_byte which is given to read
 *@stream: Is the file stream pointer being read from
 *Return: The number of byte read
 */
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_chars = 0;
	size_t total_chars = 0;
	char *buff = NULL, *new_buff = NULL;

	do
	{
		buff = (char *)realloc(buff, (*n + BUFSIZ) * sizeof(char));
		if (buff == NULL)
		{
			perror("realloc");
			free(buff);
			return (-1);
		}

		new_buff = fgets(&buff[total_chars], BUFSIZ, stream);
		if (new_buff == NULL)
		{
			free(buff);
			if (total_chars == 0)
				return (-1);
			else
				break;
		}

		read_chars = strlen(&buff[total_chars]);
		total_chars += read_chars;

	} while (buff[total_chars - 1] != '\n' && read_chars == BUFSIZ - 1);

	*lineptr = buff;
	*n = total_chars;

	return (*n);
}
