/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:18:18 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/28 22:25:57 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_per(t_info rez)
{
	int i;

	i = 0;
	if (rez.width > 1 && !rez.minus && rez.nol)
	{
		while (i++ < rez.width - 1)
			ft_putchar('0');
		ft_putchar(37);
	}
	else if (rez.width > 1 && !rez.minus)
	{
		while (i++ < rez.width - 1)
			ft_putchar(' ');
		ft_putchar(37);
	}
	else if (rez.width > 1 && rez.minus)
	{
		ft_putchar(37);
		while (i++ < rez.width - 1)
			ft_putchar(' ');
	}
	else
		ft_putchar(37);
	return (i + 1);
}

int			ft_print_str(t_info rez, char *str, char *for_check)
{
	int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	rez = ft_checking(for_check, rez, str);
	if (rez.accuracy < (int)ft_strlen(str))
		str = ft_strndup(str, rez.accuracy);
	if (rez.width > (int)ft_strlen(str) && rez.minus)
	{
		ft_putstr(str);
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		i--;
	}
	else if (rez.width > (int)ft_strlen(str) && !rez.minus)
	{
		while (i++ < rez.width - (int)ft_strlen(str))
			ft_putchar(' ');
		i--;
		ft_putstr(str);
	}
	else
		ft_putstr(str);
	return (i + ft_strlen(str));
}

int			ft_print_c(t_info rez, int c)
{
	int i;

	i = 0;
	if (rez.width > 1 && !rez.minus)
	{
		while (i++ < rez.width - 1)
			ft_putchar(' ');
		ft_putchar(c);
		i--;
	}
	else if (rez.width > 1 && rez.minus)
	{
		ft_putchar(c);
		while (i++ < rez.width - 1)
			ft_putchar(' ');
		i--;
	}
	else
		ft_putchar(c);
	return (i + 1);
}
