//input copy to the output,and replace the multi-space with single space
//Date:2012/01/24

#include <stdio.h>

main()
{
	int c,flag=1;

	while((c=getchar()) != EOF)
	{
		if(c != ' ')
		{
			putchar(c);
			flag =1;
		}
		else if (flag)
		{
			putchar(c);
			flag =0;
		}
	}
	
}
