/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:55:19 by jmery             #+#    #+#             */
/*   Updated: 2014/02/28 16:52:02 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_topath(char *path, char *cmd)
{
	char	*t;

	t = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (t)
	{
		ft_strcpy(t, path);
		ft_strcat(t, "/");
		ft_strcat(t, cmd);
	}
	return (t);
}

void    ft_execinpath(char **arg)
{
	unsigned int	i;
	char			*topath;
	char			**path;

	i = 0;
	path = ft_strsplit(ft_getkey("PATH"), ':');
	if (path)
	{
		while (path[i])
		{
			topath = ft_topath(path[i], arg[0]);
			if (path)
			{
				execve(topath, arg, g_myenv);
				free(topath);
			}
			i++;
		}
	}
}

int		ft_execcmd(char **arg)
{
	int		pid;

	if ((pid = fork()) == -1)
		return (EXIT_FAILURE);
	if (pid > 0)
		waitpid(pid, 0, 0);
	if (pid == 0)
	{
		execve(arg[0], arg, g_myenv);
		ft_execinpath(arg);
		ft_puterror("42sh: command not found: ");
		ft_puterror(arg[0]);
		ft_puterror("\n");
		_exit(1);
	}
	return (EXIT_SUCCESS);
}
