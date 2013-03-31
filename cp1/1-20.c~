/* detab: replace the tab in the input with space */
#include <stdio.h>

#define SPACE ' '
#define TAB	'\t'
#define MAXLINE 1000

int getline(char *s,int lim);

int main()
{
		int tabsize=5;
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




