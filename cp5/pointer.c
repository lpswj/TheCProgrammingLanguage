#include <stdio.h>

main()
{
	int x=1,y=2,z[10];

	swap(&x,&y);
	printf("x=%d y=%d\n",x,y);
}

void swap(int *x,int *y)
{
	int temp;

	temp=*x;
	*x=*y;
	*y=temp;
}
