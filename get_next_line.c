/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:57:43 by jferro            #+#    #+#             */
/*   Updated: 2022/02/02 20:24:31 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
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
	save = read_and_save(fd, save);
	return (save);
}
int	main(void)
{
	int fd;
	//char *text;
	fd = open("text.txt", O_RDONLY);
	//text = get_next_line(fd);
	printf("%s\n" ,get_next_line(fd));
}
