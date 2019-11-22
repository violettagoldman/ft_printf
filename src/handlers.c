/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:12:15 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/22 17:43:23 by vgoldman         ###   ########.fr       */
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
	ft_putnchar((format->flags[1] ? '0' : ' '), fill_spaces * (1 - format->flags[0]), count);
	ft_putnstr(str, print_len, count);
	ft_putnchar(' ', fill_spaces * format->flags[0], count);
}

void	ft_int(int i, t_format *format, int *count)
{
	int fill_spaces;
	int fill_zero;

	fill_spaces = 0;
	fill_zero = 0;
	if ((format->size == 0 && format->s_check && i == 0) || (format->s_check && format->size > 0) || (format->width < 0 && format->size < 0))
		format->flags[1] = 0;
	if (format->width < 0)
		format->flags[0] = 1;
	if (format->size > len_nb((long long)i) || (format->flags[1] && format->s_check))
		fill_zero = ft_abs(format->size) - len_nb((long long)i) + (i < 0);
	else if (format->flags[1] && format->width > 0)
		fill_zero = ft_abs(format->width) - len_nb((long long)i)/* + (i < 0)*/;

	if (ft_abs(format->width) > len_nb((long long)i) + fill_zero)
		fill_spaces = ft_abs(format->width) - len_nb((long long)i) - fill_zero;
	
	if (format->size == 0 && format->s_check && i == 0 && fill_spaces)
	{
		format->flags[1] = 0;
		fill_spaces++;
	}
	if (!(format->flags[0]) && !(format->flags[1]))
		ft_putnchar(' ', fill_spaces, count);
	
	if (i < 0)
		ft_putnchar('-', 1, count);
	
	if (!(format->flags[0]) && format->flags[1])
		ft_putnchar('0', fill_spaces, count);
	
	if (i >= 0 && (format->flags[2] || format->flags[3]))
		ft_putnchar((format->flags[2] ? '+' : ' '), 1, count);
	
	ft_putnchar('0', fill_zero, count);
	if (format->size != 0 || i != 0 || !(format->s_check))
		ft_putnbr(i, count);
	
	if (format->flags[0])
		ft_putnchar(' ', fill_spaces, count);
}
