#include "ft_printf.h"

void ft_putchar(char c)
{
	 write(1, &c, 1);
}

void			ft_putnbr(int nbr)
{
	unsigned int nb;

	if (nbr < 0)
	{
		nb = (unsigned int)-nbr;
		ft_putchar('-');
	}
	else
		nb = (unsigned int)nbr;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

char		*ft_find_spec(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void ft_put_smth(char c, va_list list)
{
	if (c == 'c')
		ft_putchar((char)list);
}

void ft_spec(char c, va_list list)
{
	c = ft_tolower(c);
	if (ft_find_spec("cdiefgosuxpn%", c) != 0)
			ft_put_smth(c, list);
}

void	ft_parse_all(const char *str, va_list list)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_spec(str[++i], list);
	}
}
