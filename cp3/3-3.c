#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void expand(char s1[],char s2[]);

main()
{
		int i;
		char s2[MAXLINE];
		char s1[]="A-ER-n-z";
		expand(s1,s2);
		printf("%s\n",s2);
}


void expand(char s1[],char s2[])
{
	int i,j,t,start,gap;
	for(i=0,j=0;i<strlen(s1)-1;i++)
	{
			/*the situation to check the left and right of s1*/
			if(s1[i]=='-')
			{

				char left=s1[i-1];
				char right=s1[i+1];
				/*the  situation*/	
				if((isdigit(left)&&isdigit(right)&&(right>left))||
					(islower(left)&&islower(right)&&(right>left))||
					(isupper(left)&&isupper(right)&&(right>left))
				  )
				{
						gap=right-left;
						start=left;
						for(t=1;t<=gap;t++)
								s2[j++]=start+t;
						i++;
				}
				else
						s2[j++]=s1[i];
			}
			else 
					s2[j++]=s1[i];
	}		
	s2[j]='\0';

}
