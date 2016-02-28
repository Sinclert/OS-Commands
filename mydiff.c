#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){

	// Check arguments introduced by the user
	if (argc != 3){

		printf("Syntax error. Correct syntax is:\n");
		printf("\t%s <file1> <file2>\n",argv[0]);
		return -1;
	}

	// Gives to both open files an identifier descriptor
	int filDes = open(argv[1], O_RDONLY);
	int filDes2 = open(argv[2], O_RDONLY);

	// Checking if there is any error in the open operations
	if (filDes == -1 || filDes2 == -1){
		perror("The file can not be opened");
		return -1;
	}

	int control = 1, control2 = 1;
	int close_error, close_error2;
	char buffer[1], buffer2[1];


	// While both reads are done correctly, the loop continues until it reaches the end of one of the files
	while (control == 1 && control2 == 1){

		control = read(filDes, buffer, 1);
		control2 = read(filDes2, buffer2, 1);

		// Checking if there is any error in the read operations
		if (control == -1 || control2 == -1){
			perror("The file can not be read");
			close(filDes);
			close(filDes2);
			return -1;
		}

		// In the case in a determined position both characters are differents, it exits
		if (buffer[0] != buffer2[0]){
			printf("The files %s and %s are different\n",argv[1],argv[2]);
			close_error = close(filDes);
			close_error2 = close(filDes2);

			// Checking if there is an error in any close operation
			if (close_error == -1 || close_error2 == -1){
				perror("The file can not be closed");
				return -1;
			}

			return 1;
		}
	}


	// If all the characters are the same and the end of both files is reached, they are equal
	if (control == 0 && control2 == 0){
		printf("The files %s and %s are equal\n",argv[1],argv[2]);
		close_error = close(filDes);
		close_error2 = close(filDes2);

		// Checking if there is an error in any close operation
		if (close_error == -1 || close_error2 == -1){
			perror("The file can not be closed");
			return -1;
		}
		return 0;
	}


	// Finally, if the end of a file is reached before the other's file end, they are different
	else {
		printf("The files %s and %s are different\n",argv[1],argv[2]);
		close_error = close(filDes);
		close_error2 = close(filDes2);

		// Checking if there is an error in any close operation
		if (close_error == -1 || close_error2 == -1){
			perror("The file can not be closed");
			return -1;
		}

		return 1;
	}
	
}
