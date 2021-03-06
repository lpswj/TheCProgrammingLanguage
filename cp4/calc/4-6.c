//add stack command:printop();copytop();swap();clear();
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100	/* max size fo operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define IDENTIFIER '1'
#define ENDSTRING '2'
#define MAX_ID_LEN 32
#define MAXVARS 30

/* 4-6 this is new for this program */
struct varType
{
	char name[MAX_ID_LEN];
	double val;
};

int getop(char []);
void push(double);
double pop(void);

double printop(void);
double printstack(void);
void copy(void);
void swap(void);

/* new for this program */
void clearStacks(struct varType var[]);
void dealWithName(char s[],struct varType var[]);
void dealWithVar(char s[],struct varType var[]);

int pos=0;
struct varType last;
/*  end of new stuff */

/* Reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	struct varType var[MAXVARS];

	/* Use the new function here */
	clearStacks(var);
	
	while((type=getop(s))!=EOF){
			switch(type){
					case NUMBER:
							push(atof(s));
							break;
					case IDENTIFIER:
							dealWithName(s,var);
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
							clearStacks(var);
							break;
					case ENDSTRING:
							break;
					case '=':
							pop();
							var[pos].val=pop();
							last.val=var[pos].val;
							push(last.val);
							break;
					case '<':
							printf("The last variable used was: %s (value == %g)\n",last.name,last.val);
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

/* 4-6 this is new for thi program */
/* Altered to clear both the main stack and that of the variable structure*/
void clearStacks(struct varType var[])
{
	int i;

	/* Clear the main stack by setting the position to the bottom */
	sp=0;

	/* Clear the variables by setting the initial element of each name 
	 * to the terminating character. */
	for(i = 0; i < MAXVARS;++i)
	{
		var[i].name[0]='\0';
		var[i].val=0.0;
	}
}

/*
 *
 *dealwithname 
 *a string name may be either a maths function or a variable
 *
 */
void dealWithName(char s[],struct varType var[])
{
	double op2;

	if(! strcmp(s,"sin"))
			push(sin(pop()));
	else if(! strcmp(s,"cos"))
			push(cos(pop()));
	else if(! strcmp(s,"exp"))
			push(exp(pop()));
	else if(!strcmp(s,"pow"))
	{
		op2=pop();
		push(pow(pop(),op2));
	}
	else
			dealWithVar(s,var);	
}

void dealWithVar(char s[],struct varType var[])
{
	int i =0;
	while(var[i].name[0]!='\0' && i< MAXVARS-1)
	{
		if(!strcmp(s,var[i].name))
		{
				strcpy(last.name,s);
				last.val=var[i].val;
				push(var[i].val);
				pos=i;
				return ;
		}
		i++;
	}
	/* variable name not found so add it */
	strcpy(var[i].name,s);
	/* And save it to the last variable */
	strcpy(last.name,s);
	push(var[i].val);
	pos=i;

}


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
