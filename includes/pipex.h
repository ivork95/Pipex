/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 16:33:01 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/25 13:52:43 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <libft.h>

typedef struct s_pipes
{
	int	fd[2];
	int	read_end;
}		t_pipes;

typedef struct s_process
{
	int	num;
	int	id;
}		t_process;

char	*get_path(char **arguments, char *cmd);
void	free_array(char **array);
void	err_func(char *str, int code);
#endif
