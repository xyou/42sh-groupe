/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:55:48 by jmery             #+#    #+#             */
/*   Updated: 2014/02/28 17:05:07 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    *ft_strcat(char *dest, char *src)
{
	unsigned int    i;
	unsigned int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	char			dif;

	i = 0;
	dif = 0;
	while (s1[i] && s2[i] && dif == 0 && i < n)
	{
		if (s1[i] != s2[i])
			dif = s1[i] - s2[i];
		else
			i++;
	}
	dif = s1[i] - s2[i];
	return (dif);
}
