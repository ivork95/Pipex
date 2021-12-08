/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_pos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 23:11:44 by ivork         #+#    #+#                 */
/*   Updated: 2021/02/12 10:42:55 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

extern int	g_count;

void	ft_fill_width(char *str, t_flags flag)
{
	int	len;

	len = 0;
	if (str != NULL)
		len = (int)ft_strlen(str);
	if (flag.left_align == false)
	{
		while (flag.width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			g_count++;
			flag.width--;
		}
	}
	ft_putstr_fd(str, 1);
	g_count += len;
	if (flag.left_align == true)
	{
		while (flag.width - len > 0)
		{
			ft_putchar_fd(' ', 1);
			g_count++;
			flag.width--;
		}
	}
}

void	ft_fill_preci(char *str, t_flags flag)
{
	int	len;

	if (str == NULL)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (flag.width != 0)
		flag.precision = flag.width;
	while (flag.precision - len > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		flag.precision--;
	}
	ft_putstr_fd(str, 1);
	g_count += len;
	flag.precision = 0;
}

void	ft_fill_both(char *str, t_flags flag)
{
	int	len;

	if (str == NULL)
		len = 0;
	else
		len = (int)ft_strlen(str);
	while ((flag.width - flag.precision > 0)
		&& (flag.width - len > 0))
	{
		ft_putchar_fd(' ', 1);
		g_count++;
		flag.width--;
	}
	while (flag.precision - len > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		flag.precision--;
	}
	ft_putstr_fd(str, 1);
	g_count += len;
}

void	ft_fill_both_left(char *str, t_flags flag)
{
	int	count;
	int	len;

	if (str == NULL)
		len = 0;
	else
		len = (int)ft_strlen(str);
	count = 0;
	while (flag.precision - len + count > 0)
	{
		ft_putchar_fd('0', 1);
		g_count++;
		count--;
	}
	ft_putstr_fd(str, 1);
	g_count += len;
	while ((flag.width - flag.precision > 0)
		&& (flag.width - len > 0))
	{
		ft_putchar_fd(' ', 1);
		g_count++;
		flag.width--;
	}
}

void	ft_print_pos(char *str, t_flags flag)
{
	if (flag.width == 0 && flag.preci == false && flag.zero == false)
	{
		ft_putstr_fd(str, 1);
		g_count += (int)ft_strlen(str);
	}
	if (flag.width != 0 && flag.zero == false && flag.preci == false)
		ft_fill_width(str, flag);
	if ((flag.preci == true && flag.width == 0) || (flag.zero == true))
	{
		ft_fill_preci(str, flag);
		return ;
	}
	if (flag.width != 0 && flag.preci == true)
	{
		if (flag.left_align == false)
			ft_fill_both(str, flag);
		else
			ft_fill_both_left(str, flag);
	}
}
