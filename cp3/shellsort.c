#include <stdio.h>

void shellsort(int v[],int n);


main()
{
	int i;
	int v[8]={9,8,7,6,5,4,3,2};
	shellsort(v,8);
	for (i=0;i<8;i++)
			printf("%d ",v[i]);
	printf("\n");
}


void shellsort(int v[],int n)
{
	int gap,i,j,temp;

	for(gap=n/2;gap>0;gap/=2)
			for(i=gap;i<n;i++)
					for(j=i-gap;j>=0&&v[j]>v[j+gap];j-=gap)
					{
						temp=v[j];
						v[j]=v[j+gap];
						v[j+gap]=temp;
					}
}
