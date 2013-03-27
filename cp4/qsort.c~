#include <stdio.h>

void qsort(int v[],int left,int right);
void swap(int v[],int i,int j);

main()
{
		int v[]={1,3,5,7,9,2,4,6,8,0};
		qsort(v,0,9);
		for(int i=0;i<10;i++)
				printf("%d ",v[i]);

}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[],int left,int right)
{
	int i, last;
	if(left >= right)	/* do nothing if array contains */
			return;		/* fewer than two elements */
	swap(v,left,(left+right)/2);	/* move partition elem to v[0] */
	last = left;
	for(i = left + 1;i <= right;i++)	/* partition */
			if(v[i] < v[left])
					swap(v,++last,i);
	swap(v,left,last);			/* restore partition elem */
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[],int i,int j)
{
		int temp;

		temp=v[i];
		v[i]=v[j];
		v[j]=temp;
}
