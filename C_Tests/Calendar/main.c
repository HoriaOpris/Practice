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

static struct calendar c;
static const char *DAY[Number_of_days] = { "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };
static const char *MONTH[Number_of_months] = { "January", "February", "March",
		"April", "May", "June", "July", "August", "September", "October",
		"November", "December", };

int main(void) {
	printf("Day of the year:%d \n", 8);

	printf("Day of Week: %s \n", DAY[WeekDayFromDayOfYear(8)]);
	c.month = MonthFromDayOfYear(c.day);

	//calc month
	printf("Month: %s \n", MONTH[c.month]);

	return 0;
}

static unsigned WeekDayFromDayOfYear(unsigned day_of_year) {
	return day_of_year % 7;
}

static enum Month MonthFromDayOfYear(unsigned day_of_year) {
	if (day_of_year <= 30)
		return January;
	else if ((day_of_year > 30) && (day_of_year <= 59))
		return February;
	else if ((day_of_year > 59) && (day_of_year <= 90))
		return March;
	else if ((day_of_year > 90) && (day_of_year <= 120))
		return April;
	else if ((day_of_year > 120) && (day_of_year <= 151))
		return May;
	else if ((day_of_year > 151) && (day_of_year <= 181))
		return June;
	else if ((day_of_year > 181) && (day_of_year <= 212))
		return July;
	else if ((day_of_year > 212) && (day_of_year <= 242))
		return August;
	else if ((day_of_year > 242) && (day_of_year <= 273))
		return September;
	else if ((day_of_year > 273) && (day_of_year <= 303))
		return October;
	else if ((day_of_year > 303) && (day_of_year <= 334))
		return November;
	else if ((day_of_year > 334) && (day_of_year <= 364))
		return December;
	else
		return January; //TODO: Error handling
}
