#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	/* If less than four arguments (argv[0] -> program, argv[1] -> number of bytes to display, argv[2] -> input file, argv[3] ->  output file) print an error y return -1 */
	if (argc != 4){
	    printf("Invalid number of arguments\n");
	    printf("\t%s <N> <file1> <file2>\n", argv[0]);		
	    return -1;
	}

	int filDes = open(argv[2], O_RDONLY);
	int filDes2 = open(argv[3], O_WRONLY);

	if (filDes2 == -1){
		creat("Second.txt", O_WRONLY);
		filDes2 = open("Second.txt", O_WRONLY);
	}

	int i = 0, control = 1;
	int size = atoi(argv[1]);
	char buffer[1];

	while (i < size){
		control = read (filDes, buffer, 1);
		if (control == 0){
			break;
		}
		write (filDes2, buffer, 1);
		i++;
	}

	close(filDes);
	close(filDes2);

	return 0;
}