#include <fcntl.h>
#include <pipex.h>
#include <sys/wait.h>

void first_process(char **argv, int *pipe_fd, char **envp)
{
	int fd;
	char *path;

	printf("we are now in the first proces\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error occured while opening the infile");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	printf("argv first = %s\n", argv[2]);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	dup2(fd, 0);
	argv = ft_split(argv[2], ' ');
	path = get_path(envp, argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
	close(pipe_fd[1]);
	close(fd);
}

void middle_process(char **argv, int *pipe_fd1, int *pipe_fd2, char **envp)
{
	char *path;

	printf("we are now in the middle proces\n");
	printf("argv = %s\n", argv[3]);
	close(pipe_fd1[1]);
	close(pipe_fd2[0]);
	dup2(pipe_fd1[0], 0);
	dup2(pipe_fd2[1], 1);
	argv = ft_split(argv[3], ' ');
	path = get_path(envp, argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
	close(pipe_fd1[0]);
	close(pipe_fd2[1]);
}

void last_process(char **argv, int *pipe_fd, char **envp)
{
	int fd;
	char *path;

	printf("we are now in the last proces\n");

	fd = open(argv[5], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("Error while opening file");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	printf("argv = %s\n", argv[4]);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(fd, 1);
	argv = ft_split(argv[4], ' ');
	path = get_path(envp, argv[0]);
	if (execve(path, argv, NULL) == -1)
	{
		perror("Could not execute execve");
		exit(127);
	}
	close(pipe_fd[0]);
}

int main(int argc, char **const argv, char **envp)
{
	int pipe_fd[2][2];
	int pid;
	int processes;
	int i;

	if (argc < 5)
	{
		perror("Amout of arguments is incorrect");
		return (1);
	}
	processes = argc - 3;
	if (pipe(pipe_fd[0]) == -1)
	{
		perror("An error ocurred while opening the pipe");
		return (-1);
	}
	if (pipe(pipe_fd[1]) == -1)
	{
		perror("An error ocurred while opening the pipe");
		return (-1);
	}
	i = 0;
	while (processes > i + 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("An error accured whit the fork");
			return (-1);
		}
		if (pid == 0)
		{
			if (i == 0)
				first_process(argv, pipe_fd[i], envp);
			else
				middle_process(argv, pipe_fd[i - 1], pipe_fd[i], envp);
			break;
		}
		wait(0);
		i++;
	}
	if (pid != 0)
	{
		last_process(argv, pipe_fd[i - 1], envp);
	}
	return (0);
}
