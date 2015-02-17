all:
	gcc -Wall -o mydiff mydiff.c 
	gcc -Wall -o myhead myhead.c
	gcc -Wall -o myls myls.c 

mydiff:
	gcc -Wall -o mydiff mydiff.c
myhead:
	gcc -Wall -o myhead myhead.c
myls:
	gcc -Wall -o myls myls.c

clean:
	rm -f mydiff myhead myls
