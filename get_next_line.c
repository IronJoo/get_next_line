/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:57:43 by jferro            #+#    #+#             */
/*   Updated: 2022/02/10 21:02:32 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*clean_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	j = i + 1;
	while (save[j] != '\0')
		j++;
	new_save = (char *)malloc((sizeof(char)) * (j - i));
	if (!new_save)
		return (NULL);
	if (save[i] != '\0')
	{
		j = 0;
		i++;
		while (save[i] != '\0')
			new_save[j++] = save[i++];
		new_save[j] = '\0';
	}
	else
		return (save);
	return (new_save);
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

char	*get_line(char	*save)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	next_line = (char *)malloc((sizeof(char)) * (i + 2));
	if (!next_line)
		return (NULL);
	copy_string(next_line, save, i);
	return (next_line);
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
		if (!save || !*save)
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	save = read_and_save(fd, save);
	line = get_line(save);
	save = clean_save(save);
	return (line);
}
// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	char *str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("|%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// }
