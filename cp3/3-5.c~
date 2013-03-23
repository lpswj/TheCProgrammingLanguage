#include <stdio.h>
#include <string.h>

void itob(int n,char s[],int b);
void reverse(char s[]);

main()
{
	int t=123;
	char s[1000];
	itob(t,s,2);
	printf("%s",s);
}

void itob(int n,char s[],int b)
{
	int i,sign,result;
	if((sign=n)<0)
			n=-n;
	i=0;
	do
	{
		result=n%b;
		if(result>9)
				result=result-10+'A';
		else
				result=result+'0';
			 
		s[i++]=result;
	}while((n/=b)>0);
	if(sign<0)
			s[i++]='-';
	s[i]='\0';
	reverse(s);
}

void reverse(char s[])
{
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}
