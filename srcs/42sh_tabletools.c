/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_tabletools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:19:53 by cochin            #+#    #+#             */
/*   Updated: 2014/02/28 16:21:20 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_tablerange(char **table)
{
	int		i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

char	**ft_tablencpy(char **tabledest, char **tablesrc, int n)
{
	int		i;
	char	*str;

	i = 0;
	while (tablesrc[i] && i < n)
	{
		str = (char *)malloc(sizeof(*str) * (ft_strlen(tablesrc[i]) + 1));
		if (str)
		{
			ft_strcpy(str, tablesrc[i]);
			tabledest[i] = str;
		}
		i++;
	}
	tabledest[i] = NULL;
	while (i < n)
	{
		tabledest[i] = NULL;
		i++;
	}
	return (tabledest);
}

void	ft_printtable(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		write(1, table[i], ft_strlen(table[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	ft_freetable(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}
