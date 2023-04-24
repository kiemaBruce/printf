#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
int _printf(const char *format, ...);
/*int formatHandler(char * format);*/
int formatHandler(char c, va_list args);
int getLength(char *s);
int _putchar(char c);

#endif /* MAIN_H */
