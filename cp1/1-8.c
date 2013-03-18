//Count the space,tab and newline number.
//Date 2013/01/24

#include <stdio.h>

main()
{	
	int c;	
	int space=0,tab=0,nl=0;
	while((c=getchar()) != EOF)
	{
		if(c == ' ')
				++space;
		else if (c == '\t')
				++tab;
		else if (c == '\n')
				++nl;
		else
				;
	}
	printf("the number of space is %d\n",space);
	printf("the number of tab is %d\n",tab);
	printf("the number of newline is %d\n",nl);
}
