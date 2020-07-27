/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:00:11 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:18 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_num(int n, int len, int flag)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * len + 2)))
		return (NULL);
	str[len + 1] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (flag == 1)
		str[0] = '-';
	while (n != 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int len;
	int n_len;
	int flag;

	len = 0;
	flag = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		flag = 1;
		n = -n;
		len++;
	}
	n_len = n;
	while (n_len /= 10)
		len++;
	return (get_num(n, len, flag));
}
