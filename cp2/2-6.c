//try to write down the process,make clear it ,and write it . 
#include <stdio.h>

/*getbits:get n bits from position p */
unsigned getbits(unsigned x,int p,int n);

/*set the n bits of x from position p */
unsigned setbits(unsigned x,int p ,int n ,unsigned y);

main()
{
	unsigned x=255;
	unsigned y=13;
	x=setbits(x,4,4,y);
	printf("%d\n",x);

}


unsigned setbits(unsigned x,int p ,int n ,unsigned y)
{
		x=x&~(~(~0<<n)<<p);
		y=(y&~(~0<<n))<<p;
		x|y;
		return x;
}

unsigned getbits(unsigned x,int p,int n)
{
	return (x>>(p+1-n))&~(~0<<n);
}


