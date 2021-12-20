/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:38:00 by mel-hada          #+#    #+#             */
/*   Updated: 2021/12/19 14:18:40 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill(char *s, char *filler, int start)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (filler[i])
		s[j++] = filler[i++];
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	fill(str, s1, 0);
	fill(str, s2, ft_strlen(s1));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!(char)c)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(char *s, int t)
{
	int		i;
	int		j;
	int		len;
	char	*copy;

	if (*s == '\0')
		return (NULL);
	len = 0;
	while (s[len + t])
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = t;
	j = 0;
	while (s[i])
		copy[j++] = s[i++];
	free(s);
	copy[j] = '\0';
	return (copy);
}
