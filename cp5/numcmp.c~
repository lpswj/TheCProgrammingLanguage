#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* numcmp: sort s1 and s2 by numeric order */

extern int reverse;
extern int upper;

int numcmp(void *p1,void *p2)
{
		char *s1=reverse?p2:p1;
		char *s2=reverse?p1:p2;
		double v1,v2;

		v1=atof(s1);
		v2=atof(s2);
		if(v1<v2)
				return -1;
		else if (v1>v2)
				return 1;
		else
				return 0;
}

int pstrcmp(void *p1,void *p2)
{
		char *s1=reverse?p2:p1;
		char *s2=reverse?p1:p2;
		if(upper){
				while(*s1++ != '\0')
						toupper(*s1);
				while(*s2++ !='\0')
						toupper(*s2);
		}
						
		return strcmp(s1,s2);
}
