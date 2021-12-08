/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 23:10:02 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:44:22 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

extern int	g_count;

char	*ft_conv_hexa(unsigned int x, char *base, char *str)
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
	n = 0;
	while (i > 0)
	{
		str[n] = hexadecinum[i - 1];
		n++;
		i--;
	}
	str[n] = '\0';
	return (str);
}

void	ft_print_hexa(unsigned int x, t_flags flag)
{
	char	*base;
	char	*str;

	if (flag.preci == true && flag.precision >= 0)
		flag.zero = false;
	if (flag.specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str = (char *)malloc(sizeof(char) * 9);
	if (str == NULL)
	{
		g_count = -1;
		return ;
	}
	str = ft_conv_hexa(x, base, str);
	if (x == 0 && (flag.preci == false || flag.precision < 0))
		ft_print_pos("0", flag);
	else
		ft_print_pos(str, flag);
	free(str);
}

void	ft_print_unsi(long long x, t_flags flag)
{
	char	*str;

	if (flag.preci == true && flag.precision >= 0)
		flag.zero = false;
	if (x == 0 && flag.preci == true && flag.precision == 0)
		str = 0;
	else
	{
		str = ft_uitoa(x);
		if (str == NULL)
		{
			g_count = -1;
			return ;
		}
	}
	ft_print_pos(str, flag);
	free(str);
}

void	ft_conv_str(int x, t_flags flag)
{
	char	*str;

	if (x == 0 && flag.preci == true && flag.precision == 0)
		str = NULL;
	else
	{
		str = ft_itoa(x);
		if (str == NULL)
		{
			g_count = -1;
			return ;
		}
	}
	ft_print_pos(str, flag);
	free(str);
}

void	ft_print_int(int x, t_flags flag)
{
	char	*str;

	if ((flag.preci == true && flag.precision >= 0) || flag.left_align == true)
		flag.zero = false;
	if (x >= 0)
		ft_conv_str(x, flag);
	else
	{
		x *= -1;
		str = ft_uitoa(x);
		if (str == NULL)
		{
			g_count = -1;
			return ;
		}
		else
			ft_print_neg(str, flag);
		free(str);
	}
}
