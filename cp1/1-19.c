//add a reverse(s) function to reverse the string
//Date:2013.03.18
//The first version written by myself.
/*Mark:
1.At first,I try to use getline() to get the length of line,unfortunately,
the getline() don't input the string S.
2.use less array(memeory address ) while writting program.
3.while using printf("%s",line),line[len]='\n',line[len+1]='\0'.
*/
#include <stdio.h>
#define MAXLINE 1000	/* the max line length to input */

int getline(char line[],int maxline);
//void reverse(char to[],char from[],int len);
void reverse(char s[],int len);


/*type the longest line */
int main()
{
	int len;
	int max;
	char line[MAXLINE];

	while((len=getline(line,MAXLINE))>0)
	{
			reverse(line,len);
			printf("%s",line);
//			for(int i=0;i<len;i++)
//					printf("%c",rline[i]);
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

//use 2 array,not a good solution.
/*
 * void reverse(char to[],char from[],int len)
{
	int i=0,j=0;
	for(i=0;i<len;i++)
				to[len-i-1]=from[i];
	to[len]='\n';
	to[len+1]='\0';
}

*/

void reverse(char s[],int len)
{
	int i,j;
	char tmp;
	for(i=0, j=len-1;i<j;i++,j--)
	{
		tmp=s[i];
		s[i]=s[j];
		s[j]=tmp;
	}
}
