//replace the tab with \t ,backspace with \b , backslash with \\
//Date :2012/01/24
//mark :note that '==' and '=' 
//ctrl+h equals backspace.

#include <stdio.h>

main()
{
	int c;
	while( (c=getchar()) != EOF)
	{
		if(c =='\t')
		{
			putchar('\\');
			putchar('t');		
		}
		else if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else 
			putchar(c);	
	}
}
