#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	// Check arguments introduced by the user (argv[0] -> program, argv[1] -> number of bytes, argv[2] -> input file, argv[3] ->  output file)
	if (argc != 4){
	    printf("Invalid number of arguments\n");
	    printf("\t%s <N> <file1> <file2>\n", argv[0]);
	    return -1;
	}
	int size = atoi(argv[1]);

	// Checking that the number of bits is correct
	if (size < 1){
		perror("The number of bits has to be at least 1");
		return -1;
	}


	// Gives to both open files an identifier descriptor
	int filDes = open(argv[2], O_RDONLY);
	int filDes2 = open(argv[3], O_CREAT|O_TRUNC|O_WRONLY, 0666);

	// Checking if there is any error in the open operations
	if (filDes == -1 || filDes2 == -1){
		perror("The file can not be opened");
		return -1;
	}

	int i = 0, read_error, write_error;
	char buffer[1];


	// While variable "i" continues being less than size, it writes in the second file
	while (i < size){
		read_error = read(filDes, buffer, 1);

		// Checking if there is any error in the read operation
		if (read_error == -1){
			perror("The file can not be read");
			close(filDes);
			close(filDes2);
			return -1;
		}

		// The end of the file is reached
		else if (read_error == 0){
			break;
		}

		write_error = write (filDes2, buffer, 1);

		// Checking if there is any error in the write operations
		if (write_error == -1){
			perror("The file can not be written");
			return -1;
		}

		i++;
	}


	int close_error = close(filDes);
	int close_error2 = close(filDes2);

	// Checking if there is an error in any close operation
	if (close_error == -1 || close_error2 == -1){
		perror("The file can not be closed");
		return -1;
	}

	return 0;
}