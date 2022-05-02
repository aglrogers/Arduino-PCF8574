/*
 * Test code for I2C configurations with the PCF8574 IO expander IC and the Arduino Uno.
 * Turns on all eight LEDs connected to the PCF8574, waits one second, turns them all off again, and waits another second. Repeats forever.
 */

#include "PCF8574.h"  // Library to operate the PCF8574

// Declare a PCF8574 with I2C address 0x38
PCF8574 myPCF(0x38);

// Variable delay speed for the flashing effect
const int flashDelay = 1000;

// Change the state of all LED pins at once
void changeState(int i)
{
  myPCF.digitalWrite(0, i);
  myPCF.digitalWrite(1, i);
  myPCF.digitalWrite(2, i);
  myPCF.digitalWrite(3, i);
  myPCF.digitalWrite(4, i);
  myPCF.digitalWrite(5, i);
  myPCF.digitalWrite(6, i);
  myPCF.digitalWrite(7, i);
}

void setup()
{
  // Start the IO expander IC
  myPCF.begin();

  // Set all IO expander pinmodes to OUTPUT
  myPCF.pinMode(0, OUTPUT);
  myPCF.pinMode(1, OUTPUT);
  myPCF.pinMode(2, OUTPUT);
  myPCF.pinMode(3, OUTPUT);
  myPCF.pinMode(4, OUTPUT);
  myPCF.pinMode(5, OUTPUT);
  myPCF.pinMode(6, OUTPUT);
  myPCF.pinMode(7, OUTPUT);
}

void loop()
{
  // Turn on all eight LEDs
  changeState(1);
  delay(flashDelay);

  // Turn off all eight LEDs
  changeState(0);
  delay(flashDelay);
}
