/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:18:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/23 22:05:08 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	int		status;
// 	pid_t	pid;
// 	char	*hey[] = {"ls", "-l", NULL};
// 	int		fd[2];
// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		sleep(1);
// 		write(fd[1], "hoi:)\n", 6);
// 		close(fd[1]);
// 		// execve("/bin/ls", hey, envp);
// 		// ft_printf("exec failed :(\n");
// 		// perror("\nerror");
// 	}
// 	else
// 	{
// 		char swag[10];
// 		close(fd[1]);
// 		waitpid(pid, &status, 0);
// 		read(fd[0], swag, 6);
// 		ft_printf("%s", swag);
// 		close(fd[0]);
// 	}
// 	(void)argc;
// 	(void)argv;
// 	(void)envp;
// 	(void)hey;
// 	//status can also be NULL
// 	return (0);
// }


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

void error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

char	**find_path(char **envp, char *cmd_name)
{
	int		i;
	char	*path_line;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			if (ft_strlen(envp[i]) < 6)
				error_exit("PATH is unset silly!");
			path_line = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			path = ft_split(path_line, ':');
			free(path_line);
			return (path);
		}
		i++;
	}
	error_exit("NO PATH VAR FOUND IN ENV");
	return (NULL);
}

int	ptrarrlen(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**proper_path(char **old_path, char *cmd)
{
	char	**proper_path;
	int		i;

	proper_path = malloc(ptrarrlen(old_path) * sizeof(char *));
	i = 0;
	while (old_path[i])
	{
		proper_path[i] = ft_strjoin(old_path[i], cmd);
		free(old_path[i]);
		i++;
	}
	free(old_path);
	return(proper_path);
}

//could split function up more into 1 find envp index



//so this way is a little slower actually than making our own custom
// 1 remove PATH=, 2 splitting on every colon to make char** while also adding
//cmd name to all of them. Now we do that seperately and re_alloc