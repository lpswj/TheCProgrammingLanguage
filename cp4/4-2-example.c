#include <stdio.h>

#define MAXLINE 100

main()
{
	double sum,atof(char []);
	int atoi(char s[]);
	char line[MAXLINE];
	int getline(char line[],int max);

	sum =0;
	while(getline(line,MAXLINE)>0)
	{
			printf("the float number is \t%g\n",sum+=atof(line));
	}
	return 0;
}
