#include "libftprintf.h"

void	ft_hexa(long int i, t_format *format, int *count, char *str)
{
	int fill_spaces;
	int fill_zero;

	fill_spaces = 0;
	fill_zero = 0;
	ft_hexa_help(i, format, &fill_spaces, &fill_zero);
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
		ft_putnbr_hexa(i, count, str);
	if (format->flags[0])
		ft_putnchar(' ', fill_spaces, count);
}

void	ft_hexa_help(long int i, t_format *format, int *fill_spaces, int *fill_zero)
{
	if ((format->size == 0 && format->s_check && i == 0)
		|| (format->s_check && format->size > 0)
			|| (format->width < 0 && format->size < 0))
		format->flags[1] = 0;
	if (format->width < 0)
		format->flags[0] = 1;
	if (format->size > len_nb(i)
		|| (format->flags[1] && format->s_check))
		*fill_zero = ft_abs(format->size) - len_nb(i) + (i < 0);
	else if (format->flags[1] && format->width > 0)
		*fill_zero = ft_abs(format->width) - len_nb(i);
	if (ft_abs(format->width) > len_nb(i) + *fill_zero)
		*fill_spaces = ft_abs(format->width) - len_nb(i) - *fill_zero;
	if (format->size == 0 && format->s_check && i == 0 && *fill_spaces)
	{
		format->flags[1] = 0;
		(*fill_spaces)++;
	}
}
