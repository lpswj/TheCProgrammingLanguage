#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP 100	/* max size fo operand or operator */


/* Reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type=getop(s))!=EOF){
			switch(type){
					case NUMBER:
							push(atof(s));
							break;
					case IDENTIFIER:
							dealWithName(s);
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
					case '\n':
							printf("\t%.8g\n",pop());
							break;
					/* print the top element and not push */
					case 'p':
							printop();
							break;
					/* copy the top element and print it */
					case 'c':
							copy();
							break;
					/* print the stack */
					case 'P':
							printstack();
							break;
					/* swap the top two element */
					case 's':
							swap();
							break;
					case 'C':
							clear();
							break;
					default:
							printf("error:unknown command %s\n",s);
							break;
			
			}
	}
	return 0;
}
