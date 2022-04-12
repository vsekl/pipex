/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:44:45 by vjose             #+#    #+#             */
/*   Updated: 2021/12/29 17:44:45 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 1;
	while (*s != 0)
	{
		if (*s == c)
			flag = 1;
		while (*s == c)
			s++;
		if (*s != 0 && flag == 1)
		{
			counter++;
			flag = 0;
		}
		while (*s != c && *s != 0)
			s++;
	}
	return (counter);
}

static void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i + j] != '\0' && s[i + j] != c)
			j++;
		if (j != 0)
		{
			tab[k] = ft_substr(s, i, j);
			if (tab[k] == NULL)
			{
				ft_free(tab);
				break ;
			}
			k++;
		}
		i = i + j;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words_size;
	char	**tab;

	if (s == NULL)
		return (NULL);
	words_size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (words_size + 1));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(tab, s, c);
	if (tab != NULL)
		tab[words_size] = NULL;
	return (tab);
}
