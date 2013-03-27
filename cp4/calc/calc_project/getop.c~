#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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

