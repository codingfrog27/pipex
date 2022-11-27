/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/27 15:21:44 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f(void)
{
	fprintf(stderr, "done exec\n");
}

void	exectime(char **pathv1, char *cmd_str, char **envp)
{
	int		i;
	char	**cmd;
	char	**path;

	i = 0;
	atexit(f);
	cmd = ft_split(cmd_str, ' ');
	if (!cmd)
		error_exit("Malloc fail");
	path = cmd_2_path(pathv1, cmd[0]);
	while (path[i])
	{
		if (access(path[i], F_OK | X_OK) == 0)
		{
			execve(path[i], cmd, NULL);
			fprintf(stderr, "exec really failed\n");
		}
		i++;
	}
	error_exit("No command found :s\n");
}

bool	contains_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (true);
		str++;
	}
	return (false);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	int		pipe_fd[2];
	int		infd;
	int		stat_loc = 0;
	pid_t	pid;
	pid_t	pid_2;

	if (argc != 5)
		error_exit("you need to pass 4 args silly!");
	//make <5 if I do bonus
	path = find_path(envp);
	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		error_exit("fork failed\n");
	if (pid == 0)
	{
		close(pipe_fd[READ]);
		infd = open(argv[1], O_RDONLY);
		if (infd == -1)
			error_exit("open failed");
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close(pipe_fd[WRITE]);
		dup2(infd, STDIN_FILENO);
		close(infd);

		exectime(path, argv[2], envp);
	}
	pid_2 = fork();
	if (pid_2 == -1)
		error_exit("fork failed\n");
	if (pid_2 == 0)
	{
		printf("heyy\n");
		close(pipe_fd[WRITE]);
		infd = open(argv[4], O_WRONLY | O_TRUNC);
		if (infd == -1)
			error_exit("open failed");
		dup2(pipe_fd[READ], STDIN_FILENO);
		close(pipe_fd[READ]);
		dup2(infd, STDOUT_FILENO);
		close(infd);
		exectime(path, argv[3], envp);
	}
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	waitpid(pid, &stat_loc, 0);
	waitpid(pid_2, &stat_loc, 0);
}
