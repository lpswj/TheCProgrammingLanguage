#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *,int );

int main(int argc,char *argv[])
{
	int c,number=0,except=0,found=0;
	long lineno=0;
	char line[MAXLINE];

	while(--argc > 0 && (*++argv)[0] == '-')
			while(c =*++argv[0]){
					switch(c){
							case 'n':
									number=1;
									break;
							case 'x':
									except=1;
									break;
							default:
									printf("grep:illegal option %c\n",c);
									argc = 0;
									found = -1;
									break;
					}
			}
	if(argc != 1)
			printf("Usage : grep -n -x pattern.\n");
	else
			while(getline(line,MAXLINE)>0){
					lineno++;
					if((strstr(line,*argv) != NULL) != except){
							if(number)
									printf("%ld: ",lineno);
							printf("%s",line);
							found++;
					}
			}
	return found;
}
