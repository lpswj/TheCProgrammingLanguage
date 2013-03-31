/* pointer version */
#include <stdio.h>

int day_of_year(int year,int month,int day);
int month_day(int year,int yearday,int *pmonth,int *pday);

static char daytab[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

main()
{
		int month,day;
		month_day(2003,111,&month,&day);
		printf("month : %d \t day: %d\n",month,day);
}



/* day_of_year: set day of year from month&day */
int day_of_year(int year,int month,int day)
{
	int i,leap;
	char *p;
	leap=year%4 ==0 && year%100 !=0 || year%400 ==0;
	/* limit check */
	if(year<1752||month<0 || month>12 ||day<1)
	{
			printf("invaild date!");
			return -1;
	}			
	if(day>daytab[leap][month])
	{
			printf("invaild date!");
			return -1;
	}			
	p=&daytab[leap][1];
    for(i=1;i<month;i++)
	{
			day +=*p;
			++p;
	}
	return day;
}

/* month_day:set month,day from day of year */
int month_day(int year,int yearday,int *pmonth,int *pday)
{
	int i,leap;
	char *p;

	leap=year%4 ==0 && year%100 !=0 || year%400 ==0;
	if(year<1752 || yearday<1 || yearday > 365+leap)
	{
			printf("invaild date!");
			return -1;
	}
	p=&daytab[leap][1];
	for(i=1;yearday>*p;i++)
	{
			yearday -= *p;
			++p;
	}
	*pmonth = i;
	*pday = yearday;
}
