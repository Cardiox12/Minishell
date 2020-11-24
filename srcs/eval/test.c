#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int *ptr;

	ptr = (int*)malloc(2);
	pipe(ptr);
	return (0);
}
