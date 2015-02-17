#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	/* If less than four arguments (argv[0] -> program, argv[1] -> number of bytes to display, argv[2] -> input file, argv[3] ->  output file) print an error y return -1 */
	if(argc != 4)
	{
	    printf("Invalid number of arguments\n");
	    printf("\t%s <N> <file1> <file2>\n", argv[0]);		
	    return -1;
	}

	return 0;
}

