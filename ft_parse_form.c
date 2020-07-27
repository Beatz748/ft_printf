#include "ft_printf.h"

int				ft_uintlen(unsigned int n)
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

int				ft_intlen(long long n)
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

char			*ft_strchr(const char *s, int c)
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

info			ft_clear(info rez, char *format_mini)
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

info			ft_checking(char *str, info rez, char *main)
{
	size_t i;

	i = 0;
	if (!(str = ft_strchr(str, '.')))
		rez.accuracy = ft_strlen(main);
	if (rez.accuracy < 0)
	{
		rez.accuracy = ft_strlen(main);
		rez.minus = 1;
	}
	return (rez);
}
info			ft_getting_flags(char *str, info rez, int *i, va_list list)
{
	if (str[*i] =='-')
		rez.minus = 1;
	if (str[*i] == '+')
		rez.plus = 1;
	if (str[*i] == '#')
		rez.resh = 1;
	if (str[*i] == '0')
		rez.nol = 1;
	if (str[*i] == ' ')
		rez.space = 1;
	if (str[*i] == '.')
	{
		if (str[*i + 1] == '*')
		{
				rez.accuracy = va_arg(list, int);
			return (rez);
		}
		else
		{
			rez.accuracy = ft_atoi(str + *i + 1);
			*i += ft_intlen(rez.accuracy) + 1;
			if (*i-- == '0')
				*i += 1;
		}
	}
	if ((str[*i] >= '1' && str[*i] <= '9' )|| str[*i] == '*')
	{
		if (str[*i] == '*' && str[*i - 1] != '.')
		{
			rez.width = va_arg(list, int);
			return (rez);
		}
		else if (str[*i] >= '1' && str[*i] <= '9' )
		{
			(rez.width) = atoi(str + *i);
			*i += ft_intlen(rez.width) - 1;
		}
	}
	return (rez);
}



int			ft_print_c(info rez, int c)
{
	int i;

	i = 0;

	if (rez.width > 1 && !rez.minus)
	{
		while (i++ < rez.width - 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	else if (rez.width > 1 && rez.minus)
	{
		ft_putchar(c);
		while (i++ < rez.width -1)
			ft_putchar(' ');
	}
	else 
		ft_putchar(c);
	return (i + 1);
}

void			ft_flags_chek_int(info *rez, int j, char *str)
{
	if (!(ft_strchr(str, '.')))
	{
		if (j >= 0)
			rez->accuracy = ft_intlen(j);
		else
			rez->accuracy = ft_intlen(j) - 1;
	}	
	if (rez->plus)
		rez->space = 0;
	if (rez->minus)
		rez->nol = 0;
}

void			ft_flags_chek_uint(info *rez, unsigned int j, char *str)
{
	if (!(ft_strchr(str, '.')) || rez->accuracy < 0)
		rez->accuracy = ft_uintlen(j);
	if (rez->plus)
		rez->space = 0;
	if (rez->minus)
		rez->nol = 0;
}

int			ft_print_str(info rez, char *str, char *for_check)
{
	int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	rez = ft_checking(for_check, rez, str);
	if (rez.accuracy < (int)ft_strlen(str))
		str = ft_strndup(str, rez.accuracy);

	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		ft_putstr(str);
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
	}
	else if (rez.width > (int)ft_strlen(str) && !rez.minus)
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		ft_putstr(str);
	}
	else 
		ft_putstr(str);
	return (i + ft_strlen(str));
}

void		ft_printp(info rez, char *str)
{
	int i;

	i = 0;
	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		ft_putstr(str);
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
	}
	else if (rez.width > (int)ft_strlen(str) && !rez.minus)
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		ft_putstr(str);
	}
	else 
		ft_putstr(str);
}
int			ft_print_int(info rez, int mini, char *str2)
{
	int i;
	char *str;
	int j;

	i = 0;
	str = ft_itoa(mini);
	ft_flags_chek_int(&rez, mini, str2);
	str = (mini < 0) ? str + 1 : str;
	j = 0;
	j = ft_strlen(str);
	if (rez.accuracy > j)
		while (i < rez.accuracy - j)
		{
			str = ft_strjoin("0", str);
			i++;
			rez.nol = 0;
		}
	if (rez.accuracy < j && mini != 0)
		rez.accuracy = ft_strlen(str);
	if (mini < 0)
		i++;
	while (i < rez.width - j && rez.nol && !(ft_strchr(str2, '.')))
	{
		str = ft_strjoin("0", str);
		i++;
	}
	i = 0;
	str = (mini < 0) ? ft_strjoin("-", str) : str;
	if (rez.plus && mini >= 0 && rez.spec != 'u' && rez.spec != 'U')
		str = ft_strjoin("+", str);
	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
			ft_putchar(' ');
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		i--;
	}
	else if ((rez.width > (int)ft_strlen(str) && !rez.minus) || (rez.width && mini == 0))
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
			i--;
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
		{
			ft_putchar(' ');
			i++;
		}
	}
	else if (rez.accuracy != 0)
		ft_putstr(str);
	if (rez.accuracy == 0 && mini == 0)
		return (i);
	return (i + ft_strlen(str));
}

int			ft_print_uint(info rez, unsigned int mini, char *str2)
{
	int i;
	char *str;
	int j;

	i = 0;
	str = ft_uitoa(mini);
	ft_flags_chek_uint(&rez, mini, str2);
	str = (mini < 0) ? str + 1 : str;
	j = 0;
	j = ft_strlen(str);
	if (rez.accuracy > j)
		while (i < rez.accuracy - j)
		{
			str = ft_strjoin("0", str);
			i++;
			rez.nol = 0;
		}
	if (rez.accuracy < j && mini != 0)
		rez.accuracy = ft_strlen(str);
	if (mini < 0)
		i++;
	while (i < rez.width - j && rez.nol && !(ft_strchr(str2, '.')))
	{
		str = ft_strjoin("0", str);
		i++;
	}
	i = 0;
	str = (mini < 0) ? ft_strjoin("-", str) : str;
	if (rez.plus && mini >= 0 && rez.spec != 'u' && rez.spec != 'U')
		str = ft_strjoin("+", str);
	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
			ft_putchar(' ');
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		i--;
	}
	else if ((rez.width > (int)ft_strlen(str) && !rez.minus) || (rez.width && mini == 0))
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
			i--;
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
		{
			ft_putchar(' ');
			i++;
		}
	}
	else if (rez.accuracy != 0)
		ft_putstr(str);
	if (rez.accuracy == 0 && mini == 0)
		return (i);
	return (i + ft_strlen(str));
}

int			ft_print_per(info rez)
{
	int i;

	i = 0;
	int c;

	c = 37;

	if (rez.width > 1 && !rez.minus && rez.nol)
	{
		while (i++ < rez.width - 1)
			ft_putchar('0');
		ft_putchar(c);
	}
	else if (rez.width > 1 && !rez.minus)
	{
		while (i++ < rez.width - 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	else if (rez.width > 1 && rez.minus)
	{
		ft_putchar(c);
		while (i++ < rez.width -1)
			ft_putchar(' ');
	}
	else 
		ft_putchar(c);
	return (i + 1);
}

int			ft_print_p(info rez, void* ptr)
{
	char *str;
	int i;

	i = 0;
	if (ptr == NULL)
	{
		str = "0x0";
		while (++i < rez.accuracy)
			str = ft_strjoin(str, "0");
	}
	else
		str = ft_itoa_16((long long int) ptr);
	ft_printp(rez, str);
	return (i + ft_strlen(str));
}

info			ft_flags_check_x(info rez, char *num, char *str)
{
	if (!(ft_strchr(str, '.')))
		rez.accuracy = ft_strlen(num);
	rez.plus = 0;
	rez.space = 0;
	if (rez.minus)
		rez.nol = 0;
	return (rez);
}

char *ft_upperstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
		i++;
	}
	return (str);
}
int			ft_print_x(info rez, long long num, char *str_c)
{
	char *str;
	int j;
	int i;

	str = ft_ito16(num);
	i = 0;
	j = ft_strlen(str);
	rez = ft_flags_check_x(rez, str, str_c);
	str = (num < 0) ? str + 1 : str;
	j = 0;
	j = ft_strlen(str);
	if (rez.spec == 'X')
		str = ft_upperstr(str);
	if (rez.accuracy > j)
		while (i < rez.accuracy - j)
		{
			str = ft_strjoin("0", str);
			i++;
			rez.nol = 0;
		}
	if (rez.accuracy < j && num != 0)
		rez.accuracy = ft_strlen(str);
	if (num < 0)
		i++;
	while (i < rez.width - j && rez.nol && !(ft_strchr(str_c, '.')))
	{
		str = ft_strjoin("0", str);
		i++;
	}
	i = 0;
	str = (num < 0) ? ft_strjoin("-", str) : str;
	if (rez.plus && num >= 0 && rez.spec != 'u' && rez.spec != 'U')
		str = ft_strjoin("+", str);
	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
			ft_putchar(' ');
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		i--;
	}
	else if ((rez.width > (int)ft_strlen(str) && !rez.minus) || (rez.width && num == 0))
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
			i--;
		if (rez.accuracy != 0)
			ft_putstr(str);
		else
		{
			ft_putchar(' ');
			i++;
		}
	}
	else if (rez.accuracy != 0)
		ft_putstr(str);
	if (rez.accuracy == 0 && num == 0)
		return (i);
	return (i + ft_strlen(str));
}
unsigned int	ft_get_u(int i)
{
	unsigned int j;

	if (i < 0)
		j = 4294967296 + i;
	else 
		j = i;
	return (j);
}

void		ft_var(info rez, va_list list, char *str, int *n)
{
	if (rez.spec == 'c' || rez.spec == 'C')
		*n += ft_print_c(rez, va_arg(list, int)) ;
	else if (rez.spec == '%')
		*n += ft_print_per(rez) ;
	else if (rez.spec == 's' || rez.spec == 'S')
		*n += ft_print_str(rez, va_arg(list, char*), str) ;
	else if (ft_strchr("DdIi", rez.spec))
		*n += ft_print_int(rez, va_arg(list, int), str) ;
	else if (rez.spec == 'U' || rez.spec == 'u')
		*n += ft_print_uint(rez, ft_get_u(va_arg(list, int)), str) ;
	else if (rez.spec == 'p')
		*n += ft_print_p(rez, va_arg(list, void*)) ;
	else if (rez.spec == 'x' || rez.spec == 'X')
		*n += ft_print_x(rez, va_arg(list, long long), str) ;
}

info			ft_parse_form(char *str, va_list list, info rez, int *n)
{
	int i;
	int end;
	int *ptr;

	ptr = &i;
	i = 0;
	rez = ft_clear(rez, str);
	end = ft_strlen(str);
	while(i < end)
	{
		rez = ft_getting_flags(str, rez, ptr, list);
		i++;
	}
	if (rez.width < 0)
	{
		rez.width = -rez.width;
		rez.minus = 1;
	}
	ft_var(rez, list, str, n);

	return (rez);
}

