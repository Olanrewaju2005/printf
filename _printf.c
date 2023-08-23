#include "main.h"
/**
  *_print - function to print an input to standard output
  *@format: input passed to function
  *@...: variadic input
  *Return: number of chracters printed
  */
int _printf(const char *format, ...)
{
	int char_print = 0;

	va_list printlist;
	va_start(printlist, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(printlist, int);

				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(printlist, char *);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				char_print += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(printlist, int);
				int count = 0;

				while (num != 0)
				{
					num /= 10;
					count++;
				}

				write(1, &n, count);
				char_print += count;
			}
			else
			{
				write(1, format, 1);
				char_print++;
			}
		}
		format++;
	}
	va_end(printlist);
	return (char_print);
}
