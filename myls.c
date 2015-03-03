#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]){

	// Check arguments introduced by the user (argv[0] -> program, argv[i] -> directory to search)
	if (argc < 2){
		printf("Too few arguments\n");
        return -1;
	}

	// In our implementation the user can introduce more than one directory
	int i, close_error, myErrno;
	for (i = 1 ; i < argc ; i++){

		// Cheking if the directory can be opened
		DIR * myDirectory = opendir(argv[i]);
		if (myDirectory == NULL){
			perror("Cannot open the directory");
			return -1;
		}

		myErrno = errno;
		struct dirent * entry = readdir(myDirectory);

		// Cheking if the directory can be read
		if (myErrno != errno){
			perror("Cannot read the directory");
			closedir(myDirectory);
			return -1;
		}

		// While "entry" is not null, we print the directory/files names and update "entry"
		else {
			while (entry != NULL){
				printf("%s\n", entry -> d_name);
				
				myErrno = errno;
				entry = readdir(myDirectory);

				if (myErrno != errno){
					perror("Cannot read the directory");
					closedir(myDirectory);
					return -1;
				}
			}
		}

		close_error = closedir(myDirectory);

		// Cheking if the directory can be closed
		if (close_error == -1){
			perror("The directory can not be closed");
			return -1;
		}
	}

	return 0;
}