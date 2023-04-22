#ifndef MAIN_H
#define MAIN_H


/* 0_task headers */
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


/* 0_task prototypes */
int my_strlen(const char *str);
void my_putchar(const char c);
void print_string(const char *string);
void check_char(va_list myarg, int *count_char);
void check_string(va_list myarg, int *count_char);
void check_percent(int *count_char);
int _printf(const char *format, ...);



#endif