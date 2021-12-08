/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 19:57:53 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:47:33 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0')
	{
		if (!(is_in_set(s1[start], set)))
			break ;
		start++;
	}
	end = ft_strlen(s1);
	while (end - 1 > start)
	{
		if (!(is_in_set(s1[end - 1], set)))
			break ;
		end--;
	}
	newstr = ft_substr(s1, start, end - start);
	return (newstr);
}
