/*
 * Test code for I2C configurations with the PCF8574 IO expander IC and the atTiny85 microcontroller.
 * Turns on all eight LEDs connected to the PCF8574 one after another, and then turns them all off again. 
 * A potentiometer is also used to control the speed of the pattern. Repeats forever.
 */

#include <A85_PCF8574.h>  // Library to operate the PCF8574 with the atTiny85 microcontroller

// Declare a PCF8574
A85_PCF8574 myPCF;

void setup()
{
  // Set analog pin A2 to INPUT for the potentiometer
  pinMode(A2, INPUT);

  // Start the IO expander IC with I2C address 0x38
  myPCF.begin(0x38);
}

void loop()
{
  // Loop through all the pins, turning them all off, and then all on
  for(int i = 0; i <= 1; i++)
  {
    for(int j = 0; j <= 7; j++)
    {
      myPCF.setBit(j, i);

      // Delay code according to position of potentiometer
      delay(map(analogRead(A2), 1, 1023, 2, 500));
    }
  }
}
