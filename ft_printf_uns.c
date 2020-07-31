/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:20:35 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/28 22:20:54 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfu(t_info *rez, int *j)
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

void	ft_priunm(t_info *rez, long long num, int *i, char *s)
{
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (rez->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

int		ft_print_uint(t_info *rez, unsigned int mini, char *str2)
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
		ft_priunm(rez, (long long)mini, &i, str);
	ft_printfu(rez, &j);
	if (rez->minus != 1)
		ft_priunm(rez, (long long)mini, &i, str);
	free(str);
	return (j);
}
