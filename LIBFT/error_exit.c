/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 18:44:53 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/11/24 18:45:23 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
