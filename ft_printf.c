#include "ft_printf.h"

int        ft_find_c(char *str)
{
	char *s;
	int i;
	int j;

	i = 0;
	s = "dDiIsScCu%UxXpPgGeEn";
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

int			ft_parse_all(const char **format, va_list *list)
{
	int i;
	int n;
	int result;
	info *rez;
	char *s;

	s = (char *)*format;

	i = 0;
	result = 0;
	if (!(rez = (info *)malloc(sizeof(info))))
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			n = ft_find_c(s + i + 1);
			*rez = ft_parse_form(ft_strndup(s + i + 1, n + 1), *list, *rez, &result);
			i += n + 1;
		}
		else
		{
			ft_putchar(s[i]);
			result++;
		}
		i++;
	}
	free (rez);
	return (result);
}

int    ft_printf(const char *format, ...)
{
	int i;
	va_list list;

	va_start(list, format);
	i = ft_parse_all(&format, &list);
	va_end(list);
	return (i);
}
