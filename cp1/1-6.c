#include <stdio.h>

main()
{
	int c;
	c = getchar() != EOF;
	printf("%d\n",c);
	printf("%d\n",EOF);
	//EOF is -1,cause ASCII use 0~255 .
}
