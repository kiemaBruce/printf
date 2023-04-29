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
/**
  * binaryPrinter - converts an unsigned int into a binary number and prints it
  * @args: the number to be converted.
  * Return: the number of elements printed.
  */
int binaryPrinter(va_list args)
{
	unsigned int x;
	unsigned int r;
	binList *list = NULL;
	binList *temp;
	binList *new;
	int counter;

	x = va_arg(args, unsigned int);
	counter = 0;

	if (x == 0)
	{
		_putchar('0' + 0);
		return (1);
	}
	while (x > 0)
	{
		if (counter == 0)
		{
			list = malloc(sizeof(binList));
			r = x % 2;
			x = x / 2;
			list->next = NULL;
			list->value = r;
			counter++;
			continue;
		}
		new = malloc(sizeof(binList));
		r = x % 2;
		x = x / 2;
		temp = list;
		list = new;
		new->next = temp;
		new->value = r;
	}
	print_list(list);
	free_list(list);
	return (count_elements(list));
}
/**
  * print_list - prints a binList linked list
  * @head: head of the linked list
  */
void print_list(binList *head)
{
	int x;

	while (head != NULL)
	{
		x = head->value;
		_putchar('0' + x);
		head = head->next;
	}
}
/**
  * free_list - frees a binList linked list
  * @head: the head of the linked list
  */
void free_list(binList *head)
{
	binList *temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
  * count_elements - counts the number of nodes in a binList linked list
  * @head: head of the linked list
  * Return: the number of nodes.
  */
int count_elements(binList *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}
