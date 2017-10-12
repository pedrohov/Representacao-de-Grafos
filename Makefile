all:
	gcc -o lista.o -c lista.c
	gcc -o grafoM.o -c grafoM.c
	gcc -o grafoL.o -c grafoL.c
	gcc -o transformaGrafos.o -c transformaGrafos.c
	gcc -o main transformaGrafos.o grafoM.o grafoL.o lista.o main.c

run:
	./main
