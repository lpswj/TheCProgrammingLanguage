#include <stdio.h>


//void strcpy(char *s,char *t);
void strcpy1(char *s,char *t);
void strcpy2(char *s,char *t);
//int strcmp(char *s,char *t);
int strcmp1(char *s,char *t);
int strlen(char *s);
void strcat(char *s,char *t);
int strend(char *s,char *t);
void strncpy(char *s,char *t,int n);
void strncat(char *s,char *t,int n);
int strncmp(char *s,char *t,int n);

main()
{
	char s[]="azc";
	char t[]="afgdada";
	printf("%d\n",strncmp(s,t,2));
}


/* strcpy: copy t to s;array subscript version */
void strcpy(char *s,char *t)
{
	int i=0;
	i=0;
	while((s[i]=t[i]) != '\0')
			i++;
}

/* strcpy : copy t to s;pointer version */
void strcpy1(char *s,char *t)
{
	while((*s++=*t++) != '\0')
			;
}


/* strcpy : copy t to s;pointer version 2 */
void strcpy2(char *s,char *t)
{
	while(*s++=*t++)
			;
}

/* strcmp: return <0 if s<t,0 if s=t,>0 if s>t */
int strcmp(char *s,char *t)
{
		int i ;

		for(i=0;s[i]==t[i];i++)
				if(s[i]=='\0')
						return 0;
		return s[i]-t[i];
}

/* strcmp : pointer version */
int strcmp1(char *s,char *t)
{
		for(;*s==*t;s++,t++)
				if(*s=='\0')
						return 0;
		return *s-*t;
}

/* strlen: return the length of string s */
int strlen(char *s)
{
	char *p=s;
	while(*p != '\0')
			p++;
	return p-s;
}


/*strcat : cat the t to the end of s */
void strcat(char *s,char *t)
{
	char *p;
	p=s+strlen(s);	
	while(*p++=*t++)
			;
}

/* strend : return 1 if string t  in the end of s ,else return 0*/
int strend(char *s,char *t)
{
	int i=strlen(t);
	/* *(s+strlen(s) is the '\0',the last element need -1 */
	s+=strlen(s)-1;
	t+=strlen(t)-1;
	while((*s-- == *t--)&& (i !=0))
			i--;
	if(!i)
			return 1;
	else 
			return 0;
}	

/* strncpy: copy n element in the head of t to s */
void strncpy(char *s,char *t,int n)
{
	int i=0,count;

	int len=strlen(t);
	count=(len>n)?n:len;
	while(i<count){
			*s++=*t++;
			i++;
	}
	*s='\0';
}

/* strncat:cat the n element of t to the s */
void strncat(char *s,char *t,int n)
{
	
	int i=0,count;

	int len=strlen(t);
	s += strlen(s);
	count=(len>n)?n:len;
	while(i<count){
			*s++=*t++;
			i++;
	}
	*s='\0';
}

/* strncmp:compare the first n element of s to t */
int strncmp(char *s,char *t,int n)
{
	int i;
	for(i=0;i<n && *s==*t;i++,s++,t++)
			;
	if(i==n)
			return 0;
	else
			return *s-*t;
}
