//escape character
#include <stdio.h>

main()
{
	printf("try about some escape character\r");
	// \r means the cursor back to the head of line,so above printf 
	// does not appear,not equal to the \n
	printf("why doesn't appear\n");
	//\v means vertical tabulator 
	printf("hi!\v");
}
