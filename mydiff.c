#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){

	// Check parameters introduced by the user
	if (argc != 3){
		printf("Syntax error. Correct syntax is:\n");
		printf("\t%s <file1> <file2>\n",argv[0]);		

		return -1;
	}

	// Gives to both opne files an identifier descriptor
	int filDes = open(argv[1], O_RDONLY);
	int filDes2 = open(argv[2], O_RDONLY);

	int control = 1, control2 = 1;
	char buffer[1], buffer2[1];


	// While both reads are done correctly, the loop continues until it reaches the end of one of the files
	while (control == 1 && control2 == 1){

		control = read(filDes, buffer, 1);
		control2 = read(filDes2, buffer2, 1);

		// In the case in a determined position both characters are differents, it exits
		if (buffer[0] != buffer2[0]){
			printf("Los ficheros %s y %s son distintos\n",argv[1],argv[2]);
			close(filDes);
			close(filDes2);
			return 0;
		}
	}


	// Finally, if all the characters are the same and the end of both files is reached, they are equal
	if (control == 0 && control2 == 0){
		printf("Los ficheros %s y %s son identicos\n",argv[1],argv[2]);
	}

	close(filDes);
	close(filDes2);
	
	return 0;
}