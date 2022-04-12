/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:46:48 by vjose             #+#    #+#             */
/*   Updated: 2021/12/29 17:46:48 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup("\0"));
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		str = ft_memcpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
