#Makefile
all: add-nbo

add-nbo: main.o checkfile.o my_htonl.o
	g++ -o add-nbo main.o checkfile.o my_htonl.o

main.o: checkfile.h my_htonl.h main.c
	g++ -c -o main.o main.c
	
checkfile.o: checkfile.h checkfile.c
	g++ -c -o checkfile.o checkfile.c

my_htonl.o: my_htonl.h my_htonl.c
	g++ -c -o my_htonl.o my_htonl.c

clean:
	rm -f add-nbo
	rm -f *.o
