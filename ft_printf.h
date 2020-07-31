/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 02:12:39 by kshantel          #+#    #+#             */
/*   Updated: 2020/08/01 02:12:41 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_info
{
	int				nol;
	int				minus;
	int				width;
	char			spec;
	int				accuracy;
}				t_info;

int				ft_abs(int a);

void			ft_flags_str(t_info *rez, int *len);

char			*ft_lltoa_u(long long int n);

void			ft_toupper_x(t_info *rez, char **str);

t_info			ft_parse_form(char *str, va_list list, t_info rez, int *n);

int				ft_print_c(t_info rez, int c);

char			*ft_uitoa(unsigned int n);

t_info			ft_getting_flags(char *str, t_info rez, int *i, va_list list);

t_info			ft_clear(t_info rez, char *format_mini);

int				ft_intlen(long long n);

int				ft_uintlen(unsigned int n);

char			*ft_find_c(char *str);

int				ft_printf(const char *format, ...);

int				ft_parse_all(const char **format, va_list *list);

void			ft_putnbr(int nbr);

char			*ft_itoa_hex(long long int n);

void			ft_flags_check_x(t_info *rez, char *str);

void			ft_putstr(char *s);

void			ft_putchar(char c);

int				ft_print_uint(t_info *rez, unsigned int mini, char *str2);

t_info			ft_checking(char *str, t_info rez, char *main);

int				ft_print_p(t_info *rez, void *ptr);

void			ft_print_flags_x(t_info *rez, int *j);

void			ft_var(t_info rez, va_list list, char *str, int *n);

t_info			ft_parse_form(char *str, va_list list, t_info rez, int *n);

int				ft_print_per(t_info rez);

void			ft_prflagint(t_info *rez, int *res, long long num);

void			ft_prinm(t_info *rez, long long num, int *i, char *s);

int				ft_intlen(long long n);

void			ft_flags_chek_int(t_info *rez, char *str);

void			ft_priunm(t_info *rez, long long num, int *i, char *s);

void			ft_printfu(t_info *rez, int *j);

int				ft_print_int(t_info *rez, int mini, char *str2);

int				ft_print_str(t_info *rez, char *str);

int				ft_print_c(t_info rez, int c);

int				ft_mini(char *s, va_list *list, t_info *rez);

t_info			ft_getting_acc(char *str, t_info rez, int *i, va_list list);

int				ft_print_x(t_info *rez, unsigned int num, char *str_c);

#endif
