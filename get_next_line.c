/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:45:07 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 14:11:00 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*line = ft_substr(tmp, 0, i);
	if (!tmp[i])
	{
		*str = NULL;
		free(tmp);
		return (0);
	}
	*str = ft_strdup(&tmp[i + 1]);
	free(tmp);
	if (!*line || !*str)
		return (-1);
	if (*str != NULL)
		return (1);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	int			ret;
	char		*tmp;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0
			|| !(buffer = malloc(BUFFER_SIZE + 1)) || read(fd, buffer, 0) == -1)
		return (-1);
	if (!str)
		if (!(str = ft_strdup("\0")))
			return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buffer);
		free(tmp);
		if (index_of(str, '\n') != -1)
			break ;
	}
	free(buffer);
	if (ret == -1)
		return (-1);
	return (get_line(&str, line));
}
