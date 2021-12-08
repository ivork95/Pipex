/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:10:30 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:49:00 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (n == 0)
		return (srclen);
	if (dstlen > n)
		return (srclen + n);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (n - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dstlen + srclen);
}
