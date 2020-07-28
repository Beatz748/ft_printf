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
	rez.accuracy = -1;
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
		i--;
	}
	else if (rez.width > 1 && rez.minus)
	{
		ft_putchar(c);
		while (i++ < rez.width -1)
			ft_putchar(' ');
			i--;
	}
	else 
		ft_putchar(c);
	return (i + 1);
}

void			ft_flags_chek_int(info *rez, char *str)
{
	if (rez->width < 0)
	{
		rez->width = ft_abs(rez->width);
		rez->minus = 1;
		rez->nol = 0;
	}
	if (ft_strchr(str, '.') && rez->accuracy >= 0)
		rez->nol = 0;
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
		i--;
	}
	else if (rez.width > (int)ft_strlen(str) && !rez.minus)
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
			i--;
		ft_putstr(str);
	}
	else 
		ft_putstr(str);
	return (i + ft_strlen(str));
}

char		*ft_printp(info rez, char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(str);
	if (rez.width > j && rez.minus)
	{
		while (i++ < rez.width - j)
			str = ft_strjoin(str, " ");
	}
	else if (rez.width > j && !rez.minus)
	{
		while (i++ < rez.width - j)
			str = ft_strjoin(" ", str);
	}
	return (str);
}


char *ft_ult(char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(str);
	while(str[i] != '\0')
	{
		if (str[i] == '-' && str[i - 1] == '0')
		{
			str[i] = '0';
			str[0] = '-';
		}
		i++;
	}
	return(str);
}

void	ft_prinm(info *rez, long long num, int *i, char *s)
{
	if (num < 0 && rez->nol == 0)
		write(1, "-", 1);
	if (rez->plus == 1 && num >= 0 && rez->nol == 0)
		write(1, "+", 1);
	if (rez->space == 1 && num >= 0 && rez->nol == 0)
		write(1, " ", 1);
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void	ft_prflagint(info *rez, int *res, long long num)
{
	if (rez->nol == 1 && num != 0)
	{
		if (num < 0)
			write(1, "-", 1);
		if (rez->plus == 1 && num >= 0)
			write(1, "+", 1);
		if (rez->space == 1 && num >= 0)
			write(1, " ", 1);
	}
	while (*res < rez->width)
	{
		if (rez->nol == 1 && rez->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*res)++;
	}
}

int			ft_print_int(info *rez, int mini, char *str2)
{
	int i;
	char *str;
	int j;

	j = 0;
	if (!(str = ft_lltoa_u((long long int)mini)))
		return (-1);
	ft_flags_chek_int(rez, str2);
	i = ft_strlen(str);
	i = (i == rez->accuracy) ? i : i - rez->accuracy;
	j = (i < 0) ? rez->accuracy : (int)ft_strlen(str);
	j = (mini < 0 || rez->plus == 1 || rez->space == 1) ? j + 1 : j;
	if (rez->accuracy == 0 && mini == 0)
		j = 0;
	if (rez->minus == 1)
		ft_prinm(rez, (long long)mini, &i, str);
	ft_prflagint(rez, &j, (long long)mini);
	if (rez->minus != 1)
		ft_prinm(rez, (long long)mini, &i, str);
	free(str);
	return (j);
}

void	ft_printfu(info *rez, int *j)
{
	while (*j < rez->width)
	{
		if (rez->nol == 1 && rez->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*j)++;
	}
}

void	ft_priunm(info *rez, long long num, int *i, char *s)
{
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

int			ft_print_uint(info *rez, unsigned int mini, char *str2)
{
	int i;
	char *str;
	int j;

	j = 0;
	if (!(str = ft_lltoa_u((long long int)mini)))
		return (-1);
	ft_flags_chek_int(rez, str2);
	i = ft_strlen(str);
	i = (i == rez->accuracy) ? i : i - rez->accuracy;
	j = (i < 0) ? rez->accuracy : (int)ft_strlen(str);
	j = (mini < 0 || rez->plus == 1 || rez->space == 1) ? j + 1 : j;
	if (rez->accuracy == 0 && mini == 0)
		j = 0;
	if (rez->minus == 1)
		ft_priunm(rez, (long long)mini, &i, str);
	ft_printfu(rez, &j);
	if (rez->minus != 1)
		ft_priunm(rez, (long long)mini, &i, str);
	free(str);
	return (j);
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
			i--;
	}
	else
			if (!(str = ft_itoa_16((long long int)ptr)))
		return (-1);
	str = ft_printp(rez, str);
	ft_putstr(str);
	return (i + ft_strlen(str));
}

void			ft_flags_check_x(info *rez, char *str)
{
	if (rez->width < 0)
	{
		rez->width = ft_abs(rez->width);
		rez->minus = 1;
		rez->nol = 0;
	}
	if (ft_strchr(str, '.') && rez->accuracy >= 0)
		rez->nol = 0;
	if (rez->minus)
		rez->nol = 0;
}

void	ft_upperstr(char **str, info rez)
{
	int i;

	i = 0;
	if (rez.spec == 'X')
	{
	while (str[i] != '\0')
	{
		if (**str <= 122 && **str >= 97)
			str[i] -= 32;
		i++;
	}
	}
}

void		ft_minus_x(info *rez, unsigned long long num,
		int *i, char *s)
{
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void	ft_print_flags_x(info *rez, int *j)
{
	while (*j < rez->width)
	{
		if (rez->nol == 1 && rez->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*j)++;
	}
}

int			ft_print_x(info *rez, unsigned int num, char *str_c)
{
	char *str;
	int j;
	int i;
	
	j = 0;
	if (!(str = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_flags_check_x(rez, str_c);
	i = ft_strlen(str);
	ft_toupper_x(rez, &str);
	i = (i == rez->accuracy) ? i : i - rez->accuracy;
	j = (i < 0) ? rez->accuracy : (int)ft_strlen(str);
	if (rez->accuracy == 0 && num == 0)
		j = 0;
	if (rez->minus == 1)
		ft_minus_x(rez, (unsigned long long)num, &i, str);
	ft_print_flags_x(rez, &j);
	if (rez->minus == 0)
		ft_minus_x(rez, (unsigned long long)num, &i, str);
		free (str);
		return (j);
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
		*n += ft_print_int(&rez, va_arg(list, int), str) ;
	else if (rez.spec == 'U' || rez.spec == 'u')
		*n += ft_print_uint(&rez, ft_get_u(va_arg(list, int)), str) ;
	else if (rez.spec == 'p')
		*n += ft_print_p(rez, va_arg(list, void*)) ;
	else if (rez.spec == 'x' || rez.spec == 'X')
		*n += ft_print_x(&rez, va_arg(list, unsigned int), str) ;
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

