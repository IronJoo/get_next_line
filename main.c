#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd = open("files/41_no_nl", O_RDONLY);
	if (fd == -1)
		return (1);
	// char *str = get_next_line(fd);
	// //  while (str && *str)
	// //  {
	// //  	printf("%s", str);
	// //  	free(str);
	// //  	str = get_next_line(fd);
	// //  }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
