/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:12:47 by kshantel          #+#    #+#             */
/*   Updated: 2020/08/01 03:14:36 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info			ft_clear(t_info rez, char *format_mini)
{
	rez.nol = 0;
	rez.minus = 0;
	rez.width = 0;
	rez.spec = format_mini[ft_strlen(format_mini) - 1];
	rez.accuracy = -1;
	return (rez);
}

t_info			ft_checking(char *str, t_info rez, char *main)
{
	size_t	i;

	i = 0;
	if (!(str = ft_strchr(str, '.')))
		rez.accuracy = ft_strlen(main);
	if (rez.accuracy < 0)
	{
		rez.accuracy = ft_strlen(main);
	}
	return (rez);
}

t_info			ft_getting_acc(char *str, t_info rez, int *i, va_list list)
{
	if (str[*i] == '*' && str[*i - 1] != '.')
	{
		rez.width = va_arg(list, int);
		return (rez);
	}
	else if (str[*i] >= '1' && str[*i] <= '9')
	{
		(rez.width) = atoi(str + *i);
		*i += ft_intlen(rez.width) - 1;
	}
	return (rez);
}

t_info			ft_getting_flags(char *str, t_info rez, int *i, va_list list)
{
	if (str[*i] == '-')
		rez.minus = 1;
	if (str[*i] == '0')
		rez.nol = 1;
	if (str[*i] == '.')
	{
		if (str[*i + 1] == '*')
		{
			rez.accuracy = va_arg(list, int);
			return (rez);
		}
		else
		{
			rez.accuracy = ft_atoi(str + *i + 1);
			*i += ft_intlen(rez.accuracy) + 1;
			if (*i-- == '0')
				*i += 1;
		}
	}
	if ((str[*i] >= '1' && str[*i] <= '9') || str[*i] == '*')
		rez = ft_getting_acc(str, rez, i, list);
	return (rez);
}
