/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/22 18:21:05 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int			status;
	pid_t		pid;
	char	**argv = {"pwd", "-L"};

	pid = fork();
	if (pid == 0)
	{
		execve("/bin/pwd", argv, NULL);
		ft_printf("exec failed :(\n");
		perror("error =");
	}

	waitpid(pid, &status, 0);
	//status can also be NULL
	return (0);
}


// for exec we need to split the path and the command name

//usage: pwd [-L | -P]