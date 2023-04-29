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
		return (-1);
	r = 0;
	va_start(args, format);
	flen = getLength((char *)format);

	for (i = 0; i < flen; i++)
	{
		if (format[i] == '%')
		{
			x = formatHandler(format[i + 1], args);
			/* Format consists of % only */
			if (i == 0 && (flen == 1))
				return (-1);
			/*Format consists of % only, or there's a trailing %*/
			if (x == -1)
				return (-1);
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
	va_end(args);
	return (r);
}
/**
 * formatHandler - prints out arguments according to their format specifiers
 * @c: character to be checked whether it is a format specifier
 * @args: the list of arguments to be printed
 * Description: if c is not a format specifier, the function returns 1 and
 * doesn't print anything. If it is a format specifier, the argument is
 * printed accordingly.
 * Return: 0 if the string is NULL, -1 if the c is a NULL byte -2
 * if c is a '%' -3 if c is neither a valid format specifier not the previously
 * mentioned cases. Otherwise, it returns the length of the integer, char or
 * string that is printed
 */
int formatHandler(char c, va_list args)
{
	int slen, r1;
	char d;
	char *s;

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
			if (s == NULL)
			{
				print_string(6, "(null)");
				return (0);
			}
			slen = getLength(s);
			print_string(slen, s);
			return (slen);
		case 'd':
			return (intPrinter(args));
		case 'i':
			return (intPrinter(args));
		case 'b':
			return (binaryPrinter(args));
		case '%':
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
