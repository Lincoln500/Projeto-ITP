all: main

main: formas.o arquivos.o main.c
	gcc main.c -o main formas.o arquivos.o && ./main

formas.o: formas.c
	gcc -c formas.c

arquivos.o: arquivos.c
	gcc -c arquivos.c
	
clean:
	rm -f *.o