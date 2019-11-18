/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ut2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:02:46 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/18 13:18:12 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnstr(char *str, int n, int *count)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnchar(*(str++), 1, count);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
	{
		i++;
	}
	return (i);
}
