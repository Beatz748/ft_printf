/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:02:09 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:19 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	c1;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c1)
			return (dst2 + i + 1);
		i++;
	}
	return (NULL);
}
