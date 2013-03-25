//add the % function
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100	/* max size fo operand or operator */
#define NUMBER '0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

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
/*
					case '%':
							op2=pop();
							if(op2!=0.0)
									push((int)pop()%(int)op2);
							else 
									printf("error:zero divisor\n");

							break;	
*/
					/* another try on % by using fmod */
					case '%':
							op2=pop();
							if(op2)
									push(fmod(pop(),op2));
							else
									printf("\nError:Zero Divisor\n");
							break;

					case '\n':
							printf("\t%.8g\n",pop());
							break;
					default:
							printf("error:unknown command %s\n",s);
							break;
			
			}
	}
	return 0;
}

/*
 *
 *Stack.c
 *
 *
 */

#define MAXVAL 100 	/* maximum depth of val stack */

int sp=0;			/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if(sp<MAXVAL)
			val[sp++]=f;
	else
			printf("error:stack full,can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if(sp>0)
			return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}

/*
 *
 *getop.c
 *
 *Deal with unary minus when retrieving tokens.This is based on
 *the fact that a unary minus will have no interverning space 
 *between it and its operand.
 */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i=0,c,next;

	while((s[0]=c=getch())==' ' ||c=='\t')
			;
	s[1]='\0';
	/* Not a number but may contain a unary minus. */
	if(!isdigit(c)&&c!='.'&&c!='-')
			return c;

 	if(c=='-')
	{
		next=getch();
		if(!isdigit(next)&&next != '.')
		{
			return next;
		}
		c=next;
	}	
	else
			c=getch();
	while(isdigit(s[++i]=c))
			c=getch();
	if(c=='.')
			while(isdigit(s[++i]=c=getch()))
					;
	s[i]='\0';
	if(c!=EOF)
			ungetch(c);
	return NUMBER;
}


/*
 *
 * getch.c
 *
 */

#define BUFSIZE 100

char buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp=0;			/* next free position in buf */

int getch(void)		/* get a (possibly pushed-back) character */
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if(bufp >= BUFSIZE)
			printf("ungetch:too many characters\n");
	else
			buf[bufp++]=c;
}
