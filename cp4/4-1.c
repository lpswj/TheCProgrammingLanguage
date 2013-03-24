#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[],int max);
int strrindex(char source[],char searchfor[]);

//the pattern under searching
char pattern[]="ould";

int main()
{
	char line[MAXLINE];
	int found=0;
	int pos;

	while(getline(line,MAXLINE)>0)
			if((pos=strrindex(line,pattern))>=0)
			{
					printf("%s",line);
					printf("the pos found in the rightmost is %d",pos);
					found++;
			}
	return found;
}


int getline(char s[],int lim)
{
	int c ,i;
	i=0;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
			s[i++]=c;
	if(c=='\n')
			s[i++]=c;
	s[i]='\0';
	return i;
}

//return the position where t in s,if not found ,return -1.
int strrindex(char s[],char t[])
{
	int i,j,k;

	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
				;
		if(k>0 && t[k]=='\0')
				return i;
	}
	return -1;

}
