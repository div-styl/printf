
#include "main.h"



/**
 * main - ..
 *
 * @void: ..
 *
 * Return: ..
 */

#include "main.h"

int main(void)
{

	int len = 0;
	int len2 = 0;

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");


	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");


	printf("Len:[%d]\n", len);
	printf("Len2:[%d]\n", len2);

	_printf("Percent:/%\n");

	return (0);
}
