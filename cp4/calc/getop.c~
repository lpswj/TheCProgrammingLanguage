#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp=0;	/* next free position in buf */

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i,c;
	while((s[0]=c=getch()) ==' ' ||c=='\t')
			;
	s[1]='\0';
	if(!isdigit(c) && c != '.')
			return c;	/* not a number */
	i=0;
	if(isdigit(c))	/* collect integer part */
			while(isdigit(s[i++]=c=getch()))
							;
	if(c=='.')	/* collect fraction part */
			while(isdigit(s[++i]=c=getch()))
					;
	s[i]='\0';
	if(c!=EOF)
			ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch:too many characters\n");
	else
		buf[bufp++]=c;
}
