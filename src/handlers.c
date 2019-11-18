/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:12:15 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/18 12:49:41 by vgoldman         ###   ########.fr       */
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
