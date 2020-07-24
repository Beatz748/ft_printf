#include "ft_printf.h"

int        ft_find_c(char *str)
{
	char *s;
	int res;
	int i;
	int j;

	i = 0;
	s = "dDiIsScCuUxXpPgGeEn";
	while (str[i] != '\0')
	{
		j = 0;
		while (s[j] != '\0')
		{
			if (str[i] == s[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void    ft_parse_all(char *format, va_list list)
{
	int i;
	int j;
	int n;
	info rez;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			n = ft_find_c(format + i + 1);
			rez = ft_parse_form(ft_strndup(format + i + 1, n + 1), list, rez);
			i += n + 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
}

int    ft_printf(char *format, ...)
{
	va_list list;

	va_start(list, format);
	ft_parse_all(format, list);
	va_end(list);
	return (1);
}
