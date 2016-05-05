#include <avr/pgmspace.h>

#define getPSTR(s) pgmStrToRAM(PSTR(s))

char *pgmStrToRAM(PROGMEM const char *theString);
