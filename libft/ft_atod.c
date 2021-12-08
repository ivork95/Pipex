/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 17:39:30 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:40:15 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static double	get_decimal(char *str)
{
	int		i;
	int		decimal;
	double	y;

	i = 1;
	y = 0;
	decimal = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		y = y * 10 + str[i] - '0';
		i++;
		decimal *= 10;
	}
	y = y / decimal;
	return (y);
}

double	ft_atod(const char *str)
{
	int		i;
	int		count_min;
	double	x;

	i = 0;
	count_min = 0;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		count_min++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		x += get_decimal((char *)str + i);
	if (count_min % 2 != 0)
		return (-x);
	return (x);
}
