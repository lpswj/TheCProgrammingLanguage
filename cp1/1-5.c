//the fahrenheit to celsius temperature table
//new version:update the type of temperature,from int to float
//using for statement to output by reversed order
#include <stdio.h>

main()
{
		int fahr;
		for (fahr = 300; fahr >= 0;fahr = fahr -20)
		{
			printf("%3.0d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
		}
}
