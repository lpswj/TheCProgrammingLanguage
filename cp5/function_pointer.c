/* to pointer to function */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *linptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(void *lineptr[],int left,int right,int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc,char *argv[])
{
		int nlines;
		int numeric = 0;

		//use strcmp to read the argv[]
		if(argc > 1 &&strcmp(argv[1],"-n") == 0)
				numeric = 1;
		if((nlines = readlines(lineptr,MAXLINES)) >= 0){
				qsort((void **)lineptr,0,nlines-1,
								(int (*)(void *,void*))(numeric ? numcmp :strcmp));
				writelines(lineptr,nlines);
				return 0;
		}else{
				printf("input too big to sort\n");
				return 1;
		}
}

void qsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
		int i,last;

		void swap(void *v[],int,int);

		if(left >=right)
				return ;
		swap(v,left,(left+right) / 2);
		last = left;
		for(i=left+1;i<=right;i++)
				if((*comp)(v[i],v[left]) < 0)
						swap(v,++last,i);
		swap(v,left,last);
		qsort(v,left,last-1,comp);
		qsort(v,last+1,right,comp);
}


void swap(void *v[],int i,int j)
{
		void *temp;

		temp=v[i];
		v[i]=v[j];
		v[j]=temp;
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
