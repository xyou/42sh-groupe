/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:52:15 by jmery             #+#    #+#             */
/*   Updated: 2014/02/28 17:02:12 by cochin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __42SH_H__
# define __42SH_H__
# define BUF_SIZE 512

#include <unistd.h>
#include <stdlib.h>

char	**g_myenv;

/* FORK */
int		ft_execcmd(char **arg);

/* ENV */
char	**ft_getenv(char **env);
char	*ft_getkey(char *key);

/* 42 SH TOOLS */
size_t	ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	**ft_strsplit(char const *s, char c);
int		ft_strncmp(char*s1, char *s2, size_t n);
char	*ft_strcat(char *dest, char *src);

/* 42 SH CMD TOOLS */
char	*ft_tabtospace(char *str);

/* 42 SH ERROR */
void	ft_puterror(char *str);

/* TABLE TOOLS */
int		ft_tablerange(char **table);
char	**ft_tablencpy(char **tabledest, char **tablesrc, int n);
void	ft_printtable(char **table);
void	ft_freetable(char **table);

#endif
