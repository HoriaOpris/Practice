#include<stdio.h>

enum Day {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
	Number_of_days
};

enum Month {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
	Number_of_months
};

struct calendar {
	unsigned day;
	enum Day day_of_week;
	enum Month month;
};

static enum Month MonthFromDayOfYear(unsigned day_of_year);

struct calendar c;
const char *DAY[Number_of_days] = { "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };
const char *MONTH[Number_of_months] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November",
		"December", };

int main(void) {

	c.day = 32;

	printf("Day of the year:%d \n", c.day);
	//calc day of week
	c.day_of_week = c.day % (7 - 1);

	printf("Day of Week: %s \n", DAY[c.day_of_week]);
	c.month = MonthFromDayOfYear(c.day);

	//calc month
	printf("Month: %s \n", MONTH[c.month]);

	return 0;
}

static enum Month MonthFromDayOfYear(unsigned day_of_year) {
	if (day_of_year <= 31)
		return January;
	else if ((day_of_year > 31) && (day_of_year <= 60))
		return February;
	else if ((day_of_year > 60) && (day_of_year <= 91))
		return March;
	else if ((day_of_year > 91) && (day_of_year <= 121))
		return April;
	else if ((day_of_year > 121) && (day_of_year <= 152))
		return May;
	else if ((day_of_year > 152) && (day_of_year <= 182))
		return June;
	else if ((day_of_year > 182) && (day_of_year <= 213))
		return July;
	else if ((day_of_year > 213) && (day_of_year <= 243))
		return August;
	else if ((day_of_year > 243) && (day_of_year <= 274))
		return September;
	else if ((day_of_year > 274) && (day_of_year <= 304))
		return October;
	else if ((day_of_year > 304) && (day_of_year <= 335))
		return November;
	else if ((day_of_year > 335) && (day_of_year <= 365))
		return December;
	else
		return January; //TODO: Error handling
}
