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

info    ft_parse_form(char *str, va_list list, info rez, int *n);

int    ft_print_c(info rez, int c);

char	*ft_itoa(int n);

char	*ft_uitoa(unsigned int n);

info    ft_getting_flags(char *str, info rez, int *i, va_list list);

info    ft_clear(info rez, char *format_mini);

char    *ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

int        ft_intlen(long long n);

int        ft_uintlen(unsigned int n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

int        ft_find_c(char *str);

char	*ft_strndup(const char *s1, size_t nb);

char	*ft_strcdup(const char *s, int c);

size_t		ft_strlen(const char *s);

int		ft_printf(char *format, ...);

int		ft_parse_all(char *format, va_list list);

void		ft_spec(char *str, va_list list);

void		ft_put_smth(char c, va_list list);

int			ft_tolower(int c);

char		*ft_find_spec(char *s);

void		ft_putnbr(int nbr);

char *ft_ito16(long long int num);

info ft_flags_check_x(info rez, char *num, char *str);

void		ft_putstr(char *s);

void		ft_putchar(char c);

char        *ft_itoa_16(long long int num);

int		ft_print_x(info rez, long long num, char *str_c);

#endif
