/* entab:replace the space string with minium number of tabs and spaces */

#include <stdio.h>

#define SPACE ' '
#define MAXLINE 1000
#define TAB2SPACE 4

int getline(char *s,int lim);

main()
{
	char line[MAXLINE];
	char *p=&line[0],*s;
	int  spacecount;

	while(getline(line,MAXLINE)>0){
			spacecount=0;
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
					if(spacecount == TAB2SPACE)
					{
							p=p-3;
							*p='\t';
							s=p;
							s++;
							while(*(s+3) != '\0')
							{
									*s=*(s+3);
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
