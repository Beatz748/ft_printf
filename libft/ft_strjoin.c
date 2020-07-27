/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:57:00 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:23 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		len;
	char	*dst;

	i = -1;
	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str1[++i] != '\0')
		dst[i] = str1[i];
	len = 0;
	while (str2[len] != '\0')
		dst[i++] = str2[len++];
	dst[i] = '\0';
	return (dst);
}
