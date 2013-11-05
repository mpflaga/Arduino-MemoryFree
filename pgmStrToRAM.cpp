#include <avr/pgmspace.h>
#include <stdlib.h>

char *to_print;
char *pgmStrToRAM(PROGMEM char *theString) {
	free(to_print);
	to_print=(char *) malloc(strlen_P(theString) + 1);
	strcpy_P(to_print, theString);
	return (to_print);
}