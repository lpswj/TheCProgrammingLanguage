//add stack command:printop();copytop();swap();clear();
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100	/* max size fo operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define IDENTIFIER '1'

int getop(char []);
void push(double);
double pop(void);

/*new add*/
double printop(void);
double printstack(void);
void copy(void);
void swap(void);
void clear(void);

/*math function*/
void dealWithName(char s[]);

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

double printop(void)
{
	if(sp>0)
		 printf("Top element is %g\n",val[sp-1]);
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}

double printstack(void)
{
	int i;
	if(sp>0)
	{
		printf("the stack is :");
		for(i=0;i<sp;i++)
				printf("%g ",val[i]);
	}
	else
	{
		printf("error:stack empty\n");
	}
}

void copy(void)
{
	double temp=pop();
	push(temp);
	push(temp);
}

void swap(void)
{
	double t1,t2;
	t1=pop();
	t2=pop();
	push(t1);
	push(t2);
}

void clear(void)
{
	sp=0;
}

/*
 *
 *dealwithname 
 *
 *
 */
/*
 *
 *getop.c
 *
 *
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

	/*get the char input*/
	if(isalpha(c))
	{
		i=0;
		while(isalpha(s[i++]=c))
				c=getch();
		s[i-1]='\0';
		if(c != EOF)
				ungetch(c);
		return IDENTIFIER;
	}

	if(!isdigit(c)&&c!='.'&&c!='-')
			return c;
	if(c=='-')
	{
		next=getch();
		if(!isdigit(next) && next !='.')
				return next;
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
