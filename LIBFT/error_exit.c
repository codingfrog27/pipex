/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 18:44:53 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/29 21:20:35 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	error_exit(char *str, int err_nbr)
{
	perror(str);
	exit(err_nbr);
}
