/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 18:44:53 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/29 18:30:03 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errno.h"
#include <stdio.h>

void	error_exit(char *str)
{
	perror(str);
	exit(errno);
}
