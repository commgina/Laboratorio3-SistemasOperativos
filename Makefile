all: e1 e2 cJSON.o libcJSON.a lib_d.o lib_d.so CommandLineArguments.o CommandLineArguments

CommandLineArguments: CommandLineArguments.o libcJSON.a lib_d.so
	gcc -o CommandLineArguments CommandLineArguments.o -L./ -l_d libcJSON.a -Wl,-rpath,./

CommandLineArguments.o: CommandLineArguments.c
	gcc -c CommandLineArguments.c -o CommandLineArguments.o

lib_d.so: lib_d.o 
	gcc lib_d.o -shared -o lib_d.so

lib_d.o: lib_d.c lib_d.h
	gcc -c lib_d.c -fpic	

libcJSON.a: cJSON.o 
	ar rcs libcJSON.a cJSON.o 

cJSON.o: cJSON.c cJSON.h
	gcc -c cJSON.c -o cJSON.o

e2: ejercicio2Lab2.c
	gcc -Wall -Werror -pedantic -o e2 ejercicio2Lab2.c

e1: ejercicio1Lab2.c
	gcc -Wall -Werror -pedantic -o e1 ejercicio1Lab2.c

clean:
	rm -f *.o *.a *.txt *.so e1 e2 CommandLineArguments 