#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

main()
{
	char s[]="123";
	int result;
	result=atoi(s);
	printf("the result is %d\n",result);
}



int atoi(char s[])
{
	int i,n,sign;
	/*skip the white space*/
	for(i=0;isspace(s[i]);i++)
			;
	sign=(s[i]=='-')?-1:1;
	/*skip the symbol*/
	if(s[i]=='+'||s[i]=='-')
			i++;
	for(n=0;isdigit(s[i]);i++)
			n=10*n+(s[i]-'0');
	return sign*n;		
}


