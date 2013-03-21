#include <stdio.h>
#define MAXLINE 1000

void escape(char s[],char t[]);
void r_escape(char u[],char s[]);

main()
{
	char s[MAXLINE];
	char u[MAXLINE];
	char t[MAXLINE]="hey	 jude,don't make	 it bad!";
//	char t[MAXLINE]="hey\\tjude,don't make\\tit bad!";
	escape(s,t);
	printf("%s\n",s);
	r_escape(u,s);
	printf("%s\n",u);
}


void escape(char s[],char t[])
{	
	int i,j;
	for(j=0,i=0;t[j]!='\0';j++,i++)
	{		switch(t[j])
			{
				case '\n':
						s[i]='\\';
						s[i+1]='n';
						i++;
						break;
				case '\t':
						s[i]='\\';
						s[i+1]='t';
						i++;
						break;
				default:
						s[i]=t[j];
						break;  //dont' forget it
			}
	}
	s[i]='\0';
}


void r_escape(char s[],char t[])
{
	
	int i,j,flag;
	flag=0;
	for(j=0,i=0;t[j]!='\0';j++)
	{		
			switch(t[j])
			{
			//forget the i ,in case '\\',s[i] is not value
				case '\\':
						flag=1;
						break;
				default:
						if(flag&&t[j]=='t')
						{
							s[i++]='\t';
							flag=0;
						}
						else if(flag&&t[j]=='n')
						{
							s[i++]='\n';
							flag=0;
						}
						else
								s[i++]=t[j];
						break;  //dont' forget it
						
			}
	}
	s[i]='\0';
}
