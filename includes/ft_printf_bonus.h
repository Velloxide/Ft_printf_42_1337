/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:06:43 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/07 13:44:10 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_spec
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		prec;
	char	type;
}			t_spec;

int			ft_printf(const char *format, ...);
int			ft_handle(const char *format, int *i, va_list *args);
int			ft_parse(const char *format, t_spec *spec);
int			ft_print_char(int c);
int			ft_print_c(t_spec *s, int c);
int			ft_print_s(t_spec *s, char *str);
int			ft_print_d_i(t_spec *s, int n);
int			ft_print_u(t_spec *s, unsigned int n);
int			ft_print_x(t_spec *s, unsigned int n);
int			ft_print_p(t_spec *s, void *ptr);
int			ft_pad(int pad, char c);
int			ft_print_field(t_spec *s, char *str, int len);
int			ft_print_str(char *s, size_t size);
int			ft_print_number(t_spec *s, char *prefix, char *digits, int len);
int			ft_zeros(t_spec *s, int plen, int len);
char		*ft_utoa_base(unsigned long long n, char *bufbase, int base);

#endif
