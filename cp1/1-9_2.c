//input copy to the output,and replace the multi-space with single space
//Date:2012/01/24
//another way to solve the problem

#include <stdio.h>

main()
{
	int c,lastChar;

	while((c=getchar()) != EOF)
	{
		if(c != ' ')
		{
			putchar(c);
		}
		else if (lastChar != ' ')
		{
			putchar(c);
		}
		lastChar = c;
	}
}
