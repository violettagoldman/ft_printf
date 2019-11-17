/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:23:48 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/17 18:28:59 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_format(char **ptr, va_list args, int *count)
{
	(void)count;
	t_format format;

	get_flags(ptr, &format);
	get_width(ptr, &format, args);
	get_size(ptr, &format, args);
	format.spec = **ptr;
	(*ptr)++;
	print_flags(&format);
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
	printf("width == %d\n", format->width);
	printf("size == %d\n", format->size);
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
	}
	else
		format->width = ft_atoi(ptr);
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
	}
}
