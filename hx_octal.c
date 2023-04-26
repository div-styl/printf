#include "main.h"
/**
 * handle_hex - converts a number to hex
 * @num: number to be converted
 * @base:	base of the number
 * @buffer: buffer to store the result
 * Return: void
*/
void handle_hex(unsigned int num, char base, char *buffer)
{
	const char hx_low[] = "0123456789abcdef";
	const char hx_upp[] = "0123456789ABCDEF";
	const char *hx_dg = (base == 'x') ? hx_low : hx_upp;
	int index = 0, rmd;

	while (num != 0)
	{
		rmd = num % 16;
		buffer[index++] = hx_dg[rmd];
		num /= 16;
	}

	buffer[index] = '\0';
}
/**
 * handle_octal - converts a number to octal
 * @num: number to be converted
 * @buffer: buffer to store the result
 * Return: void
*/
void handle_octal(unsigned int num, char *buffer)
{
	int index = 0, rmd;

	while (num != 0)
	{
		rmd = num % 8;
		buffer[index++] = rmd + '0';
		num /= 8;
	}

	buffer[index] = '\0';
}

/**
 * handle_decimal - converts a number to decimal
 * @num: number to be converted
 * @buffer: buffer to store the result
 * Return: void
*/
void handle_decimal(unsigned int num, char *buffer)
{
	int index = 0, rmd;

	while (num != 0)
	{
		rmd = num % 10;
		buffer[index++] = rmd + '0';
		num /= 10;
	}

	buffer[index] = '\0';
}
/**
 * handle_point - print the address of a pointer
 * @p: the pointer that should print the address
 * Return: addresse
*/
int handle_point(void *p)
{
	int compare = 0, i = 0;
	unsigned long int number = (unsigned long int)p;
	char *hex_digt = "0123456789abcdef";
	int hx_digt_len = 16;
	int max[100];

	if (p == NULL)
	{
		compare += write(1, "(nil)", 5);
		return (compare);
	}
	write(1, "0x", 2);
	if (number == 0)
	{
		write(1, "0", 1);
		compare++;
	}
	else
	{
		while (number != 0)
		{
			max[i] = number % hx_digt_len;
			number /= hx_digt_len;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			my_putchar(hex_digt[max[i]]);
			compare++;
		}
	}
	return (compare + 2);
}
/**
 * number_to_hx_to_octal -	converts a number to hex or octal
 * @num: number to be converted
 * @base: base of the number
 * Return: number of digits printed
*/
int number_to_hx_to_octal(unsigned int num, char base)
{
	char buffer[MAX_BUFFER_SIZE];
	int i;

	if (num == 0)
	{
		my_putchar('0');
		return (1);
	}
	if (base == 'x' || base == 'X')
		handle_hex(num, base, buffer);
	else if (base == 'o')
		handle_octal(num, buffer);
	else if (base == 'u')
		handle_decimal(num, buffer);
	else
	{
		return (0);
	}
	for (i = _strlen(buffer) - 1; i >= 0; i--)
	{
		my_putchar(buffer[i]);
	}
	return (_strlen(buffer));
}
