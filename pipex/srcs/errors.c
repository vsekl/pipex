/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:16 by vjose             #+#    #+#             */
/*   Updated: 2022/01/07 19:52:32 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_wrong_args(void)
{
	write(2, "Error: Invalid number of arguments\n", 35);
	exit(1);
}

void	ft_error(void)
{
	perror("Error");
	exit(1);
}
