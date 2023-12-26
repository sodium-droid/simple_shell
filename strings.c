#include "main.h"

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
int i, dest_len = _strlen(dest);

for (i = 0; i < n && *src != '\0'; i++)
{
dest[dest_len + i] = *src;
src++;
}
dest[dest_len + i] = '\0';
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

/**
 *_strcmp - compares two strings
 *@str1: first string
 *@str2: second string
 *Return: 0 or 1 or -1
 */

int _strcmp(char *str1, char *str2)
{
int value = 0;

while (*str1 && *str2 && *str1 == *str2)
{
	str1++;
	str2++;
}
if (*str1 == '\0' && *str2 == '\0')
	return (value);
else
	value = (*str1 > *str2) ? 1 : -1;
return (value);
}
