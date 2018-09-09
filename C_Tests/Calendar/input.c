#include"input.h"

static unsigned AsciiToNumber(char ascii);

extern unsigned In_ReadCalendarYear(char **argv) {
	unsigned millenia = AsciiToNumber(argv[1][0]) * 1000;
	unsigned hundreth = AsciiToNumber(argv[1][1]) * 100;
	unsigned decade = AsciiToNumber(argv[1][2]) * 10;
	unsigned one = AsciiToNumber(argv[1][3]);

	return millenia + hundreth + decade + one;
}

static unsigned AsciiToNumber(char ascii) {
	return ascii - 48;
}
