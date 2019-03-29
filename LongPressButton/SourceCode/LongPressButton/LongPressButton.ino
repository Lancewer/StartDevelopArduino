/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

#define ON  HIGH
#define OFF LOW

/*
 * Constants
 */
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin
const unsigned long debounceDelay = 50; // debounce threshold
const unsigned long clkThreshold = 2000; // long press min threshold

/*
 * Variables
 */
int ledState = ON;         // variable for reading the led status
int buttonState = LOW;
int lastBtnState = LOW;
unsigned long debounceTime;
unsigned long clkTimer;
bool btnPressed = false;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void longPressBtn(){
  int reading = digitalRead(buttonPin);

  if (reading != lastBtnState) {
    debounceTime = millis();
  }

  if (millis() - debounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (reading == HIGH) {
          clkTimer = millis();  //start click timer
          btnPressed = true;
        }else if(btnPressed & millis() - clkTimer >= clkThreshold){ //only if second click triggered within click threshold time.
          ledState = !ledState;
          btnPressed = false;
        }else{
          btnPressed = false;
      }
    }
  }

  digitalWrite(ledPin, ledState);
  lastBtnState = reading;
}

void loop() {
  longPressBtn();
}
