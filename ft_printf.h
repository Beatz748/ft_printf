#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_info
{
	int				nol;
	int				minus;
	int				width;
	char			spec;
	int				accuracy;
}					t_info;

int			ft_abs(int a);

char		*ft_lltoa_u(long long int n);

void		ft_toupper_x(t_info *rez, char **str);

t_info		ft_parse_form(char *str, va_list list, t_info rez, int *n);

int			ft_print_c(t_info rez, int c);

void		ft_putstr_fd(char *s, int fd);

char		*ft_uitoa(unsigned int n);

t_info		ft_getting_flags(char *str, t_info rez, int *i, va_list list);

t_info		ft_clear(t_info rez, char *format_mini);

char		*ft_strchr(const char *s, int c);

char		*ft_strjoin(char const *s1, char const *s2);

int			ft_intlen(long long n);

int			ft_uintlen(unsigned int n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_find_c(char *str);

char		*ft_strndup(const char *s1, size_t nb);

char		*ft_strcdup(const char *s, int c);

size_t		ft_strlen(const char *s);

int			ft_printf(const char *format, ...);

int			ft_parse_all(const char **format, va_list *list);

void		ft_spec(char *str, va_list list);

void		ft_put_smth(char c, va_list list);

int			ft_tolower(int c);

char		*ft_find_spec(char *s);

void		ft_putnbr(int nbr);

char		*ft_itoa_hex(long long int n);

void		ft_flags_check_x(t_info *rez, char *str);

void		ft_putstr(char *s);

void		ft_putchar(char c);

char		*ft_itoa_16(long long int num);

int			ft_print_uint(t_info *rez, unsigned int mini, char *str2);

t_info		ft_checking(char *str, t_info rez, char *main);

int			ft_print_p(t_info *rez, void *ptr);

void		ft_print_flags_x(t_info *rez, int *j);

void		ft_minus_x(t_info *rez, unsigned long long num, int *i, char *s);

void		ft_var(t_info rez, va_list list, char *str, int *n);

t_info		ft_parse_form(char *str, va_list list, t_info rez, int *n);

int			ft_print_per(t_info rez);

void		ft_prflagint(t_info *rez, int *res, long long num);

void		ft_prinm(t_info *rez, long long num, int *i, char *s);

int			ft_intlen(long long n);

void		ft_flags_chek_int(t_info *rez, char *str);

void		ft_priunm(t_info *rez, long long num, int *i, char *s);

void		ft_printfu(t_info *rez, int *j);

void		ft_flags_chek_uint(t_info *rez, unsigned int j, char *str);

int			ft_print_int(t_info *rez, int mini, char *str2);

int			ft_print_str(t_info rez, char *str, char *for_check);

int			ft_print_c(t_info rez, int c);

int			ft_print_x(t_info *rez, unsigned int num, char *str_c);

#endif
