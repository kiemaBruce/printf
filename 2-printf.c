#include "main.h"

/**
  * print_string - prints a string
  * @slen: the length of the string, sans the terminating null byte
  * @s: pointer to the string
  * Description: the function doesn't check for null pointers.
  */
void print_string(int slen, char *s)
{
	int i;

	i = 0;

	for (i = 0; i < slen; i++)
	{
		_putchar(s[i]);
	}
}
