/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:01:39 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/19 11:18:26 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_format
{
	int		flags[6];
	int		width;
	int		size;
	char	spec;
	int		w_check;
	int		s_check;
}				t_format;

int				ft_printf(const char *format, ...);
void			handle_format(char **ptr, va_list args, int *count);
void			get_flags(char **ptr, t_format *format);
void			get_width(char **ptr, t_format *format, va_list args);
void			get_size(char **ptr, t_format *format, va_list args);
int				ft_isflag(char c);
int				ft_isdigit(char c);
int				ft_atoi(char **str);
void			ft_putnchar(char c, int n, int *count);
void			ft_putnstr(char *str, int n, int *count);
int				len_nb(long long n);
int				ft_abs(int n);
int				ft_strlen(char *str);
void			send_to(va_list args, t_format *format, int *count);
void			ft_putnbr(long long nb, int *count);
void			ft_char(char c, t_format *format, int *count);
void			ft_string(char *str, t_format *format, int *count);
void			ft_int(int i, t_format *format, int *count);
void			print_flags(t_format *format);
#endif
