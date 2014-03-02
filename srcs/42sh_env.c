/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:20:05 by cochin            #+#    #+#             */
/*   Updated: 2014/02/28 16:29:53 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	**ft_getenv(char **env)
{
	int		tablerange;
	char	**myenv;

	tablerange = ft_tablerange(env);
	myenv = (char**)malloc(sizeof(myenv) * (tablerange + 1));
	if (myenv)
		ft_tablencpy(myenv, env, tablerange);
	return (myenv);
}

char	*ft_getkey(char *key)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	while (g_myenv[i] && tmp == NULL)
	{
		if (ft_strncmp(key, g_myenv[i], ft_strlen(key)))
			tmp = g_myenv[i];
		i++;
	}
	return (tmp);
}
