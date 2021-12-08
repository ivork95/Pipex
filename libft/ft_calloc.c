/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:00:49 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:53:18 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*mem;

	mem = (char *)malloc(nitems * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, (nitems * size));
	return (mem);
}
