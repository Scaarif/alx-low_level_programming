#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _write()
{
	char buf[20];/*reserve memory to store the value*/
	size_t nbytes;
	ssize_t bytes_written;
	int fd = 1; /*write to std output instead of to a file*/

	strcpy(buf, "This is a test\n");
	nbytes = strlen(buf);

	bytes_written = write(fd, buf, nbytes);
	return (bytes_written);
}

int main(void)
{
	// _write();
	printf("no of bytes printed: %d\n", _write());
	return (0);
}



