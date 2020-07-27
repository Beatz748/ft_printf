/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:51:27 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:26 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = dsize;
	if (!dst || !src)
		return (0);
	while (size-- > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dsize)
		dst[i] = '\0';
	else if (dsize > 0)
		dst[i - 1] = '\0';
	return (ft_strlen(src));
}
