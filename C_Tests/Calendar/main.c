#include "output.h"

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

static enum Month MonthFromDayOfYear(unsigned day_of_year);
static unsigned WeekDayFromDayOfYear(unsigned day_of_year);

static const char *DAY[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday" };
static const char *MONTH[] =
		{ "January", "February", "March", "April", "May", "June", "July",
				"August", "September", "October", "November", "December", };

int main(void) {
	for (unsigned i = 0; i < 50; i++)
		Out_WriteCalendarLine(i, DAY[WeekDayFromDayOfYear(i)],
				MONTH[MonthFromDayOfYear(i)]);

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
