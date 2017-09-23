# OS-Commands

This repository is a small collection of several Operating System commands, some of them already implemented in the UNIX systems, but others expand the OS ones to provide better functionality.

## What is in the repository?

### 1. Makefile:
File to compile the other repository files. It can be also used to remove the compiled ones.
```shell
$ make
gcc -Wall -o mydiff mydiff.c 
gcc -Wall -o myhead myhead.c
gcc -Wall -o myls myls.c 
```

```shell
$ make clean 
rm -f mydiff myhead myls
```

### 2. mydiff:
File that implements a function which compares 2 existing files and determine if they are equal or not. The possible outputs are: "The files <i>file1</i> and <i>file2</i> are equal" or "The files <i>file1</i> and <i>file2</i> are different". <b>It works with any type of file: PNG, MP3...</b>

#### How does it work?
```shell
$ ./mydiff <file1> <file2>
```

### 3. myhead:
File that implements a function which copy the first "n" bytes of a file into a new one. The number of bytes can be specified. The first specified file is the source and the second one is the destination one. <b>In case that the second file does not exist, it will be created.</b>

#### How does it work?
```shell
$ ./myhead <N> <file1> <file2>
```

### 4. myls:
File that implements a function already provided in a UNIX operating system: list the number of files and directories in the specified directory.

#### How does it work?

```shell
$ ./myls <directory>
```
## Requirements:
These commands are designed to work in a UNIX O.S. (GCC Compiler needed). Those which fullfill the requirements:

<b>A) Mac OSX</b><br>
<b>B) Any Linux distribution</b>
