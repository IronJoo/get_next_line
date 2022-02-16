/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:38:08 by jferro            #+#    #+#             */
/*   Updated: 2022/02/16 01:46:34 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

void	copy_string(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size >= 0 && src)
	{
		while (src[i] != '\n' && src[i] != '\0' && i < size)
		{
			dst[i] = src[i];
			i++;
		}
		if (src[i] == '\n')
		{
			dst[i] = '\n';
			i++;
		}
		dst[i] = '\0';
	}
}
