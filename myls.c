#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

	// Check arguments introduced by the user (argv[0] -> program, argv[1] -> directory to search)
	if (argc < 2){
		printf("Too few arguments\n");
        return -1;
	}


	// Cheking if the directory can be opened
	DIR * myDirectory = opendir(argv[1]);
	if (myDirectory == NULL){
		perror("Cannot open the directory");
		return -1;
	}

	struct dirent * entry = readdir(myDirectory);

	// Cheking if the directory can be read
	if (entry == NULL){
		perror("Cannot read the directory");
		closedir(myDirectory);
		return -1;
	}

	// While "entry" is not null, we print the directory/files names and update "entry"
	else {
		while (entry != NULL){
			printf("%s\n", entry -> d_name);
			entry = readdir(myDirectory);
		}
	}

	int close_error = closedir(myDirectory);

	// Cheking if the directory can be closed
	if (close_error == -1){
		perror("The directory can not be closed");
		return -1;
	}

	return 0;
}