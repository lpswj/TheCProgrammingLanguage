//read a array of text,and print longest line.
//Date:2013.01.28 unfinished
//Date:2013.03.18

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000	/* the max line length to input */

int getline(char *s,int maxline);
void copy(char to[],char from[]);

/*type the longest line */
int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=getline(line,MAXLINE))>0)
			if(len>max){
				max=len;
				copy(longest,line);
			}
	if(max>0)
			printf("%s",longest);
	return 0;
}

/* getline function :read a line to the s and return its length */
int getline(char *s,int lim)
{
	int c ;
	char *p;

	p=s;
	while(--lim>0 && (c=getchar()) != EOF && c != '\n')
			*p++=c;
	if(c=='\n')
			*p++=c;
	*p='\0';
	return (int)(p-s);
}

void copy(char to[],char from[])
{
	int i;

	i=0;
	while((to[i]=from[i])!='\0')
			++i;
}
