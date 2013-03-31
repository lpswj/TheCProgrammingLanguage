/* the pointer version */
#include <stdio.h>
#include <string.h>

void reverse(char *s);

main()
{
	char s[]="hey man!";
	reverse(s);
	printf("%s\n",s);
}

void reverse(char *s)
{
		char *p,tmp;
		p=s+strlen(s)-1;
		while(s < p){
				tmp=*s;
				*s++ = *p;
				*p-- = tmp;
		}
}
