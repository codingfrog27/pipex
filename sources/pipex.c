/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/17 16:05:22 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve("pwd", NULL, NULL);
		ft_printf("exec failed :(\n");
		perror("hey\n");
	}

	waitpid(pid, &status, 0);
	//status can also be NULL
	return (0);
}
