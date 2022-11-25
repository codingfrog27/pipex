/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 18:46:51 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/25 16:29:06 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			if (ft_strlen(envp[i]) < 6)
				error_exit("PATH is unset silly!");
			path = ft_split(&envp[i][5], ':');
			if (!path)
				error_exit("malloc fail (go to jail)");
			return (path);
		}
		i++;
	}
	error_exit("NO PATH VAR FOUND IN ENV");
	return (NULL);
}

static int	ptrarrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**cmd_2_path(char **old_path, char *cmd)
{
	char	**proper_path;
	int		i;

	proper_path = malloc((ptrarrlen(old_path) + 1) * sizeof(char *));
	if (!proper_path)
		error_exit("malloc fail (go to jail)");
	i = 0;
	while (old_path[i])
	{
		proper_path[i] = ft_strjoin(old_path[i], cmd);
		if (!proper_path[i])
			error_exit("malloc fail (go to jail)");
		free(old_path[i]);
		i++;
	}
	free(old_path);
	return (proper_path);
}
