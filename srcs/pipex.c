/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 18:06:55 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/20 18:06:55 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <sys/wait.h>


char	**get_arguments(int arg_count, char **arguments)
{
	char	**arg_vec;
	int		i;

	arg_vec = (char **)malloc(sizeof(char*) * arg_count);
	i = 1;
	while (arguments[i])
	{
		arg_vec[i - 1] =  ft_strdup(arguments[i]);
		i++;
	}
	arg_vec[i] = NULL;
	return(arg_vec);
}

int	main(int argc, char **const	argv)
{
	int		pipe_fd[2];
	char	*cmd;
	char	**arg_vec;


	if (pipe(pipe_fd) == -1)
	{
		perror("An error ocurred with opening the pipe\n");
		return (-1);
	}
	if (fork() == 0)
	{
		// child process
		close(pipe_fd[0]);  //close the read end of the pipe in child process

		dup2(pipe_fd[1], 1);  // send stdout to the pipe
		dup2(pipe_fd[1], 2);  // send stderr to the pipe

		close(pipe_fd[1]);
		arg_vec = get_arguments(argc, argv);
		cmd = "/usr/bin/ls";
		if (execve(cmd, arg_vec, NULL) == -1)
		{
			perror("Could not execute execve\n");
			return (-1);
		}
		printf("Oops, something went wrong\n");
		//TODO: free arg_vec
	}
	else
	{
		// parent process

		char *buffer;
		char ret;

		wait(NULL);
		close(pipe_fd[1]);  // close the write end of the pipe in the parent
		ret  = 1;
		while (ret)
		{
			ret = get_next_line(pipe_fd[0], &buffer);
			printf("%s\n", buffer);
			free(buffer);
		}
		close(pipe_fd[0]);
	}
	return (0);
}