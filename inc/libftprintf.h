/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:01:39 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/17 18:11:21 by vgoldman         ###   ########.fr       */
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
}				t_format;

int				ft_printf(const char *format, ...);
void			handle_format(char **ptr, va_list args, int *count);
void			get_flags(char **ptr, t_format *format);
void			get_width(char **ptr, t_format *format, va_list args);
void			get_size(char **ptr, t_format *format, va_list args);
int				ft_isflag(char c);
int				ft_isdigit(char c);
int				ft_atoi(char **str);
void			ft_putchar(char c);
void			print_flags(t_format *format);

#endif
