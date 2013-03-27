objects=main.o stack.o getop.o getch.o

main:$(objects)
	gcc -std=c99 -g $(objects) -o main -lm
main.o:calc.h
	gcc -c -std=c99 -g main.c -o main.o 
stack.o:calc.h
	gcc -c -std=c99 -g stack.c -o stack.o 
getop.o:calc.h
	gcc -c -std=c99 -g getop.c -o getop.o
getch.o:calc.h
	gcc -c -std=c99 -g getch.c -o getch.o
clean:
	rm -f $(objects) main


