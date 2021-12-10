/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 20:54:33 by ivork         #+#    #+#                 */
/*   Updated: 2021/12/10 20:54:33 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pipex.h>
#include <sys/wait.h>

void	first_process(char **argv, int *pipe_fd, char **envp)
{
	int		fd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_func("open", 1);
	if (close(pipe_fd[0]) == -1)
		err_func("close", 1);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1 || dup2(fd, STDIN_FILENO) == -1)
		err_func("dup2", 1);
	if (close(pipe_fd[1]) == -1 || close(fd) == -1)
		err_func("close", 1);
	argv = ft_split(argv[2], ' ');
	if (access(argv[0], X_OK) == -1)
	{
		path = get_path(envp, argv[0]);
		fd = -1;
	}
	else
		path = argv[0];
	execve(path, argv, NULL);
	free_array(argv);
	if (fd == -1)
		free(path);
	err_func("execve", 127);
}

void	middle_process(char **argv, int *pipe_fd, int read_pipe, char **envp)
{
	char	*path;
	int		free_bool;

	free_bool = 0;
	if (close(pipe_fd[0]) == -1)
		err_func("close", 1);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1
		|| dup2(read_pipe, STDIN_FILENO) == -1)
		err_func("dup2", 1);
	if (close(pipe_fd[1]) == -1 || close(read_pipe) == -1)
		err_func("close", 1);
	argv = ft_split(argv[0], ' ');
	if (access(argv[0], X_OK) == -1)
	{
		path = get_path(envp, argv[0]);
		free_bool = 1;
	}
	else
		path = argv[0];
	execve(path, argv, NULL);
	free_array(argv);
	if (free_bool == 1)
		free(path);
	err_func("Could not execute execve", 127);
}

void	last_process(char **argv, int argc, int read_pipe, char **envp)
{
	char	*path;
	int		free_bool;

	free_bool = 0;
	if (dup2(read_pipe, STDIN_FILENO) == -1)
		err_func("dup2", 1);
	if (close(read_pipe) == -1)
		err_func("close", 1);
	argv = ft_split(argv[argc - 2], ' ');
	if (access(argv[0], X_OK) == -1)
	{
		path = get_path(envp, argv[0]);
		free_bool = 1;
	}
	else
		path = argv[0];
	execve(path, argv, NULL);
	free_array(argv);
	if (free_bool == 1)
		free(path);
	err_func("Could not execute execve", 127);
}

int	create_processes(char **argv, char **envp, int argc)
{
	t_process	process;
	t_pipes		pipes;
	int			i;

	process.num = argc - 3;
	i = 0;
	while (process.num > i + 1)
	{
		if (pipe(pipes.fd) == -1)
			exit (-1);
		process.id = fork();
		if (process.id == -1)
			exit (-1);
		if (process.id == 0)
		{
			if (i == 0)
				first_process(argv, pipes.fd, envp);
			else
				middle_process(argv + 2 + i, pipes.fd, pipes.read_end, envp);
		}
		pipes.read_end = pipes.fd[0];
		close(pipes.fd[1]);
		i++;
	}
	return (pipes.read_end);
}

int	main(int argc, char **const argv, char **envp)
{
	int	read_pipe;
	int	fd;

	fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		err_func("open", 1);
	if (argc < 5)
		err_func("Amout of arguments is incorrect", 1);
	read_pipe = create_processes(argv, envp, argc);
	while (wait(0) != -1)
		;
	if (dup2(fd, STDOUT_FILENO) == -1)
		err_func("dup2", 1);
	if (close(fd) == -1)
		err_func("close", 1);
	last_process(argv, argc, read_pipe, envp);
	return (0);
}
