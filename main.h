#ifndef MAIN_H
#define MAIN_H

/**
  * struct binaryList - singly linked list
  * @value: binary value
  * @next: points to the next node
  * Description: this singly linked list is used to store the binary digits of
  * a decimal value in individual nodes. The entire list will then contain the
  * binary equivalent of a decimal value.
  */
struct binaryList
{
	int value;
	struct binaryList *next;
};
/**
  * binList - typedef for struct binaryList
  */
typedef struct binaryList binList;

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

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
int binaryPrinter(va_list args);
void print_list(binList *head);
void free_list(binList *head);
int count_elements(binList *head);

#endif /* MAIN_H */
