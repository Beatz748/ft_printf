#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_atoi(char *str);

typedef struct    info_str
{
    int        nol;
    int        resh;
    int        minus;
    int        plus;
    int        width;
    char       spec;
    int        space;
    int            accuracy;
}                info;

info    ft_parse_form(char *str, va_list list);

void    ft_getting_flags(char *str, info rez, int i, va_list list);

info    ft_clear(info rez, char *format_mini);

char    *ft_strchr(const char *s, int c);

int        ft_intlen(int n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

int        ft_find_c(char *str);

char	*ft_strndup(const char *s1, size_t nb);

char	*ft_strcdup(const char *s, int c);

size_t		ft_strlen(const char *s);

void		ft_printf(char *format, ...);

void		ft_parse_all(char *format, va_list list);

void		ft_spec(char *str, va_list list);

void		ft_put_smth(char c, va_list list);

int			ft_tolower(int c);

char		*ft_find_spec(char *s);

void		ft_putnbr(int nbr);

void		ft_putstr(char *s);

void		ft_putchar(char c);
#endif
