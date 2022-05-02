/*
 * Test code for I2C configurations with the PCF8574 IO expander IC and the atTiny85 microcontroller.
 * Turns on all eight LEDs connected to the PCF8574, waits one second, turns them all off again, and waits another second. Repeats forever.
 */

#include <A85_PCF8574.h>  // Library to operate the PCF8574 with the atTiny85 microcontroller

// Declare a PCF8574
A85_PCF8574 myPCF;

// Variable delay speed for the flashing effect
const int flashDelay = 1000;

// Change the state of all LED pins at once
void changeState(int i)
{
  myPCF.setBit(0, i);
  myPCF.setBit(1, i);
  myPCF.setBit(2, i);
  myPCF.setBit(3, i);
  myPCF.setBit(4, i);
  myPCF.setBit(5, i);
  myPCF.setBit(6, i);
  myPCF.setBit(7, i);
}

void setup()
{
  // Start the IO expander IC with I2C address 0x38
  myPCF.begin(0x38);
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
