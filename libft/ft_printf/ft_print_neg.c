/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_neg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 23:45:07 by ivork         #+#    #+#                 */
/*   Updated: 2021/02/12 10:40:07 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

extern int	g_count;

void	ft_min_width(char *str, t_flags flag)
{
	if (flag.left_align == false)
	{
		while (flag.width - (int)ft_strlen(str) > 0)
		{
			ft_putchar_fd(' ', 1);
			g_count++;
			flag.width--;
		}
	}
	ft_putchar_fd('-', 1);
	g_count++;
	ft_putstr_fd(str, 1);
	g_count += (int)ft_strlen(str);
	if (flag.left_align == true)
	{
		while (flag.width - (int)ft_strlen(str) > 0)
		{
			ft_putchar_fd(' ', 1);
			g_count++;
			flag.width--;
		}
	}
}

void	ft_min_preci(char *str, t_flags flag)
{
	if (flag.width != 0)
		flag.precision = flag.width;
	ft_putchar_fd('-', 1);
	g_count++;
	while (flag.precision - (int)ft_strlen(str) > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		flag.precision--;
	}
	ft_putstr_fd(str, 1);
	g_count += (int)ft_strlen(str);
	flag.precision = 0;
}

void	ft_min_both(char *str, t_flags flag)
{
	while ((flag.width - flag.precision > 0)
		&& (flag.width - (int)ft_strlen(str) > 0))
	{
		ft_putchar_fd(' ', 1);
		g_count++;
		flag.width--;
	}
	ft_putchar_fd('-', 1);
	g_count++;
	while (flag.precision - (int)ft_strlen(str) > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		flag.precision--;
	}
	ft_putstr_fd(str, 1);
	g_count += (int)ft_strlen(str);
}

void	ft_min_both_left(char *str, t_flags flag)
{
	int	count;

	count = 0;
	ft_putchar_fd('-', 1);
	g_count++;
	while (flag.precision - (int)ft_strlen(str) + count > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		count--;
	}
	ft_putstr_fd(str, 1);
	g_count += (int)ft_strlen(str);
	while ((flag.width - flag.precision > 0)
		&& (flag.width - (int)ft_strlen(str) > 0))
	{
		ft_putchar_fd(' ', 1);
		g_count++;
		flag.width--;
	}
}

void	ft_print_neg(char *str, t_flags flag)
{
	if (flag.width > (int)ft_strlen(str))
		flag.width--;
	if (flag.width == 0 && flag.precision == 0 && flag.zero == false)
	{
		ft_putchar_fd('-', 1);
		g_count++;
		ft_putstr_fd(str, 1);
		g_count += (int)ft_strlen(str);
	}
	if (flag.width != 0 && flag.zero == false && flag.precision == 0)
		ft_min_width(str, flag);
	if ((flag.precision != 0 && flag.width == 0) || (flag.zero == true))
	{
		ft_min_preci(str, flag);
		return ;
	}
	if (flag.width != 0 && flag.precision != 0)
	{
		if (flag.left_align == false)
			ft_min_both(str, flag);
		if (flag.left_align == true)
			ft_min_both_left(str, flag);
	}
}
