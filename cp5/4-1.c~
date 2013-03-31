#include <stdio.h>
#define MAXLINE 1000

int getline(char *line,int max);
int strrindex(char *source,char *searchfor);
static char* strchr(char *s,int c);


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


int getline(char *s,int lim)
{
	int c; 
	char *p=s;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
			*p++=c;
	if(c=='\n')
			*p++=c;
	*p='\0';
	return (int)(p-s);
}

//return the position where t in s,if not found ,return -1.
int strrindex(char *s,char *t)
{
		char *u,*v,*w;

		if(*t == '\0')
				return 0;
		for(u=s;(u=strchr(u,*t))!=NULL;++u){
				for(v=u,w=t;;)
						if(*++w == '\0')
								return (int)(u-s);
						else if (*++v != *w)
								break;
		}
		return -1;
}

static char* strchr(char *s,int c)
{
	char ch=c;

	for(;*s !=ch;++s)
			if(*s == '\0')
					return NULL;
	return s;
}
