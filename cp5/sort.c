#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000	/* max #lines to be stored */

char *lineptr[MAXLINES];	/* pointer to text lines */

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);

int readlines2(char lines[][MAXLEN],int maxlines);

/* sort input lines */
int main()
{
	int nlines;		/* number of input lines read */

	if((nlines=readlines(lineptr,MAXLINES)) >= 0){
			qsort(lineptr,0,nlines-1);
			writelines(lineptr,nlines);
			return 0;
	}else{
			printf("error:input too big to sort\n");
			return 1;
	}
}

#define MAXLEN 1000		/* max length of any input file */
int getline(char *,int );
char *alloc(int);

/* readlines:read input lines */
int readlines(char *lineptr[],int maxlines)
{
	int len,nlines;
	char *p,line[MAXLEN];

	nlines=0;
	while((len=getline(line,MAXLEN)) >0)
					if(nlines >= maxlines || (p=alloc(len)) == NULL)
							return -1;
					else{
							line[len-1] = '\0';	/* delete newline */
							strcpy(p,line);
							lineptr[nlines++] = p;
					}
	return nlines;
}

/* writelines:write output lines */
void writelines(char *lineptr[],int nlines)
{
	/*
	int i;
	for(i=0;i<nlines;i++)
			printf("%s\n",lineptr[i]);		
	*/
	while(nlines-->0)
			printf("%s\n",*lineptr++);
}

/* qsort:sort v[left]..v[right] into increasing order */
void qsort(char *v[],int left,int right)
{
	int i,last;
	void swap(char *v[],int i,int j);

	if(left >= right)
			return 0;
	swap(v,left,(left+right)/2);
	last = left;
	for(i=left+1;i<=right;i++)
			if(strcmp(v[i],v[left])<0)
					swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

/* swap:interchange v[i] and v[j] */
void swap(char *v[],int i,int j)
{
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

/* getline:get the input line */
int getline(char *s,int lim)
{
	int c;
	char *p=s;
	while(--lim>0&&(c=getchar()) != EOF && c != '\n')
			*p++=c;
	if(c=='\n')
			*p++=c;
	*p='\0';
	return (int)(p-s);
}

/* store lines in an array */
int readlines2(char lines[][MAXLEN],int maxlines)
{
	int len,nlines;
	
	nlines=0;
	while((len=getline(lines[nlines],MAXLEN))>0)
			if(nlines >= maxlines)
					return -1;
			else
					lines[nlines++][len-1]='\0';	//delete the newline
	return nlines;
}
