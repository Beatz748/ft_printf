/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:25:10 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/28 22:25:11 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flags_check_x(t_info *rez, char *str)
{
	if (rez->width < 0)
	{
		rez->width = ft_abs(rez->width);
		rez->minus = 1;
		rez->nol = 0;
	}
	if (ft_strchr(str, '.') && rez->accuracy >= 0)
		rez->nol = 0;
	if (rez->minus)
		rez->nol = 0;
}

void		ft_minus_x(t_info *rez, unsigned long long num, int *i, char *s)
{
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void		ft_print_flags_x(t_info *rez, int *j)
{
	while (*j < rez->width)
	{
		if (rez->nol == 1 && rez->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*j)++;
	}
}

int			ft_print_x(t_info *rez, unsigned int num, char *str_c)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	if (!(str = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_flags_check_x(rez, str_c);
	i = ft_strlen(str);
	ft_toupper_x(rez, &str);
	i = (i == rez->accuracy) ? i : i - rez->accuracy;
	j = (i < 0) ? rez->accuracy : (int)ft_strlen(str);
	if (rez->accuracy == 0 && num == 0)
		j = 0;
	if (rez->minus == 1)
		ft_minus_x(rez, (unsigned long long)num, &i, str);
	ft_print_flags_x(rez, &j);
	if (rez->minus == 0)
		ft_minus_x(rez, (unsigned long long)num, &i, str);
	free(str);
	return (j);
}

int			ft_print_p(t_info *rez, void *ptr)
{
	int			j;
	char		*s;

	if (!(s = ft_itoa_hex((unsigned long long)ptr)))
		return (-1);
	j = ft_strlen(s) + 2;
	if (rez->minus == 1)
	{
		write(1, "0x", 2);
		ft_putstr_fd(s, 1);
	}
	while (j < rez->width)
	{
		write(1, " ", 1);
		j++;
	}
	if (rez->minus == 0)
	{
		write(1, "0x", 2);
		ft_putstr_fd(s, 1);
	}
	free(s);
	return (j);
}
