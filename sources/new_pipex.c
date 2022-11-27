/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_pipex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:00:44 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/27 16:34:56 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


typedef struct s_struct_x
{
	int	i;
}	t_struct_x;

void	baby_process(char **argv, char **envp, bool is_write_child)
{

	if (is_write_child)
		somehting;

}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		error_exit("not enough arguments\n");

}
