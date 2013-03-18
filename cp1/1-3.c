//the fahrenheit to celsius temperature table
//new version:update the type of temperature,from int to float
//the exercise 1-3:add a title on the top
#include <stdio.h>

main()
{
	float fahr,celsius;
	int lower,upper,step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr=lower;
	printf("#Fahrenheit To Celsius Temperature Comparation#\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr + step;
	}
}
