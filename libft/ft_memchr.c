/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:18:21 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:20 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
