/* the pointer version */
#include <stdio.h>
#include <ctype.h>

int atoi(char *s);

main()
{
	char s[]="123";
	int result;
	result=atoi(s);
	printf("the result is %d\n",result);
}



int atoi(char *s)
{
	int n=0,sign;
	/*skip the white space*/
	while(isspace(*s))
			s++;
	sign=(*s=='-')?-1:1;
	/*skip the symbol*/
	if(*s=='+'||*s=='-')
			s++;
	while(isdigit(*s))
			n=10*n+(*s++ -'0');
	return sign*n;		
}


