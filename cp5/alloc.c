#define ALLOCSIZE 10000		/* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)
{
	if(allocbuf +ALLOCSIZE-allocp>=n){
			allocp += n;
			return allocp-n;	/* old p */
	}
	else 						/* not enough room */
			return 0;
}

void afree(char *p)				/* free storage pointed to by p */
{
		if(p >= allocbuf && p < allocbuf +ALLOCSIZE)
				allocp = p;
}
