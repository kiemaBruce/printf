#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
int _printf(const char *format, ...);
/*int formatHandler(char * format);*/
int formatHandler(char c, va_list args);
int getLength(char *s);
int _putchar(char c);
void print_number(int n);
int det_digits(int x);
int raise(int x, int y);
int intPrinter(va_list args);
void print_string(int slen, char *s);

#endif /* MAIN_H */
