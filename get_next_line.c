/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:37:33 by mel-hada          #+#    #+#             */
/*   Updated: 2021/12/19 14:15:17 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc(i + 1 + (rest[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_rest(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	return (ft_strdup(rest, i + 1));
}

char	*get_rest(int fd, char *rest)
{
	char	box[BUFFER_SIZE + 1];
	int		bytes;

	if (ft_strchr(rest, '\n'))
		return (rest);
	*box = '\0';
	bytes = 1;
	while (!ft_strchr(rest, '\n') && bytes)
	{
		bytes = read(fd, box, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		box[bytes] = '\0';
		rest = ft_strjoin(rest, box);
	}
	if (bytes < 0)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = get_rest(fd, rest);
	if (rest == NULL)
		return (NULL);
	line = get_line(rest);
	rest = update_rest(rest);
	return (line);
}
