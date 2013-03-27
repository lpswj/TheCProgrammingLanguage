/* the common wrong when using the #define */
#include <stdio.h>

/* while call square(z+1),the answer is wrong */
#define square(x) x*x

/* while using max(i++,j++),the answer is wrong*/
#define max(A,B) ((A)>(B))?(A):(B)


