/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:26:26 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/25 12:08:01 by ivork         ########   odam.nl         */
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
	free(array);
	return ;
}

char	*get_path(char **arguments, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (arguments[i])
	{
		if (ft_strncmp(arguments[i], "PATH=", 5) == 0)
			path = ft_strdup(arguments[i]);
		i++;
	}
	arguments = ft_split(path, ':');
	free(path);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (arguments[i])
	{	
		arguments[i] = ft_strjoin(arguments[i], cmd);
		if (access(arguments[i], F_OK) == 0)
			path = ft_strdup(arguments[i]);
		i++;
	}
	free_array(arguments);
	free(cmd);
	return (path);
}
