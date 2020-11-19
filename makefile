CLFAGS = -Wall -ansi -std=c99 -c

all : P11 P12 P21 P22 P23
	gcc $(CFLAGS) -o runme main.c p11.o p12.o p21.o p22.o p23.o

P11 : 
	gcc $(CLFAGS) P11.c -o p11.o

P12 : 
	gcc $(CLFAGS) P12.c -o p12.o

P21 : 
	gcc $(CLFAGS) P21.c -o p21.o

P22 : 
	gcc $(CLFAGS) P22.c -o p22.o

P23 : 
	gcc $(CLFAGS) P23.c -o p23.o

run : all
	clear
	./runme

clean : 
	rm -f runme
	rm -f *.o
	clear