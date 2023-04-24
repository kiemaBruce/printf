#include "main.h"

/**
  * _printf - prints anything as specified by the format
  * @format: string that is used to specify what arguments are to be printed.
  * Return: the number of characters printed excluding the terminating null
  * byte in strings
  */
int _printf(const char *format, ...)
{
	int i, flen, x;
	va_list args;

	if (format == NULL)
	{
		return (0);
	}
	va_start(args, format);
	flen = getLength((char *)format);

	for (i = 0; i < flen; i++)
	{
		if (format[i] == '%')
		{
			/* Check if next is a valid format specifier */
			x = formatHandler(format[i + 1], args);
			if (x == 1)
			{
				_printf("Unknown conbersion type in format");
				return (1);
			}
			/*formatHandler(format[i + 1]);*/
			i++;
			continue;
		}
		_putchar(*(format + i));
	}
	return (0);
}
/**
  * formatHandler - prints out arguments according to their format specifiers
  * @c: character to be checked whether it is a format specifier
  * @args: the list of arguments to be printed
  * Description: if c is not a format specifier, the function returns 1 and
  * doesn't print anything. If it is a format specifier, the argument is
  * printed accordingly.
  * Return: 0 if the c is a format specifier, 1 if c is not a format specifier
  */
int formatHandler(char c, va_list args)
{
	int i, slen;
	char d;
	char *s;

	i = 0;

	switch (c)
	{
		case 'c':
			d = (char)(va_arg(args, int));
			_putchar(d);
			return (0);
		case 's':
			s = va_arg(args, char*);
			/**
			  * The official printf from the stdio.h throws a
			  * segmentation error if the string is NULL. This means
			  * I don't have to ensure that the string isn't NULL
			  */
			slen = getLength(s);
			for (i = 0; i < slen; i++)
			{
				_putchar(s[i]);
			}
			return (0);
		default:
			return (1);
	}
}
/**
  * getLength - determines the length of a string
  * @s: pointer to the string whose length is to be determined
  * Description: doesnt't count the terminating null byte
  * Return: the length as an int
  */
int getLength(char *s)
{
	int i;

	i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}
