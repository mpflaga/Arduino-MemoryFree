#include <MemoryFree.h>;
#include <pgmStrToRAM.h>; // not needed for new way. but good to have for reference.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(getPSTR("Old way to force String to Flash")); // forced to be compiled into and read 	
  Serial.println(F("New way to force String to Flash")); // forced to be compiled into and read 	
  Serial.println(F("Free RAM = ")); //F function does the same and is now a built in library, in IDE > 1.0.0
  Serial.println(freeMemory(), DEC);  // print how much RAM is available.
  // print how much RAM is available.
}

void loop() {
  // put your main code here, to run repeatedly:

}