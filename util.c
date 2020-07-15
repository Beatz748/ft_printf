#include "ft_printf.h"

int		ft_atoi(char *str)
{
	long			res;
	long			sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int        ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

void				ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void            ft_putnbr(int nbr)
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

void ft_putchar(char c)
{
     write(1, &c, 1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}

char	*ft_strndup(const char *s1, size_t nb)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (nb + 1));
	if (dst == NULL)
		return (NULL);
	dst[nb] = '\0';
	return ((char *)ft_memcpy(dst, s1, nb));
}

char	*ft_strcdup(const char *s, int c)
{
	char    *copy;
    size_t  i;

    i = 0;
    while (s[i] != (char)c && s[i] != '\0')
        i++;
    if (!(copy = malloc(sizeof(char) * i + 1)))
        return (NULL);
    copy[i] = '\0';
    while (i-- > 0)
        copy[i] = s[i];
    return (copy);
}
