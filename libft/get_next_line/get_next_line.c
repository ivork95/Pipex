/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:27:02 by anonymous     #+#    #+#                 */
/*   Updated: 2021/10/12 17:41:24 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_read(int fd, char *buff, int ret)
{
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	while (ret)
	{
		if (!*buff)
			ret = ft_read(fd, buff, ret);
		if (ret < 0)
			return (-1);
		*line = ft_strcjoin(*line, buff);
		if (*line == NULL)
			return (-1);
		if (ft_strmove(buff, buff + (ft_strichr(buff, '\n'))))
			return (1);
		ft_bzero(buff, BUFFER_SIZE);
	}
	return (0);
}
