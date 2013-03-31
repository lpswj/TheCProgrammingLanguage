#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP 100	/* max size fo operand or operator */


/* Reverse Polish calculator */
int main(int argc,char *argv[])
{
	int type,i;
	double op2;
	if(argc<1)
			printf("Usage: expr 2 3 +\n");
	for(i=1;i<argc;i++)	
	{
			while((type=getop(argv[i])) != EOF){
			switch(type){
					case NUMBER:
							push(atof(argv[i]));
							break;
					case '+':
							push(pop()+pop());
							break;
					case '*':
							push(pop()*pop());
							break;
					case '-':
							op2=pop();
							push(pop()-op2);
							break;
					case '/':
							op2=pop();
							if(op2!=0.0)
									push(pop()/op2);
							else
									printf("error:zero divisor\n");
							break;
					case '%':
							op2=pop();
							if(op2)
									push(fmod(pop(),op2));
							else
									printf("error:zero divisor\n");
							break;
					default:
							printf("unknown operator.\n");
							break;
			}
			}
	}	
	printf("%g\n",pop());
	return 0;
}

