#include <Keyboard.h>

/*
  4x4 keyboard code , based on Analog input, analog output, serial output by Tom Igoe

  2020 (c) Radek Voltr
  MIT license

*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
char lastchar = ' ';

void setup() {
  // initialize serial communications at 9600 bps:
  //Serial.begin(115200);
    Keyboard.begin();

}

void ProcessChar(char current_char)
{
    if (lastchar != current_char)
    {
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(current_char);
      lastchar = current_char;
      delay(100);
      Keyboard.releaseAll();
    }
}


void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  // print the results to the Serial Monitor:
  //Serial.print("sensor = ");
  //Serial.print(sensorValue);
  //Serial.print("\t output = ");
  //Serial.println(outputValue);

  if (sensorValue > 1015)
    ProcessChar('a');
    else
  if (sensorValue > 920)
    ProcessChar('b');
    else
  if (sensorValue > 840)
    ProcessChar('c');
    else
  if (sensorValue > 780)
    ProcessChar('d');
    else
  if (sensorValue > 670)
    ProcessChar('e');
    else
  if (sensorValue > 630)
    ProcessChar('f');
    else
  if (sensorValue > 590)
    ProcessChar('g');
    else
  if (sensorValue > 560)
    ProcessChar('h');
    else
  if (sensorValue > 500)
    ProcessChar('i');
    else
  if (sensorValue > 470)
    ProcessChar('j');
    else
  if (sensorValue > 450)
    ProcessChar('k');
    else
  if (sensorValue > 430)
    ProcessChar('l');
    else
  if (sensorValue > 390)
    ProcessChar('m');
    else
  if (sensorValue > 310)
    ProcessChar('n');
    else
  if (sensorValue > 250)
    ProcessChar('o');
    else
  if (sensorValue > 210)
    ProcessChar('p');
    else
    lastchar = ' ';
  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
