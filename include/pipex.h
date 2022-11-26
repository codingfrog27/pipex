/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:19:09 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/26 17:03:53 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# include <fcntl.h>

# define READ 0
# define WRITE 1

char	**find_path(char **envp);
char	**cmd_2_path(char **old_path, char *cmd);

#endif // !PIPEX_H