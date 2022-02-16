#include "get_next_line_bonus.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	int fd1 = open("files/text", O_RDONLY);
	int fd2 = open("files/multiple_line_with_nl", O_RDONLY);
	char *str;

	while (1)
	{
		str = get_next_line(fd1);
		if (!str)
			return (0);
		else
			printf("%s", str);
	}
	// for (int i = 0; i < 10; i++)
	// 	printf("%s", get_next_line(fd1));
	// for (int j = 0; j < 10; j++)
	// 	printf("%s", get_next_line(fd2));
}
