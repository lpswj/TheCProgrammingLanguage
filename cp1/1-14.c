// type the histogram of each character

#include <stdio.h>

main()
{
	int rate[26];
	int c,i,j;

	for (i=0;i<26;i++)
	{
		rate[i]=0;
	}
	
	while ((c = getchar()) != EOF)
	{
		if (c >='a'&& c<='z')
				++rate[c-'a'];
		else if (c >='A'&&c<='Z')
				++rate[c-'A'];
	}
	
	//output the historgram
	printf("******the histogram for character*****\n");
	for (i=0;i<26;i++)
	{		
			if(rate[i]>0)
			{
				printf("%c: ",'a'+i);
				for(j=0;j<rate[i];j++)
						printf("**");
				printf("\n");
			}
	}

}

