/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ut2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:02:46 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/22 16:09:05 by vgoldman         ###   ########.fr       */
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

void	ft_putnbr(long long nb, int *count)
{
	long long a;

	a = nb;
	if (a < 0)
		a = a * (-1);
	if (a > 9)
	{
		ft_putnbr(a / 10, count);
		ft_putnchar(a % 10 + '0', 1, count);
	}
	else
		ft_putnchar(a + '0', 1, count);
}

int		len_nb(long long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}
