/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:13:08 by vjose             #+#    #+#             */
/*   Updated: 2022/01/08 16:57:56 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	init_path(t_pipex	*pipex, char **envp)
{
	int		i;
	char	*tmp;
	char	*ptr;

	i = 0;
	while (envp[i] != NULL)
	{
		ptr = ft_strnstr(envp[i], "PATH", 4);
		if (ptr != NULL)
			break ;
		i++;
	}
	ptr = ptr + 5;
	pipex->path = ft_split(ptr, ':');
	if (pipex->path == NULL)
		ft_error();
	i = 0;
	while (pipex->path[i] != NULL)
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		free(pipex->path[i]);
		pipex->path[i] = tmp;
		i++;
	}
}

static void	init_files(t_pipex	*pipex, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	pipex->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (pipex->fd_in == -1 || pipex->fd_out == -1)
		ft_error();
}

static void	init_cmds(t_pipex	*pipex, char **argv)
{
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	if (pipex->cmd_1 == NULL || pipex->cmd_2 == NULL)
		ft_error();
}

void	init_vars(t_pipex	*pipex, char **argv, char **envp)
{
	if (pipe(pipex->fd) == -1)
		ft_error();
	init_path(pipex, envp);
	init_files(pipex, argv);
	init_cmds(pipex, argv);
}
