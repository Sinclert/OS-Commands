#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

	/* If less than two arguments (argv[0] -> program, argv[1] -> directory to search) print an error y return -1 */
	if (argc < 2){
		printf("Too few arguments\n");
        return -1;
	}

	// Here it is check if the directory can be open
	DIR * myDirectory = opendir(argv[1]);
	if (myDirectory == NULL){
		printf("Cannot open directory %s\n", argv[1]);
		return -1;
	}

	struct dirent * entry = readdir(myDirectory);

	// While "entry" is not null, we print the directory/files names and update "entry"
	while (entry != NULL){
		printf("%s\n", entry -> d_name);
		entry = readdir(myDirectory);
	}

	closedir(myDirectory);
	return 0;
}