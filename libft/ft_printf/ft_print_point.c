/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_point.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 13:43:19 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:44:09 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

extern int	g_count;

char	*ft_conv_point(unsigned long long x, char *base, char *str)
{
	char	hexadecinum[100];
	int		i;
	int		n;

	i = 0;
	while (x != 0)
	{
		n = x % 16;
		hexadecinum[i] = base[n];
		x /= 16;
		i++;
	}
	str[0] = '0';
	str[1] = 'x';
	n = 2;
	while (i > 0)
	{
		str[n] = hexadecinum[i - 1];
		n++;
		i--;
	}
	str[n] = '\0';
	return (str);
}

void	ft_print_point(unsigned long long x, t_flags flag)
{
	char	*base;
	char	*str;

	base = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * 11);
	if (str == NULL)
	{
		g_count = -1;
		return ;
	}
	str = ft_conv_point(x, base, str);
	if (x == 0 && (flag.preci == false || flag.precision < 0))
		ft_print_pos("0x0", flag);
	else
		ft_print_pos(str, flag);
	free(str);
}
