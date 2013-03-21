#include <stdio.h>

int lower(int c)
{
	c=(c>='A'&&c<='Z')?(c+'a'-'A'):c;
	return c;
}

main()
{

		char c='Z';
		printf("%c\n",lower(c));
}
