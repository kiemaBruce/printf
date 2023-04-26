#include "main.h"

/**
  * _printf - prints anything as specified by the format
  * @format: string that is used to specify what arguments are to be printed.
  * Return: the number of characters printed excluding the terminating null
  * byte in strings
  */
int _printf(const char *format, ...)
{
	int i, flen, x, r;
	va_list args;

	if (format == NULL)
		return (0);
	r = 0;
	va_start(args, format);
	flen = getLength((char *)format);

	for (i = 0; i < flen; i++)
	{
		if (format[i] == '%')
		{
			x = formatHandler(format[i + 1], args);
			if (i == 0 && (flen == 1))
				return (0);
			/*Format consists of % only, or there's a trailing %*/
			if (x == -1 && (format[i - 1] == '%'))
			{
				return (0);
			}
			/**
			  * valid format specifier, hence after printing it we
			  * increment and move to the next character
			  */
			if (x >= 0 && x != -3)
			{
				r = r + x;
				i++;
				continue;
			}
			if (x == -2)
			{
				i++;
			}
		}
		_putchar(*(format + i));
		r++;
	}
	return (r);
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
	int i, slen, r1;
	char d;
	char *s;

	i = 0;
	r1 = 0;

	switch (c)
	{
		case 'c':
			d = (char)(va_arg(args, int));
			_putchar(d);
			r1++;
			return (r1);
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
			_putchar('\0');
			return (slen);
		case '%':
			/*_putchar('%');*/
			return (-2);
		case '\0':
			return (-1);
		default:
			return (-3);
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
