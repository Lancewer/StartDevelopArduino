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
const unsigned long debounceDelay = 50; //debounce threshold
const unsigned long clkThreshold = 500; //click max threshold

/*
 * Variables
 */
int ledState = ON;         // variable for reading the led status
int buttonState = LOW;
int lastBtnState = LOW;
unsigned long debounceTime;
unsigned long clkTimer;
int clkCount = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void doubleTapBtn(){
  int reading = digitalRead(buttonPin);

  //if clkTimer exceed clkThreshold reset click counter.
  if (millis() - clkTimer > clkThreshold) {
    clkCount = 0;
  }

  if (reading != lastBtnState) {
    debounceTime = millis();
  }

  if (millis() - debounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (reading == HIGH) {
        //trigger task
        if (clkCount == 0) {
          clkTimer = millis();  //start click timer
          clkCount++; //increase click counter by 1
        }else if(millis() - clkTimer <= clkThreshold){ //only if second click triggered within click threshold time.
          ledState = !ledState;
          clkCount = 0;
        }
      }
    }
  }

  digitalWrite(ledPin, ledState);
  lastBtnState = reading;
  return 0;
}

void loop() {
  doubleTapBtn();
}
