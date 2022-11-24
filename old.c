/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   old.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 16:47:59 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/24 16:48:27 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	int		status;
	pid_t	pid;
	char	*hey[] = {"ls", "-l", NULL};
	int		fd[2];
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		sleep(1);
		write(fd[1], "hoi:)\n", 6);
		close(fd[1]);
		// execve("/bin/ls", hey, envp);
		// ft_printf("exec failed :(\n");
		// perror("\nerror");
	}
	else
	{
		char swag[10];
		close(fd[1]);
		waitpid(pid, &status, 0);
		read(fd[0], swag, 6);
		ft_printf("%s", swag);
		close(fd[0]);
	}
	(void)argc;
	(void)argv;
	(void)envp;
	(void)hey;
	//status can also be NULL
	return (0);
}


// for exec we need to split the path and the command name

//usage: pwd [-L | -P]

int	main(int argc, char **argv, char **envp)
{
	char	*hey[] = {"ls", "-l", NULL};
	int 	fd = open("test.txt", O_RDWR);
	ft_printf("%s", envp[8]);
	dup2(fd, 1);
	execve("/bin/ls", hey, envp);
	// ft_printf("swaggy");

	(void)argc;
	(void)argv;
	(void)envp;
	(void)hey;
}