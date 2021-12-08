/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:10:54 by ivork         #+#    #+#                 */
/*   Updated: 2020/11/08 21:25:43 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*target;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	target = malloc(sizeof(*str) * len + 1);
	if (target == 0)
		return (NULL);
	while (str[i] != 0)
	{
		target[i] = str[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
