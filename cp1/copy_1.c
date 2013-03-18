//TO copy the input to the output
//ver1

#include <stdio.h>

main()
{
	int c;

	c = getchar();
	while(c != EOF)
	{
		putchar(c);
		c = getchar();
	}
}
