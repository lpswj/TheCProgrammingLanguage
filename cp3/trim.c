#include <stdio.h>
#include <string.h>

//trim:del the space,tab and \n in the end of string.
int trim(char s[]);

main()
{
	char s[]="abd           ";
	int n=trim(s);
	printf("the space is :%d",n);
	printf("%s",s);
}

int trim(char s[])
{
	int n;
	for(n=strlen(s)-1;n>=0;n--)
			if(s[n]!=' '&&s[n]!='\t'&&s[n]!='\n')
					break;
	s[n+1]='\0';
	return n;
}
