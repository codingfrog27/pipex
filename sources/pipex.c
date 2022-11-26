/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/26 17:23:40 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exectime(char **pathv1, char *cmd_str, char **envp)
{
	int		i;
	char	**cmd;
	char	**path;

	i = 0;
	cmd = ft_split(cmd_str, ' ');
	if (!cmd)
		error_exit("Malloc fail");
	path = cmd_2_path(pathv1, cmd[0]);
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
			execve(path[i], cmd, envp);
		i++;
	}
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

	if (argc != 5)
		error_exit("you need to pass 4 args silly!");
	//make <5 if I do bonus
	path = find_path(envp);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[READ]);
		infd = open(argv[1], O_RDWR);
		if (infd == -1)
			error_exit("open failed");
		dup2(pipe_fd[WRITE], 1);
		dup2(infd, 0);
		exectime(path, argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[WRITE]);
		infd = open(argv[4], O_RDWR);
		if (infd == -1)
			error_exit("open failed");
		dup2(pipe_fd[READ], 0);
		dup2(infd, 1);
		exectime(path, argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
}
