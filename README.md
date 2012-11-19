# Arduino library for Measuring and use less Free RAM

This Library was written for the Arduino to both measure available RAM and use less RAM

## Installation

*   Downloaded the Library https://github.com/mpflaga/Arduino-MemoryFree.git
*   it will contain the following to be placed into corresponding directories:
<pre>.\pgmStrToRAM\MemoryFree.cpp
.\pgmStrToRAM\MemoryFree.h
.\pgmStrToRAM\pgmStrToRAM.cpp
.\pgmStrToRAM\pgmStrToRAM.h
.\pgmStrToRAM\examples\BareMinimum\BareMinimum.ino</pre>

*   Place the pgmStrToRAM directory library folder into your &lt;arduinosketchfolder&gt;/libraries/ <arduinosketchfolder>folder,
if the libraries folder does not exist - create it first!</arduinosketchfolder>
*   Restart the IDE

BareMinimum.ino is a example of usage that both demonstrates how to print out the current available memory at the time the freeMemory() is executed along with how to using getPSTR("hello") to put the "hello" into Flash without using any static RAM.

## Back Ground

Did you know that that the Arduino’s built in 

<pre>Serial.Print(“Hello”);</pre>

This actually allocates the “Hello” into a _unique _space of RAM. Hence every such occurrence of serial print of a constant string uses more and more ram. Until you are out. And there is only 2\. of RAM on the ATmega328\. This is likely why you don’t see many examples with a lot of debug prints. 

Based on my tests I see that Serial.Print of actual variables e.g.

<pre>Serial.Print( (int8_t) value, DEC); </pre>

Does not increase RAM usage for each occurrence. 

Hence it would appear that overloaded object member of an char array (e.i. const string) create a unique location in static RAM and definite does not share it. As one might think or expect.

That said there is hope. I have both been suggested and found several work-a-rounds all similar in forcing the char array to be read directly from memory at print time.&nbsp; This can be done using some not as obvious AVR Libc commands provided with avr/pgmspace.h.