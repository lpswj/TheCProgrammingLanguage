objects=calc.o push_pop.o

calc:$(objects)
	gcc -std=c99 -g $(objects) -o calc 
calc.o:
	gcc -c -std=c99 -g calc.c -o calc.o
push_pop.o:
	gcc -c -std=c99 -g push_pop.c -o push_pop.o
clean:
	rm -f $(objects) calc


