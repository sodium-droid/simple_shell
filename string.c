#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *_strlen - function that
 *outputs the lenght of a string
 *@s: required string
 *Return: 0 (lenght of string)
 */

int _strlen(char *s)
{
int i, j = 0;

if(!s)
	return (0);
for (i = 0; s[i] != '\0'; i++)
	j++;
return (j);
}

/**
 *_puts - prints a string
 *and a new line.
 *@str: string to print
 */

void _puts(char *str)
{
int i;

if (!str)
	return;
for (i = 0; str[i] != '\0'; i++)
	_putchar(str[i]);
}

/**
 *_strcpy - A function that
 *copies the string pointed to by
 *src to dest.
 *@src: pointer
 *@dest: destination
 *Return: dest.
 */

char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
	dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}

/**
 *_strcspn - returns the number of bytes in *str 
 *before the first occurence of the first character in both pointers
 *@str: target string
 *@check: argument string
 *Return: confirmed number of bytes in str.
 */

int _strcspn(const char *str, const char *check)
{
const char *temp;
int i = 0;

while (*str)
{
	temp = check;
	while (*temp)
		{
			if (*str == *temp)
				return (i);
			temp++;
		}
	i++;
	str++;
}
return (i);
}
