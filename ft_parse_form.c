#include "ft_printf.h"

int        ft_intlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

char    *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

info    ft_clear(info rez, char *format_mini)
{
	rez.nol = 0;
	rez.resh = 0;
	rez.minus = 0;
	rez.plus = 0;
	rez.width = 0;
	rez.spec = format_mini[ft_strlen(format_mini) - 1];
	rez.space = 0;
	rez.accuracy = 0;
	return (rez);
}

void    ft_getting_flags(char *str, info rez, int i, va_list list)
{
	if (str[i] =='-')
		rez.minus = 1;
	else if (str[i] == '+')
		rez.plus = 1;
	else if (str[i] == '#')
		rez.resh = 1;
	else if (str[i] == '0')
		rez.nol = 1;
	else if (str[i] == ' ')
		rez.space = 1;
	else if (str[i] == '.')
	{
		if (str[i + 1] == '*')
			rez.accuracy = va_arg(list, int);
		else
		{
			rez.accuracy = ft_atoi(str + i + 1);
			i += ft_intlen(rez.accuracy);
		}
	}
	else if (str[i] >= '1' && str[i] <= '9')
	{
		if (str[i + 1] == '*')
			rez.width = va_arg(list, int);
		else
		{
			rez.width = atoi(str + i);
			i += ft_intlen(rez.width) - 1;
		}
	}
}

info    ft_parse_form(char *str, va_list list)
{
	info rez;
	int i;
	int end;
	char *new;

	i = 0;
	rez = ft_clear(rez, str);
	end = ft_strlen(str);
	while(i <= end)
	{
		ft_getting_flags(str, rez, i, list);
		i++;
	}
	return (rez);
}
