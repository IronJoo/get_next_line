/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferro <jferro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:13:19 by jferro            #+#    #+#             */
/*   Updated: 2022/01/27 19:49:56 by jferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	new_line_in_buffer(char *buffer)
{
	char	*line;
	char	*p;

	p = ft_strchr(buffer, '\n');
	if (p != NULL)
		return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_size;
	int			line_size;

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
		return (NULL);
	line = (char *)malloc((sizeof(char)) * line_size);
	// 
	if (new_line_in_buffer(buffer))
	{
		
	}
	else
	{
		
	}
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", str);
	for (int i = 0; i < 100; i++)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
}
