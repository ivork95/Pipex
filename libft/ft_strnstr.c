/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:08:12 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:48:17 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)src);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] && src[i + j] == to_find[j] && i + j < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}
