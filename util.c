/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:50:35 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/28 21:50:39 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toupper_x(t_info *rez, char **str)
{
	int i;

	i = 0;
	while (str[0][i] && rez->spec == 'X')
	{
		str[0][i] = ft_toupper(str[0][i]);
		i++;
	}
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int		ft_abs(int a)
{
	return (a < 0) ? -a : a;
}
