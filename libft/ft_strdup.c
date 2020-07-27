/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:14:40 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:22 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((res = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) != NULL)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
