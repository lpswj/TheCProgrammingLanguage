#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

main()
{
		int c;
		float result;
		float test=1.0;
		float *pn=&result;
		while((c=getint(pn))!='\n')
				;
		printf("the result is %f\n",result);
		printf("the result is %f\n",test);
		
}

/* getint:get next integer from input into *pn */
int getint(float *pn)
{
	int c,sign,sawsign,power=1;

	while(isspace(c=getch()))
			;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
			ungetch(c);		/* it is not a number */
			return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(sawsign = (c == '+'||c == '-'))
			c=getch();
	if(!isdigit(c)){
			ungetch(c);
			if(sawsign)
					ungetch((sign == -1)?'-':'+');
			return 0;
	}
	for(*pn = 0;isdigit(c);c=getch())
			*pn = 10 * *pn + (c - '0');
	if(c=='.')
	{
			while(isdigit(c=getch())){
					*pn=10* *pn+(c-'0');
					power *=10;
			}
			
	}
	*pn =*pn * sign/power;
	if(c != EOF)
			ungetch(c);
	return c;
}



