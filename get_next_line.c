/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:57:43 by jferro            #+#    #+#             */
/*   Updated: 2022/02/16 01:37:50 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*thankyou_bmiguel_(char *save, int i)
{
	char	*new_save;
	int		j;

	j = 0;
	new_save = (char *)malloc((sizeof(char)) * (ft_strlen(save) - i++));
	if (!new_save)
		return (NULL);
	while (save[i] != '\0')
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	if (!*new_save)
	{
		free(new_save);
		new_save = NULL;
	}
	return (new_save);
}

char	*clean_save(char *save)
{
	int		i;

	i = 0;
	if (!*save)
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] != '\0')
		return (thankyou_bmiguel_(save, i));
	free(save);
	save = NULL;
	return (save);
}

char	*get_line(char	*save)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!*save)
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
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = clean_save(save);
	return (line);
}
