#include <stdio.h>
#include <math.h>
#include <string.h>
#include "calc.h"


#define MAXVAL 100 	/* maximum depth of val stack */

static int sp=0;			/* next free stack position */
static double val[MAXVAL];	/* value stack */

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

void dealWithName(char s[])
{
	double op2;
	if(0 == strcmp(s,"sin"))
			push(sin(pop()));
	else if(0 == strcmp(s,"cos"))
			push(cos(pop()));
	else if(0 == strcmp(s,"exp"))
			push(exp(pop()));
	else if(!strcmp(s,"pow"))
	{
		op2=pop();
		push(pow(pop(),op2));
	}
	else
			printf("%s is not a support function.\n",s);
}


