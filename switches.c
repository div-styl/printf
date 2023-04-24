#include "main.h"
/*by div-styl and adilma53*/

/**
 * my_putchar -write a single character to standard output.
 * @c: the character to be written.
 * Return: the string/ character
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * handle_char - handles a single character conversion specifier
 *
 * @c: the conversion specifier character
 * @args: the va_list of arguments
 * @count: a pointer to the running count of printed characters
 */
void handle_char(char c, va_list args, int *count)
{
	if (c == 'c')
	{
		char ch = va_arg(args, int);

		write(1, &ch, 1);
		(*count)++;
	}
	else if (c == 's')
	{
		char *s = va_arg(args, char *);

		if (s == NULL)
			s = "(null)";

		write(1, s, strlen(s));
		(*count) += strlen(s);
	}
	else if (c == 'd' || c == 'i')
	{
		int num = va_arg(args, int);
		(*count) += int_to_str(num);
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*count) += 2;
	}
}
