/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 22:52:08 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:42:37 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_putnstr_fd(char *s, int fd, int n)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0' && n > 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
		n--;
	}
}

static char	*ft_convnum(char *s, long long int n, int x)
{
	int	i;

	i = 0;
	if (n == 0)
		s[0] = '0';
	if (n == -2147483648)
	{
		s[i + 1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		n *= -1;
		s[i] = '-';
	}
	i = i + x - 1;
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[x] = '\0';
	return (s);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned long	x;
	int				count;
	char			*str;

	x = (unsigned long)n;
	count = 0;
	if (n <= 0)
	{
		x *= -1;
		count++;
	}
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	str = malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (str);
	return (ft_convnum(str, n, count));
}

t_flags	ft_init_flag(void)
{
	t_flags	flag;

	flag.width = 0;
	flag.precision = 0;
	flag.count = 0;
	flag.left_align = false;
	flag.zero = false;
	flag.preci = false;
	return (flag);
}
