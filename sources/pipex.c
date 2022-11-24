/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/24 19:57:54 by mde-cloe      ########   odam.nl         */
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
	path = cmd_2_path(pathv1, cmd_str);
	while (path[i])
	{
		if (access(path[i], F_OK))
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
	pid_t	pid;

	// if (argc != 5)
	// 	error_exit("you need to pass 4 args silly!");
	//make <5 if I do bonus
	path = find_path(envp);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		infd = open(argv[1], O_RDONLY);
		if (infd == -1)
			error_exit("open failed");
		dup2(infd, 1);
		exectime(path, argv[2], envp);
	}
}
