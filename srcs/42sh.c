/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:53:37 by cochin            #+#    #+#             */
/*   Updated: 2014/02/28 17:04:31 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_stockcmd(char buf[], int ret)
{
	char	*cmd;

	cmd = (char *)malloc(sizeof(*cmd) * ret);
	if (cmd)
		ft_strncpy(cmd, buf, ret - 1);
	return (cmd);
}

int		ft_getcmd(void)
{
	int		ret;
	char	buf[BUF_SIZE];
	char	*cmd;
	char	**arg;

	write(1, "$> ", 3);
	if ((ret = read(0, buf, BUF_SIZE)) <= 0)
		return (EXIT_FAILURE);
	cmd = ft_tabtospace(ft_stockcmd(buf, ret));
	arg = ft_strsplit(cmd, ' ');
	if (ft_execcmd(arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(cmd);
	return (EXIT_SUCCESS);
}

int		main(int argc, char **argv, char **env)
{
	int		exit;

	if (argc)
		argv++;
	exit = EXIT_SUCCESS;
	g_myenv = ft_getenv(env);
	while (exit == EXIT_SUCCESS)
		exit = ft_getcmd();
	ft_freetable(g_myenv);
	return (EXIT_SUCCESS);
}
