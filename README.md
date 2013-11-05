# Arduino library for Measuring and use less Free RAM

This Library was written for the Arduino to both measure available RAM and use less RAM

Did you know that that the Arduino’s built in serial.print() of a constant char array

<pre>Serial.Print(“Hello”);</pre>

actually allocates the “Hello” into a unique space of RAM, not just Flash. Hence every such occurrence of serial print of a constant string uses more and more RAM. Until you are out. And there is only 2K of RAM on the ATmega328. This is likely why you don’t see many examples with a lot of debug prints.
That said there is hope, use the "F()" funciton. Now natively supported in the IDE > 1.0.0. Same concept applies.

Previously, I have both been suggested and found several work-a-rounds all similar in forcing the char array to be read directly from memory at print time. This can be done using some not as obvious AVR Libc commands provided with avr/pgmspace.h. Where teh pgmStrToRAM library provides a simplified library to do such.

Additionally the companion library MemoryFree is very useful in determining how much RAM is being used or left. Don't wonder or guess. I find it good practice to always dump it during setup to see the global static usage. Just in case.

## Installation

*   Download the Library https://github.com/mpflaga/Arduino-MemoryFree.git
*   It will contain the following to be placed into corresponding library directories:
<pre>.\pgmStrToRAM\MemoryFree.cpp
.\pgmStrToRAM\MemoryFree.h
.\pgmStrToRAM\pgmStrToRAM.cpp
.\pgmStrToRAM\pgmStrToRAM.h
.\pgmStrToRAM\examples\BareMinimum\BareMinimum.ino</pre>

*   Place the pgmStrToRAM directory folder and contents into your arduino library folder,
if the libraries folder does not exist - create it first!
*   Restart the IDE

## Example Usage

BareMinimum.ino is a example of usage that both demonstrates how to print out the current available memory at the time the freeMemory() is executed along with how to using getPSTR("hello") to put the "hello" into Flash without using any static RAM.

include the desired library(s) at the beginning of sketch

<pre>#include &lt;MemoryFree.h&gt;
#include &lt;pgmStrToRAM.h&gt;</pre>

then at the desired location

<pre>  Serial.println(getPSTR("Old way to force String to Flash"));
  Serial.println(F("New way to force String to Flash"));
  Serial.println(F("Free RAM = "));</pre>

Please note that the memory is dynamic and always changing. Where Static Global Variables and Members&nbsp; create a base minimum of usage that can typically be read at setup(). When functions and routines dive deeper into the stack more memory will be dynamically consumed and released. So there needs to be a margin from completely running out. 

## Back Ground

Based on my tests I see that Serial.Print of actual variables e.g.
Serial.Print( (int8_t) value, DEC);
Does not increase RAM usage for each occurrence.
However it would appear that overloaded object member of an char array (e.i. const string) creates a unique location in static RAM and definitely does not share it. As one might think or expect. 

A more indepth look at avr-libc and its features can be found at http://www.nongnu.org/avr-libc/user-manual/pgmspace.html 

## Alternatives

It is worth noting that there are many other sources of equivalent methods. Although note widely known. One such alternative is "SdFATlib" found at http://code.google.com/p/sdfatlib/ library file called SdFatUtil.h


<pre>#include&lt;SdFat.h&gt;  // required
#include &lt;SdFatUtil.h&gt;

PgmPrint("Free RAM: ");
Serial.println(FreeRam());</pre>

## Gratitude

Special Thanks to GreyGnome, William Greiman and others for providing the example this is based off.