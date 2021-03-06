/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_cmdtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:58:58 by cochin            #+#    #+#             */
/*   Updated: 2014/02/28 17:00:26 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_tabtospace(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}
