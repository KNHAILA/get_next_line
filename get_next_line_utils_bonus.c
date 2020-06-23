/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:44:24 by knhaila           #+#    #+#             */
/*   Updated: 2019/12/27 19:23:41 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (i <= len)
		{
			str[i] = s1[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			lnew;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	lnew = ft_strlen(&s[start]);
	if (lnew >= len)
		lnew = len;
	if (!(str = (char *)malloc(sizeof(char) * (lnew + 1))))
		return (NULL);
	while (i < len && *s != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	int		j;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!str)
		return (NULL);
	while (++i < (int)ls1)
		str[i] = s1[i];
	j = 0;
	while (i < (int)(ls1 + ls2))
	{
		str[i++] = s2[j++];
	}
	str[ls1 + ls2] = '\0';
	return (str);
}

int			index_of(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
