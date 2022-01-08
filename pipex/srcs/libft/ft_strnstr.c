/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:44:23 by vjose             #+#    #+#             */
/*   Updated: 2021/12/29 17:44:23 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big[i] != '\0' && little[j] == '\0' && len == 0)
		return ((char *)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] != '\0' && i + j < len && little[j] == big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	if (little[j] == 0)
		return ((char *)&big[i]);
	else
		return (NULL);
}
