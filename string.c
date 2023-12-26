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

/**
 *_strncat - A function that concats
 *two strings based on size of n
 *@dest: string destination
 *@src: string source
 *@n: required bytes (number)
 *Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
int i, destlen = _strlen(dest);

for (i = 0; i < n && *src != '\0'; i++)
{
dest[destlen + i] = *src;
src++;
}
dest[destlen + i] = '\0';
return (dest);
}

/**
 *_strcat - A funtion that
 *concats 2 strings
 *@dest: string 1
 *@src: string 2
 *Return: dest.
 */

char *_strcat(char *dest, char *src)
{
int i, lena = _strlen(src), lenb = _strlen(dest);

for (i = 0; i <= lena; i++)
	dest[lenb + i] = src[i];
return (dest);
}

