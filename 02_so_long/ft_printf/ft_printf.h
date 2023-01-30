/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:56:42 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 12:32:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define FLAG "#0- +"
# define CONVERSION "cspdiuxX%"

# define DEC "0123456789"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

typedef struct s_spec
{
	char	alter_form;
	char	zero_pad;
	char	left_adjust;
	char	blank_sign;
	char	sign;
	char	precision_flag;
	int		width;
	int		precision;
	char	conversion;
	char	*head;
	char	pad_chr;
}				t_spec;

int		ft_printf(const char *format, ...);

int		match_conversion(const char *format);
void	parse_conversion(const char **format, t_spec *spec);

int		ft_print_c(char arg, t_spec *spec);
int		ft_print_s(char *arg, t_spec *spec);
int		ft_print_p(void *arg, t_spec *spec);
int		ft_print_d(int arg, t_spec *spec);
int		ft_print_i(int arg, t_spec *spec);
int		ft_print_u(unsigned int arg, t_spec *spec);
int		ft_print_x(unsigned int arg, t_spec *spec);
int		ft_print_x_upper(unsigned int arg, t_spec *spec);
int		ft_print_percentage(t_spec *spec);

int		ft_print_x_hex(unsigned int n, int precision, int width, t_spec *spec);

int		ft_print_width(int width, t_spec *spec);
int		ft_print_head(int width, t_spec *spec);
int		ft_print_precision(int precision, int width, t_spec *spec);

int		is_chrset(const char c, const char *set);
int		is_digit(const char c);
int		ft_abs(int n);
int		ft_p_strlen(const char *str);
long	ft_strtol(const char *str, const char **endptr);
char	*ft_strdup(const char *str);

#endif