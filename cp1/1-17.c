//type out the line whose length is over 80 
//Date:2013.03.18

#include <stdio.h>
#define MAXLINE 1000	/* the max line length to input */
#define POINT 80

int getline(char line[],int maxline);
void copy(char to[],char from[]);

/*type the longest line */
int main()
{
	int len;
	char line[MAXLINE];
	while((len=getline(line,MAXLINE))>0)
			if(len>POINT){
				printf("%s",line);
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

