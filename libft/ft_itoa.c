/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:04:16 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:53:08 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_convnum(char *s, int n, int x)
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

char	*ft_itoa(int n)
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
