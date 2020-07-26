#include "ft_printf.h"

int	ft_atoi(char *str)
{
	size_t				i;
	int					minus;
	unsigned long long	number;

	number = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number < 9223372036854775807)
			number = number * 10 + str[i++] - 48;
		if (number > 9223372036854775807 && minus < 0)
			return (0);
		else if (number > 9223372036854775807)
			return (-1);
	}
	return ((int)(number * minus));
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int nbr)
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

void	ft_putchar(char c)
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
	char	*copy;
	size_t	i;

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

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, i + 1);
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_uintlen(n);
	if (!(str = malloc(sizeof(char ) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		minus;

	minus = 1;
	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		minus = -1;
	n *= minus;
	if (!(str = malloc(sizeof(char ) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (minus == -1)
		str[0] = '-';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_16(long long int num)
{
	char			*itoa16;
	int				size;
	char			*str;
	long long int	k;

	k = num;
	size = 0;
	itoa16 = "0123456789abcdef";
	while (k /= 16)
		size++;
	size += 1;
	str = (char *)malloc(sizeof(char) * size + 3);
	str[size + 2] = '\0';
	while (size-- > 0)
	{
		str[size + 2] = itoa16[num % 16];
		num /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*ft_ito16(long long int num)
{
	char			*itoa16;
	int				size;
	char			*str;
	long long int	k;

	k = num;
	size = 0;
	itoa16 = "0123456789abcdef";
	while (k /= 16)
		size++;
	size += 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size-- > 0)
	{
		str[size] = itoa16[num % 16];
		num /= 16;
	}
	return (str);
}
