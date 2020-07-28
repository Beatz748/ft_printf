/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:19:26 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/28 22:21:11 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_intlen(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

void		ft_prinm(t_info *rez, long long num, int *i, char *s)
{
	if (num < 0 && rez->nol == 0)
		write(1, "-", 1);
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void		ft_prflagint(t_info *rez, int *res, long long num)
{
	if (rez->nol == 1 && num != 0)
	{
		if (num < 0)
			write(1, "-", 1);
	}
	while (*res < rez->width)
	{
		if (rez->nol == 1 && rez->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*res)++;
	}
}

void		ft_flags_chek_int(t_info *rez, char *str)
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

int			ft_print_int(t_info *rez, int mini, char *str2)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	if (!(str = ft_lltoa_u((long long int)mini)))
		return (-1);
	ft_flags_chek_int(rez, str2);
	i = ft_strlen(str);
	i = (i == rez->accuracy) ? i : i - rez->accuracy;
	j = (i < 0) ? rez->accuracy : (int)ft_strlen(str);
	j = (mini < 0) ? j + 1 : j;
	if (rez->accuracy == 0 && mini == 0)
		j = 0;
	if (rez->minus == 1)
		ft_prinm(rez, (long long)mini, &i, str);
	ft_prflagint(rez, &j, (long long)mini);
	if (rez->minus != 1)
		ft_prinm(rez, (long long)mini, &i, str);
	free(str);
	return (j);
}
