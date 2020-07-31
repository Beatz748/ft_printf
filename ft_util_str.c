/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:58:34 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/31 23:58:35 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_str(t_info *rez, int *len)
{
	if (rez->width < 0)
	{
		rez->width = ft_abs(rez->width);
		rez->minus = 1;
		rez->nol = 0;
	}
	if (rez->accuracy > -1)
		*len = (rez->accuracy > *len) ? *len : rez->accuracy;
}

char	*ft_found(char *str, int i)
{
	char	*ha;
	int		start;

	start = 0;
	ha = malloc(2 + i);
	*ha = '%';
	while (start <= i)
	{
		ha[start + 1] = str[start];
		start++;
	}
	ha[i + 2] = '\0';
	return (ha);
}

char	*ft_find_c(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		start;

	i = 0;
	start = 0;
	s = "dDiIsScCu%UxXpPgGeEn";
	while (str[i] != '\0')
	{
		j = 0;
		while (s[j] != '\0')
		{
			if (str[i] == s[j])
			{
				return (ft_found(str, i));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
