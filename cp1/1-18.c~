//del the blank or the tab in the input line,and del the blank line.
//Date:2013.03.18

#include <stdio.h>
#define MAXLINE 1000	/* the max line length to input */

int getline(char line[],int maxline);
void copy(char to[],char from[]);

/*type the longest line */
int main()
{
	int len;
	int max;
	char line[MAXLINE];

	while((len=getline(line,MAXLINE))>0)
	{
			while(line[len-2]==' '||line[len-2]=='\t')
					--len;
			if(len>1)
			{
			for (int i=0;i<len;i++)
					printf("%c",line[i]);
			}
	}	
	return 0;
}

/* getline function :read a line to the s and return its length */
int getline(char s[],int lim)
{
	int c ,i ;
	for (i=0;i<lim-1 && (c=getchar())!=EOF&&c!='\n';++i)
			s[i]=c;
	if(c=='\n'){
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}

void copy(char to[],char from[])
{
	int i;

	i=0;
	while((to[i]=from[i])!='\0')
			++i;
}
