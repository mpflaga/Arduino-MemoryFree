#include <MemoryFree.h>;
#include <pgmStrToRAM.h>;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	Serial.print(getPSTR("Free RAM = ")); // forced to be compiled into and read from Flash
	Serial.println(freeMemory(), DEC);  // print how much RAM is available.
}

void loop() {
	// put your main code here, to run repeatedly:

}