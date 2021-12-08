/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 21:11:29 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:50:11 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	**ft_fill_in(char **array, const char *s, char c, int splits)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (splits)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		array[k] = ft_substr(s, j, (i - j));
		if (array[k] == NULL)
		{
			ft_free_array(array, (k + 1));
			return (NULL);
		}
		k++;
		splits--;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (!s)
		return (0);
	words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * words + 1);
	if (arr == NULL)
		return (NULL);
	arr[words] = NULL;
	return (ft_fill_in(arr, s, c, words));
}
