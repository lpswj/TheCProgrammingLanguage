//read a array of text,and print longest line.
//Date:2013.01.28

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[],char from);


//print the longest line
main()
{
	int len;	//the length of current input
	int max;	//the longest line that have found
	char line[MAXLINE];	//current input
	char longest[MAXLINE];	//save the longest line

	max=0;
	while((len=getline(line,MAXLINE))>0)
			if(len>max)
			{
				max=len;
				copy(longest,line);
			}
	//if it exists
	if(max>0)
			printf("%s",longest);
	return 0;
	
}

//getline function:read a line and return its length
int getline(char s[],int lim)
{
	int c , i;
	for()
}
