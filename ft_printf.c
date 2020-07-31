/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:56:36 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/31 23:57:05 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_var(t_info rez, va_list list, char *str, int *n)
{
	if (rez.spec == 'c' || rez.spec == 'C')
		*n += ft_print_c(rez, va_arg(list, int));
	else if (rez.spec == '%')
		*n += ft_print_per(rez);
	else if (rez.spec == 's' || rez.spec == 'S')
		*n += ft_print_str(&rez, va_arg(list, char*));
	else if (ft_strchr("DdIi", rez.spec))
		*n += ft_print_int(&rez, va_arg(list, int), str);
	else if (rez.spec == 'U' || rez.spec == 'u')
		*n += ft_print_uint(&rez, va_arg(list, unsigned int), str);
	else if (rez.spec == 'p')
		*n += ft_print_p(&rez, va_arg(list, void*));
	else if (rez.spec == 'x' || rez.spec == 'X')
		*n += ft_print_x(&rez, va_arg(list, unsigned int), str);
}

t_info		ft_parse_form(char *str, va_list list, t_info rez, int *n)
{
	int i;
	int end;
	int *ptr;

	ptr = &i;
	i = 0;
	rez = ft_clear(rez, str);
	end = ft_strlen(str);
	while (i < end)
	{
		rez = ft_getting_flags(str, rez, ptr, list);
		i++;
	}
	if (rez.width < 0)
	{
		rez.width = -rez.width;
		rez.minus = 1;
	}
	ft_var(rez, list, str, n);
	return (rez);
}

int			ft_mini(char *s, va_list *list, t_info *rez)
{
	char	*cop;
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ((cop = ft_find_c(s + i + 1))))
		{
			*rez = ft_parse_form(cop, *list, *rez, &r);
			i += ft_strlen(cop) - 1;
			free(cop);
		}
		else if (s[i] != '%')
		{
			ft_putchar(s[i]);
			r++;
		}
		i++;
	}
	return (r);
}

int			ft_parse_all(const char **format, va_list *list)
{
	int		r;
	t_info	*rez;
	char	*s;

	s = (char *)*format;
	r = 0;
	if (!(rez = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	r = ft_mini(s, list, rez);
	free(rez);
	return (r);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;

	va_start(list, format);
	i = ft_parse_all(&format, &list);
	va_end(list);
	return (i);
}
