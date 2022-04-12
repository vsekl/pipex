/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:10:20 by vjose             #+#    #+#             */
/*   Updated: 2022/01/07 20:11:14 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	int		fd_in;
	int		fd_out;
	char	**cmd_1;
	char	**cmd_2;
	char	**path;
	pid_t	pid;
}	t_pipex;

//errors
void	error_wrong_args(void);
void	ft_error(void);

//libft functions
void	*ft_memcpy(void	*dest, const void	*src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//pipex init
void	init_vars(t_pipex	*pipex, char **argv, char **envp);

#endif