/* entab:replace the space string with minium number of tabs and spaces */

#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
#define MAXLINE 1000

int getline(char *s,int lim);

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	char *p,*s;
	int  spacecount;
	/* the number of tab to sapce */
	int num=4;
	if(argc == 2)
			num=atoi(argv[1]);

	while(getline(line,MAXLINE)>0){
			spacecount=0;
			p=&line[0];
			while(*(p++) != '\0'){
					if(*p == SPACE )
					{
							spacecount++;
					}
					if(*p != SPACE)
					{
							spacecount=0;
					}
					/* now we have enough spaces to replace them with a tab*/
					if(spacecount == num)
					{
							p=p-(num-1);
							*p='\t';
							s=p;
							s++;
							while(*(s+(num-1)) != '\0')
							{
									*s=*(s+(num-1));
									s++;
							}
							spacecount=0;
							*s='\0';
					}
			}
			printf("%s",line);
	}
	return 0;
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
