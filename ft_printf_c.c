/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:18:18 by kshantel          #+#    #+#             */
/*   Updated: 2020/08/01 02:12:26 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_per(t_info rez)
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

int		ft_print_str(t_info *rez, char *str)
{
	int		j;
	int		len;

	if (!(str))
		str = "(null)";
	len = ft_strlen(str);
	ft_flags_str(rez, &len);
	j = len;
	while (rez->minus == 1 && len--)
	{
		write(1, str, 1);
		str++;
	}
	while (j < rez->width)
	{
		write(1, " ", 1);
		j++;
	}
	while (rez->minus == 0 && len--)
	{
		write(1, str, 1);
		str++;
	}
	return (j);
}

int		ft_print_c(t_info rez, int c)
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
