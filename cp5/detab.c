/* detab: replace the tab in the input with space */
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
#define TAB	'\t'
#define MAXLINE 1000

int getline(char *s,int lim);

int main(int argc,char *argv[])
{
		int tabsize=5;

		if(argc == 2)
				tabsize=atoi(argv[1]);
		char line[MAXLINE];
		char *p=&line[0];
		while(getline(p,MAXLINE)>0){
				while(*p != '\0'){
						if(*p == TAB)
						{
								for(int i=0;i<tabsize;i++){		
										putchar(SPACE);
								}
								p++;
						}
						else
						{
								putchar(*p);
								p++;
						}
				}
		}
		return 0;
}

int getline(char *s,int lim)
{
		int c;
		char *p=s;
		while(--lim>0 && (c=getchar()) != EOF && c !='\n')
				*p++=c;
		if(c == '\n')
				*p++=c;
		*p='\0';
		return (int)(p-s);
}




