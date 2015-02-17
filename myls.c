#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* If less than two arguments (argv[0] -> program, argv[1] -> directory to search) print an error y return -1 */
	if(argc < 2)
	{
		printf("Too few arguments\n");
        	return -1;
	}

	/* Include your code from here */

	return 0;
}
