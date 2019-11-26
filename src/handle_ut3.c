#include "libftprintf.h"

int		len_nb_hexa(long int n, t_format *format)
{
	int i;
	i = 0;
	if (format->flags[4])
		i += 2;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}
