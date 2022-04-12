/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:09:42 by vjose             #+#    #+#             */
/*   Updated: 2022/04/12 19:32:50 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	command_not_found(char *command)
{
	write(2, "zsh: command not found: ", 24);
	write(2, command, ft_strlen(command));
	write(2, "\n", 1);
}

static void	cmd_1(t_pipex	*pipex, char **envp)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (access(pipex->cmd_1[0], X_OK) == 0)
	{
		execve(pipex->cmd_1[0], pipex->cmd_1, envp);
		return ;
	}
	while (pipex->path[i] != NULL)
	{
		cmd_path = ft_strjoin(pipex->path[i], pipex->cmd_1[0]);
		if (access(cmd_path, X_OK) == 0)
			break ;
		i++;
		free(cmd_path);
	}
	if (pipex->path[i] != NULL)
	{
		execve(cmd_path, pipex->cmd_1, envp);
		free(cmd_path);
	}
	else
		command_not_found(pipex->cmd_1[0]);
}

static void	cmd_2(t_pipex	*pipex, char **envp)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (access(pipex->cmd_2[0], X_OK) == 0)
	{
		execve(pipex->cmd_2[0], pipex->cmd_2, envp);
		return ;
	}
	while (pipex->path[i] != NULL)
	{
		cmd_path = ft_strjoin(pipex->path[i], pipex->cmd_2[0]);
		if (access(cmd_path, X_OK) == 0)
			break ;
		i++;
		free(cmd_path);
	}
	if (pipex->path[i] != NULL)
	{
		execve(cmd_path, pipex->cmd_2, envp);
		free(cmd_path);
	}
	else
		command_not_found(pipex->cmd_2[0]);
}

static void	free_pipex(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->cmd_1[i] != NULL)
	{
		free(pipex->cmd_1[i]);
		i++;
	}
	free (pipex->cmd_1);
	i = 0;
	while (pipex->cmd_2[i] != NULL)
	{
		free(pipex->cmd_2[i]);
		i++;
	}
	free (pipex->cmd_2);
	i = 0;
	while (pipex->path[i] != NULL)
	{
		free(pipex->path[i]);
		i++;
	}
	free (pipex->path);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		error_wrong_args();
	init_vars(&pipex, argv, envp);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipex.fd[0]);
		dup2(pipex.fd_in, 0);
		dup2(pipex.fd[1], 1 );
		close(pipex.fd[1]);
		close(pipex.fd_in);
		close(pipex.fd_out);
		cmd_1(&pipex, envp);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipex.fd[1]);
		dup2(pipex.fd[0], 0);
		dup2(pipex.fd_out, 1 );
		close(pipex.fd[0]);
		close(pipex.fd_in);
		close(pipex.fd_out);
		cmd_2(&pipex, envp);
		exit(0);
	}
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	pipex.pid = waitpid(-1, &status, 0);
	pipex.pid = waitpid(-1, &status, 0);
	free_pipex(&pipex);
	return (0);
}

