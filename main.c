/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:38:41 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/18 12:47:08 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	/*printf("|%*s|\n", 5, "Salut !");
	printf("|%*s|\n", -5, "Salut !");
	printf("|%*.*s|\n", 5, 10, "Salut !");
	printf("|%*.*s|\n", 5, -10, "Salut !");
	printf("|%*.*s|\n", -5, -10, "Salut !");
	printf("|%*.*s|\n", -5, 10, "Salut !");
	printf("|%*.*s|\n", -20, 2, "Salut !");
	printf("|%-*.*s|\n", 20, 5, "Salut !");
	printf("|%-*.*s|\n", -20, 5, "Salut !");
	printf("|%-*.*s|\n", 20, 2, NULL);
	printf("|%*.*s|\n", 0, 0, NULL);
	printf("|%*.*s|\n", 0, 10, NULL);
	printf("|%*.*s|\n", 10, 0, "hello");*/
	ft_printf("|%*c|\n", -10, 'f');
	printf("|%*c|\n", -10, 'f');
	return (0);
}
