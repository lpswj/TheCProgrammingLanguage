#include <stdio.h>

int strelen(char *s);
int strelen1(char *s);

main()
{
	char *s="waht the hell!";
	printf("The length is %d\n",strlen(s));
	printf("The length is %d\n",strlen1(s));
}

/* strlen:return length of string s */
int strlen(char *s)
{
	int n;

	for(n=0;*s != '\0';s++)
			n++;
	return n;
}

/* new function of strlen */
int strlen1(char *s)
{
	char *p=s;

	while(*p != '\0')
			p++;
	return p-s;
}
