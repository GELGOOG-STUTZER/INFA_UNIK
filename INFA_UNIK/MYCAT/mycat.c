#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main( int argc, char *argv[] )
{
	int i, fd, ch;

	for (i = 1; i < argc; i++)
		{
		fd = open( argv[i], O_RDONLY );
		if (fd < 0) {
			printf("open error %s\n", argv[i]);
			continue;
		}
		while (read(fd, &ch, 1) == 1) 
			write(STDOUT_FILENO, &ch, 1);
		close(fd);
		}
}
