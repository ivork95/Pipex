/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:51:26 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 19:54:33 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned long	x;

	x = n;
	i = 0;
	if (!src && !dest)
		return (0);
	if (dest > src)
	{
		while (x > 0)
		{
			((char *)dest)[x - 1] = ((const char *)src)[x - 1];
			x--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}
