/* the common wrong when using the #define */
#include <stdio.h>

/* while call square(z+1),the answer is wrong */
#define square(x) x*x

/* while using max(i++,j++),the answer is wrong*/
#define max(A,B) ((A)>(B))?(A):(B)

/* #expr equals to "expr"*/
#define dprint(expr) printf(#expr " =%g\n",expr )

#define swap(t,x,y) do{t temp=x;x=y;y=temp;}while(0)


//#if !defined(HDR)
#ifndef HDR
#define HDR
#include "hdr.h"
#endif

#if SYSTEM == SYSV
	#define HDR "sysv.h"
#elif SYSTEM == BSD
	#define HDR "bsd.h"
#elif SYSTEM ==MSDOS
	#define HDR "msdos.h"
#else
	#define HDR "default.h"
#endif
#include HDR

