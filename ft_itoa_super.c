/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_super.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:10:56 by kshantel          #+#    #+#             */
/*   Updated: 2020/08/01 02:14:11 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_u(long long int n)
{
	size_t		i;
	long long	j;
	char		*str;

	j = n;
	i = (j == 0) ? 1 : 0;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	j = (j < 0) ? -j : j;
	while (i-- > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
	}
	return (str);
}

char	*ft_itoa_hex(long long int n)
{
	int					i;
	unsigned long long	j;
	char				*str;
	char				*hex;

	j = n;
	str = "\0";
	i = (j == 0) ? 1 : 0;
	hex = "0123456789abcdef";
	while (j != 0)
	{
		j = j / 16;
		i++;
	}
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	while (i-- > 0)
	{
		str[i] = hex[j % 16];
		j = j / 16;
	}
	return (str);
}
