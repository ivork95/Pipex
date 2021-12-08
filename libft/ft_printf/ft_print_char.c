/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 22:44:26 by ivork         #+#    #+#                 */
/*   Updated: 2021/02/14 14:10:38 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_count;

void	ft_print_str(char *str, t_flags flag)
{
	int	width;
	int	preci;

	width = flag.width;
	preci = flag.precision;
	if (str == NULL)
		str = "(null)";
	if (flag.preci == false || preci > (int)ft_strlen(str) || preci < 0)
		preci = ft_strlen(str);
	if (flag.left_align == true)
		ft_putnstr_fd(str, 1, preci);
	while ((width - preci) > 0)
	{
		ft_putchar_fd(' ', 1);
		g_count++;
		width--;
	}
	if (flag.left_align == false)
		ft_putnstr_fd(str, 1, preci);
	g_count += preci;
}

void	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = flags.width;
	if (flags.left_align == true)
	{
		ft_putchar_fd(c, 1);
		g_count++;
	}
	while (count - 1 > 0)
	{
		if (flags.zero == true && flags.left_align == false)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		count--;
		g_count++;
	}
	if (flags.left_align == false)
	{
		ft_putchar_fd(c, 1);
		g_count++;
	}
}
