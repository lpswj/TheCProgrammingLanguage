#include <stdio.h>

/*reverse n bits from the postion p of x*/
unsigned invert(unsigned x,int p,int n);

main()
{
	unsigned x=255;
	x=invert(255,4,2);
	printf("%d\n",x);

}


unsigned invert(unsigned x,int p,int n)
{

		//XOR with  0 no change,XOR with 1 equal reverse.
		return x^(~(~0<<n)<<p);
}



