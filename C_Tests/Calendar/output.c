#include "output.h"
#include <stdio.h>

extern void Out_WriteCalendarLine(unsigned day, char const * dayOfWeek,
		char const * month) {
	static FILE *out_file = NULL;

	if (out_file == NULL) {
		out_file = fopen("Calendar.html", "w");
	}

	fprintf(out_file, "%d %s %s<br />", day, dayOfWeek, month);
}
