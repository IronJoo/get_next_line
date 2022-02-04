/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:57:43 by jferro            #+#    #+#             */
/*   Updated: 2022/02/04 17:55:11 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*clean_save(char *save)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	j = i;
	while (save[j] != '\n' && save[j] != '\0')
		j++;
	p = (char *)malloc((sizeof(char)) * (j - i));
	if (!p)
		return (NULL);
	if (save[i] != '\0')
	{
		j = 0;
		while (save[++i] != '\n' && save[i] != '\0')
		{
			p[j] = save[i];
		}
	}
	else
		return (save);
	return (p);
}

void	copy_string(char *restrict dst, const char *restrict src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
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

char	*get_line(char	*save)
{
	int		i;
	char	*new_save;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	new_save = (char *)malloc((sizeof(char)) * (i + 2));
	if (!new_save)
		return (NULL);
	copy_string(new_save, save, i);
	return (new_save);
}

char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	int		read_size;

	buffer = (char *)malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(save, '\n') && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		if (!save)
			save = ft_strdup(buffer);
		else
			save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	save = read_and_save(fd, save);
	line = get_line(save);
	save = clean_save(save);
	return (line);
}
int	main(void)
{
	// printf("Insert input: \n");
	// int fd = 0;
	// printf("You inserted = %s", get_next_line(fd));

	int fd = open("text.txt", O_RDONLY);
	//char *line = get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
