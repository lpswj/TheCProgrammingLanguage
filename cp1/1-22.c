/* write a program which can break the long line into serval lines,
 * the position where to break is before the number n row and the behind 
 * the last space string. 
 */

#include <stdio.h>

#define SPACE ' '
#define MAXLINE 1000

int getline(char *s,int lim);

int main()
{
		int rowcount,space,isspace=0;
		int i=0,j=0;
		int FOLDLENGTH=10;
		char line[MAXLINE],nl[MAXLINE];

		while((len=getline(line,MAXLINE)) > 0){
				if(len < FOLDLENGTH)
				{
				}
				else{
					rowcount=0;
					while(*(line++) != '\0'){
							if(line[i] == ' ')


							
							rowcount++;
					}
				}
		}
		return 0;
}

int getline(char *s,int lim)
{
		int c;
		char *p=s;
		while(--lim>0 && (c=getchar()) != EOF & c != '\n')
				*p++=c;
		if(c == '\n')
				*p++=c;
		*p='\0';
		return (int)(p-s);
}
