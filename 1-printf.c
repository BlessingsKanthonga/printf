#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - prints according to format
 * @format: char string
 * @...: variable inputs
 * Return: # of printed characers
 */

int _printf(const char *format, ...)
{
	int count = 0;
	char *s;
	char c;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(args, int);

				write(STDOUT_FILENO, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				*s = va_arg(args, char *);
				
				while (*s != '\0')
				{
					write(STDOUT_FILENO, s, 1);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				count++;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
