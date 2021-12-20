/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:10:12 by mel-hada          #+#    #+#             */
/*   Updated: 2021/12/19 14:19:54 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *s, int t);

#endif
