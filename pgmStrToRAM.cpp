#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>

char *to_print;
char *pgmStrToRAM(PROGMEM const char *theString) {
	free(to_print);
	to_print=(char *) malloc(strlen_P(theString) + 1);
	strcpy_P(to_print, theString);
	return (to_print);
}