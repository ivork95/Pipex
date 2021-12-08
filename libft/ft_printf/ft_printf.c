/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 22:39:26 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:43:25 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count;

t_flags	ft_fill_flag(const char *str, int i, t_flags flag, va_list ap)
{
	if (str[i] == ' ')
	{
		ft_putchar_fd(' ', 1);
		g_count++;
	}
	else if (str[i] == '-')
		flag.left_align = true;
	else if (str[i] == '0' && !(ft_isdigit(str[i - 1])))
		flag.zero = true;
	else if (str[i] == '*' && str[i - 1] != '.')
		flag.width = va_arg(ap, int);
	else if (ft_isdigit(str[i]) && flag.width == 0 && flag.precision == 0)
		flag.width = ft_atoi(&str[i]);
	else if (str[i] == '.')
	{
		flag.preci = true;
		if (str[i + 1] == '*')
			flag.precision = va_arg(ap, int);
		else if (flag.precision == 0)
			flag.precision = ft_atoi(&str[i + 1]);
	}
	return (flag);
}

void	ft_check_speci(t_flags flag, va_list ap)
{
	if (flag.specifier == '%')
		ft_print_char('%', flag);
	else if (flag.specifier == 'c')
		ft_print_char(va_arg(ap, int), flag);
	else if (flag.specifier == 's')
		ft_print_str(va_arg(ap, char *), flag);
	else if ((flag.specifier == 'i') || (flag.specifier == 'd'))
		ft_print_int(va_arg(ap, int), flag);
	else if (flag.specifier == 'u')
		ft_print_unsi(va_arg(ap, unsigned int), flag);
	else if ((flag.specifier == 'x') || (flag.specifier == 'X'))
		ft_print_hexa(va_arg(ap, unsigned int), flag);
	else if (flag.specifier == 'p')
		ft_print_point(va_arg(ap, unsigned long long), flag);
}

int	ft_check_flags(const char *str, int i, va_list ap)
{
	t_flags	flag;

	flag = ft_init_flag();
	while (!(ft_isalpha(str[i])) && (str[i] != '%'))
	{
		flag = ft_fill_flag(str, i, flag, ap);
		i++;
	}
	if (flag.width < 0)
	{
		flag.width *= -1;
		flag.left_align = true;
	}
	flag.specifier = str[i];
	ft_check_speci(flag, ap);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	g_count = 0;
	va_start(ap, str);
	while (str[i] != '\0' && g_count != -1)
	{
		if (str[i] == '%')
		{
			i++;
			i = ft_check_flags(str, i, ap);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			g_count++;
		}
		i++;
	}
	va_end(ap);
	return (g_count);
}
