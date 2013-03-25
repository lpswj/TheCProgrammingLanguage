#include <ctype.h>
#include <math.h>

//atof function:translate the s to double number

double atof(char s[])
{
	double val,power,epow;
	int i,sign,esign=1;

	/*skip the space */
	for(i=0;isspace(s[i]);i++)
			;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
			i++;
	/*calc the integer*/
	for(val=0.0;isdigit(s[i]);i++)
			val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
			i++;
	/*calc the number behind decimal*/
	for(power=1.0;isdigit(s[i]);i++)
	{
		val=10.0*val+(s[i]-'0');
		/*count down the power*/
		power*=10.0;
	}
	if(s[i]=='e')
			i++;
	if(s[i]=='-')
	{
			esign=-1;
			i++;
	}
	for(epow=0.0;isdigit(s[i]);i++)
	{
		epow=10.0*epow+(s[i]-'0');
	}
	return sign*val*pow(10.0,epow*esign)/power;
}
