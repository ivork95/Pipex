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

#include <fcntl.h>
#include <pipex.h>
#include <sys/wait.h>

void	child_process(char **argv, int *pipe_fd, char **envp)
{
	int		fd;
	char	*path;

	fd = open(argv[1], O_RDONLY) ;
	if (fd == -1)
	{
		perror("Error occured while opening the infile");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit (1);
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	dup2(fd, 0);

	argv = ft_split(argv[2], ' ');
	path = get_path(envp, argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve\n");
		exit (127);
	}
	close(pipe_fd[0]);
	close(fd);
}

void	parrent_process(char **argv, int *pipe_fd, char **envp)
{
	int		fd;
	char	*path;

	wait(0);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("Error while opening file");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit (1);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(fd, 1);
	argv = ft_split(argv[3], ' ');
	path = get_path(envp, argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve\n");
		exit (127);
	}
	close(pipe_fd[0]);
	close(fd);
}

int	main(int argc, char **const	argv, char **envp)
{
	int		pipe_fd[2];
	int		pid;

	if (argc != 5)
	{
		perror("Amout of arguments is incorrect\n");
		return (1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("An error ocurred while opening the pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("An error accured whit the fork");
		return (-1);
	}
	if (pid == 0)
		child_process(argv, pipe_fd, envp);
	else
		parrent_process(argv, pipe_fd, envp);
	return (0);
}
