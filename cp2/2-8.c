#include <stdio.h>

/*rotate right the bits */
unsigned rightrot(unsigned x,int n);

main()
{
	unsigned x=247;
	printf("%d\n",rightrot(x,3));

}

int wordlength()
{
	int i;
	unsigned v= (unsigned)~0;
	for(i=1;(v=v>>1)>0;++i)
			;
	return i;
}

unsigned rightrot(unsigned x,int n)
{
		unsigned low;
		if((n=n%wordlength())>0)
		{
		low=x&(~(~0<<n));
		low=low<<(wordlength()-n);
		x=x>>n;
		x=x|low;
		}
		return x;
		
}



