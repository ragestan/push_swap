/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:28:54 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/23 14:30:10 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*line(char *str, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	i = 1;
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*l;

	l = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next = line(next, fd);
	if (next == NULL)
		return (NULL);
	l = ft_line(next);
	next = mzl(next);
	if (l[0] == '\0')
	{
		free(next);
		free(l);
		return (NULL);
	}
	return (l);
}
