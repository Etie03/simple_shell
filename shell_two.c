#include "shell.h"

/**
 * _strlen - a function that returns length of string
 * @stg: string
 *
 * Return: length of string
 */
int _strlen(char *stg)
{
	int m = 0;

	while (stg[m] != '\0')
	{
		m++;
	}
	return (m);
}

/**
 * _strcpy - copies the string pointed by src to dest
 *@dest: first value to check
 *@src: Second value to check
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{

	char *g = src;
	int m = 0;

	while (*g != '\0')
	{
		dest[m] = src[m];
		g++;
		m++;
	}
	dest[m] = src[m];
	return (dest);
}

/**
 * _strncmp - a function that compares n chars of two strings
 * @s1: first value
 * @s2: second value
 * @n: number of chars to compare
 *
 * Return: 0 if equal, else other
 */
int _strncmp(char *s1, char *s2, int n)
{
	int m = 0, g = 0, l, f = 0;

	while (s1[m] != 0)
	{
		m++;
	}
	while (s2[g] != 0)
	{
		g++;
	}
	for (l = 0; l < n; l++)
	{
		if (s1[l] != s2[l])
		{
			f = (s1[l] - '0') - (s2[l] - '0');
			break;
		}
	}
	return (f);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: first
 *@src: second value
 *
 * Return: concanated char
 */
char *_strcat(char *dest, char *src)
{
	int m = 0, g = 0, h;

	while (dest[m] != 0)
	{
		m++;
	}
	while (src[g] != 0)
	{
		g++;
	}
	for (h = 0; h < g; h++)
	{
		dest[m] = src[h];
		m++;
	}
	dest[m] = '\0';
	return (dest);
}

/**
 * _realloc_mem - a function that reallocs a memory block
 * @ptr: first value
 * @old_size: second value
 * @new_size: third value
 *
 * Return: the pointer
 */

void *_realloc_mem(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pnt;
	unsigned int m, low = 0;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 &&  ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
		low = new_size;
	else
		low = old_size;
	pnt = malloc(new_size);
	if (pnt == NULL)
		return (NULL);
	for (m = 0; m < low; m++)
	{

		pnt[m] = ((char *) ptr)[m];
	}
	free(ptr);
	return (pnt);
}
