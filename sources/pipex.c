/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:00:44 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/29 17:49:26 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_and_exec(char **cmd, char **envp)
{
	char	**path;

	if (ft_strchr(*cmd, ' '))
		cmd = ft_split(*cmd, ' ');
	if (!cmd)
		error_exit("malloc fail\n");
	if (access(*cmd, F_OK | X_OK) == 0)
	{
		execve(*cmd, cmd, envp);
		error_exit("exec fail\n");
	}
	path = find_path(envp, *cmd);
	while (path)
	{
		if (access(*path, F_OK | X_OK) == 0)
		{
			execve(*path, cmd, envp);
			error_exit("exec fail");
		}
		path++;
	}
	error_exit("No executable found");
}

void	baby_1(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		error_exit("can't open infile\n");
	if (dup2(pipe_fd[WRITE], 1) == -1 || dup2(file_fd, 0) == -1)
		error_exit("dup2 fail\n");
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	close(file_fd);
	find_and_exec(&argv[2], envp);
}

void	baby_2(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[4], O_WRONLY);
	if (file_fd == -1)
		error_exit("can't open infile\n");
	if (dup2(pipe_fd[READ], 0) == -1 || dup2(file_fd, 1) == -1)
		error_exit("dup2 fail\n");
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
	close(file_fd);
	find_and_exec(&argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		stat_loc;

	if (argc != 5)
		error_exit("wrong nr of arguments\n");
	if (pipe(pipe_fd) == -1)
		error_exit("pipe failed\n");
	pid_1 = fork();
	if (pid_1 == -1)
		error_exit("fork failed\n");
	else if (pid_1 == 0)
		baby_1(argv, envp, pipe_fd);
	pid_2 = fork();
	if (pid_2 == -1)
		error_exit("fork failed\n");
	else if (pid_2 == 0)
		baby_2(argv, envp, pipe_fd);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	waitpid(pid_1, &stat_loc, 0);
	waitpid(pid_2, &stat_loc, 0);
	return (errno);
}
