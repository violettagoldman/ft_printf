/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:23:48 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/18 13:30:34 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_format(char **ptr, va_list args, int *count)
{
	t_format format;

	format.w_check = 0;
	format.s_check = 0;
	get_flags(ptr, &format);
	get_width(ptr, &format, args);
	get_size(ptr, &format, args);
	format.spec = **ptr;
	(*ptr)++;
	send_to(args, &format, count);
	//print_flags(&format);
}

void	send_to(va_list args, t_format *format, int *count)
{
	if (format->spec == 'c')
		ft_char((char)va_arg(args, int), format, count);
	if (format->spec == 's')
		ft_string(va_arg(args, char*), format, count);
}

void	print_flags(t_format *format)
{
	int i;

	i = 0;
	puts("");
	while (i < 6)
	{
		printf("flags[%d] == %d\n", i, format->flags[i]);
		i++;
	}
	printf("spec == %c\n", format->spec);
	printf("width == %d && %d\n", format->width, format->w_check);
	printf("size == %d  && %d\n", format->size, format->s_check);
}

void	get_flags(char **ptr, t_format *format)
{
	int i;

	i = 0;
	while (i < 6)
		format->flags[i++] = 0;
	while (ft_isflag(**ptr))
	{
		if (**ptr == '-')
			format->flags[0] = 1;
		else if (**ptr == '0')
			format->flags[1] = 1;
		else if (**ptr == '+')
			format->flags[2] = 1;
		else if (**ptr == ' ')
			format->flags[3] = 1;
		else if (**ptr == '#')
			format->flags[4] = 1;
		else if (**ptr == 39)
			format->flags[5] = 1;
		(*ptr)++;
	}
}

void	get_width(char **ptr, t_format *format, va_list args)
{
	if (**ptr == '*')
	{
		format->width = va_arg(args, int);
		(*ptr)++;
		format->w_check = 1;
	}
	else if (ft_isdigit(**ptr))
	{
		format->width = ft_atoi(ptr);
		format->w_check = 1;
	}
}

void	get_size(char **ptr, t_format *format, va_list args)
{
	if (**ptr == '.')
	{
		(*ptr)++;
		if (**ptr == '*')
		{
			format->size = va_arg(args, int);
			(*ptr)++;
		}
		else
			format->size = ft_atoi(ptr);
		format->s_check = 1;
	}
}
