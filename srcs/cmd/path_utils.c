/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarliah <lkarliah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:07:43 by natali            #+#    #+#             */
/*   Updated: 2021/08/07 21:06:56 by lkarliah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*path_name(char *path, char *cmd_name, t_cmd *cmd)
{
	struct stat	buff;
	char		*new;
	int			fd;

	new = ft_strdup(path);
	new = ft_strnjoin(new, "/", 1);
	new = ft_strnjoin(new, cmd_name, ft_strlen(cmd_name));
	if ((stat(new, &buff)) == 0)
	{
		cmd->path = ft_strdup(new);
		free (new);
		return ((void *)1);
	}
	free (new);
	return (NULL);
}

int	check_path(char **path, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if ((path_name(path[i], cmd->args[0], cmd)))
			return (1);
		i++;
	}
	ft_putstr_fd(cmd->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	g_data.status = 127;
	return (0);
}

int	check_file(t_cmd *cmd)
{
	struct stat	buff;

	if ((ft_strchr(cmd->args[0], '/')))
	{
		if ((stat(cmd->args[0], &buff)) < 0)
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			g_data.status = 127;
			return (-1);
		}
		else if (S_ISDIR(buff.st_mode))
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putstr_fd(": Is a directory\n", 2);
			g_data.status = 126;
			return (-1);
		}
		else
		{
			cmd->path = ft_strdup(cmd->args[0]);
			return (0);
		}
	}
	return (1);
}

void	*get_path(t_cmd *cmd, char **envp)
{
	char	**path;

	path = NULL;
	if (!cmd->args || !envp)
		return (NULL);
	while (*envp)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			path = ft_split(*envp + 5, ':');
		envp++;
	}
	if (!path)
	{
		ft_putstr_fd("Error: cannot find PATH variable\n", 2);
		g_data.status = 1;
		return (ft_free_array((void **)path));
	}
	if ((check_file(cmd)) == -1)
		return (ft_free_array((void **)path));
	else if ((check_file(cmd)) == 1)
		if (!check_path(path, cmd))
			return (ft_free_array((void **)path));
	ft_free_array((void **)path);
	return ((void *)1);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
			ft_free_array((void **)cmd->args);
		free (cmd);
		cmd = tmp;
	}
}
