objects=calc.o stack.o getop.o getch.o

expr:$(objects)
	gcc -std=c99 -g $(objects) -o expr -lm
calc.o:calc.h
	gcc -c -std=c99 -g calc.c -o calc.o 
getop.o:calc.h
	gcc -c -std=c99 -g getop.c -o getop.o 
getch.o:calc.h
	gcc -c -std=c99 -g getch.c -o getch.o 
stack.o:calc.h
	gcc -c -std=c99 -g stack.c -o stack.o 
clean:
	rm -f $(objects) expr


