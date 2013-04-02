/* tail: print the last n row input */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 5000
#define MAXLEN 1000

char *lineptr[MAXLINE]; 		/* max #lines to be stored */

int getline(char *s,int lim);
int readlines(char *lineptr[],int nlines);
char *alloc(int);

int main(int argc,char *argv[])
{
		int nlines;			/* number of input lines read*/
		int last,i,j,k;
		char cmd[MAXLINE];
		char *p=&cmd[0];

		/* in default,the last is 10 */
		if(argc == 1)
				last=10;		/* the last 10 lines to printf */
		else if(argc == 2 && (*++argv)[0] == '-')
		{
				while(*++argv[0] != '\0'){
						*(p++)= *argv[0];
				}
				*p= '\0';
				/* check the input */
				for(i=0;cmd[i] != '\0';i++){
						if(isdigit(cmd[i]))
								;
						else 
						{
								printf("Usage: tail -n \n");
								return 0;
						}
				}
				last=atoi(cmd);
		}
		else{ 
				printf("Usage: tail -n \n");
				return 0;
		}
		nlines=readline(lineptr,MAXLINE);
		if(nlines <= last){
				for(j=0;j<nlines;j++)
						printf("%s\n",lineptr[j]);
		}
		else{
				for(k=nlines-last;k<nlines;k++)
						printf("%s\n",lineptr[k]);
		}
		return 0;
}

int readline(char *lineptr[],int maxlines)
{
		int len,nlines;
		char *p,line[MAXLEN];

		nlines=0;
		while((len=getline(line,MAXLEN))>0)
						if(nlines >= maxlines || (p=alloc(len)) == NULL)
								return -1;
						else{
								line[len-1]='\0';
								strcpy(p,line);
								lineptr[nlines++]=p;
						}
		return nlines;
}

int getline(char *s,int lim)
{
		int c;
		char *p=s;
		while(--lim>0 && (c=getchar()) != EOF && c != '\n')
				*p++=c;
		if(c == '\n')
				*p++=c;
		*p='\0';
		return (int)(p-s);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
		if(allocbuf+ALLOCSIZE-allocp >= n){
				allocp += n;
				return allocp-n;
		}
		else 
				return 0;
}

void afree(char *p)
{
		if(p >=allocbuf && p < allocbuf+ALLOCSIZE)
				allocp = p;
}




