// Code to check the operation of the internal EEPROM memory of an ATtiny85 microcontroller (by Pléyades IT).

#include <EEPROM.h>

int retardo = 325;
int LED_bar[] = {1, 2, 4, 8, 16};
int position;

void setup()
{
  DDRB = B00011111;             // Digital pin 0 to 4 as output (set 1 = output // set 0 = intput). 
  position = EEPROM.read(0);    // EEPROM.read(address);
  delay(100);
}

void loop()
{
  for (int i = position; i <= 4; i++)
  {
    PORTB = LED_bar[i];
    EEPROM.write(0, i);     	// EEPROM.write(address, value);
    delay(retardo);
  }
  position = 0;
}
