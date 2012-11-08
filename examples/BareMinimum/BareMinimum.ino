#include <MemoryFree.h>;
#include <pgmStrToRAM.h>;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(115200);
	Serial.print(getPSTR("Free RAM = "));
	Serial.println(freeMemory(), DEC);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}

