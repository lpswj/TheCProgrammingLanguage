//type the histogram of word length.
#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int wlen[30]; //the array of word length.
	int c,i,j,count=0;
//	int state=OUT;

	for(i=0;i<30;i++)
			wlen[i]=0;

	//count the length.
	while((c=getchar())!=EOF)
	{
			if(c==' '||c=='\t'||c=='\n')
			{
			//		state=OUT;
					if(count>0)
					{
						++wlen[count];
					}
					count=0;
			}
			else 
					++count	;
	}

	//print the histogram
	printf("*******the word length histogram*******\n");
	for(i=0;i<30;i++)
	{
			if(wlen[i]>0)   //better write style if(wlen[i])
			{
				for(j=0;j<wlen[i];j++)
						printf("***");
				printf("\n");
			}
	}
}
