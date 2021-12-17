/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:26:26 by ivork         #+#    #+#                 */
/*   Updated: 2021/12/17 18:12:40 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdio.h>

void	err_func(char *str, int code)
{
	perror(str);
	exit(code);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	return ;
}

char	*get_path(char **arguments, char *cmd)
{
	char	*path;
	char	*full_path;
	int		i;

	while (*arguments)
	{
		if (ft_strncmp(*arguments, "PATH=", 5) == 0)
			path = ft_strdup(*arguments);
		arguments++;
	}
	arguments = ft_split(path, ':');
	free(path);
	i = 0;
	path = ft_strjoin("/", cmd);
	while (arguments[i])
	{
		full_path = ft_strjoin(arguments[i], path);
		if (access(full_path, F_OK) == 0)
			break ;
		free(full_path);
		i++;
	}
	free_array(arguments);
	free(path);
	return (full_path);
}
