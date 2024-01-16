#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *line;
	
	//fd = open ("multiple_nl.txt", O_RDONLY);
	fd = open ("teste.txt", O_RDONLY);
 	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}