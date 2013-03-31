#include <stdio.h>
#include <string.h>
#define MAXLINE 1000



int getline(char *p,int lim)
{
	int c;
	char *s=p;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
			*s++=c;
	if(c=='\n')
			*s++=c;
	*s='\0';
	return (int)(s-p);
}

