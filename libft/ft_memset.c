/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:56:53 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:56 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	while (i < len)
	{
		s1[i] = c;
		i++;
	}
	return (s);
}
