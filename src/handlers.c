/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:12:15 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/19 13:33:42 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_char(char c, t_format *format, int *count)
{
	int fill_spaces;

	fill_spaces = ft_abs(format->width) - 1;
	if (format->width < 0)
		format->flags[0] = 1;
	ft_putnchar(' ', fill_spaces * (1 - format->flags[0]), count);
	ft_putnchar(c, 1, count);
	ft_putnchar(' ', fill_spaces * format->flags[0], count);
}

void	ft_string(char *str, t_format *format, int *count)
{
	int fill_spaces;
	int print_len;

	if (str == NULL)
	{
		ft_string("(null)", format, count);
		return ;
	}
	if (ft_abs(format->size < ft_strlen(str) && format->s_check == 1))
		print_len = ft_abs(format->size);
	else
		print_len = ft_strlen(str);
	fill_spaces = format->width - print_len;
	ft_putnchar(' ', fill_spaces * (1 - format->flags[0]), count);
	ft_putnstr(str, print_len, count);
	ft_putnchar(' ', fill_spaces * format->flags[0], count);
}

void	ft_int(int i, t_format *format, int *count)
{
	int fill_spaces_w;
	int fill_spaces_s;

	fill_spaces_w = (format->width * format->w_check) -
		(format->size * format->s_check) - len_nb((long long)i);
	fill_spaces_s = (format->size * format->s_check) - len_nb((long long)i);
	if (format->flags[1] == 0)
		ft_putnchar(' ', fill_spaces_w * (1 - format->flags[0]) , count);
	if (i < 0 && (format->flags[1] == 1 || format->s_check))
	{
		i *= -1;
		ft_putnchar('-', 1, count);
	}
	if (format->flags[1] && format->s_check == 0)
		ft_putnchar('0', fill_spaces_w * format->flags[1], count);
	else if (format->s_check == 1)
		ft_putnchar('0', format->size - len_nb((long long)i), count);
	ft_putnbr((long long)i, count);
	ft_putnchar(' ', fill_spaces_w * format->flags[0], count);
}
