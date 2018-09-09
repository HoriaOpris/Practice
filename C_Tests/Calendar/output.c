#include "output.h"
#include <stdio.h>

extern void Out_WriteCalendarLine(unsigned day, char const * dayOfWeek,
		char const * month, unsigned year) {
	static FILE *out_file = NULL;

	if (out_file == NULL) {
		out_file = fopen("Calendar.html", "w");
	}

	fprintf(out_file, "%d %s %s %d<br />", day, dayOfWeek, month, year);
}
