#include <fcntl.h>
#include <pipex.h>
#include <sys/wait.h>

void	first_process(char **argv, int *pipe_fd, char **envp)
{
	int		fd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error occured while opening the infile");
		exit(1);
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	dup2(fd, 0);
	close(pipe_fd[1]);
	close(fd);
	argv = ft_split(argv[2], ' ');
	if (access(argv[0], F_OK) == -1)
		path = get_path(envp, argv[0]);
	else
		path = argv[0];
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
}

void	middle_process(char **argv, int *pipe_fd, int read_pipe, char **envp)
{
	char	*path;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	dup2(read_pipe, 0);
	close(pipe_fd[1]);
	close(read_pipe);
	argv = ft_split(argv[0], ' ');
	if (access(argv[0], F_OK) == -1)
		path = get_path(envp, argv[0]);
	else
		path = argv[0];
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
}

void	last_process(char **argv, int argc, int read_pipe, char **envp)
{
	int		fd;
	char	*path;

	fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("Error while opening file");
		exit(1);
	}
	dup2(read_pipe, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(read_pipe);
	close(fd);
	argv = ft_split(argv[argc - 2], ' ');
	if (access(argv[0], F_OK) == -1)
		path = get_path(envp, argv[0]);
	else
		path = argv[0];
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
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

	if (argc < 5)
	{
		perror("Amout of arguments is incorrect");
		return (1);
	}
	read_pipe = create_processes(argv, envp, argc);
	while (wait(0) != -1)
		;
	last_process(argv, argc, read_pipe, envp);
	return (0);
}
