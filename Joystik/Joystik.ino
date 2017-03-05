/*
 Keyboard Message test

 For the Arduino Leonardo and Micro.

 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 4 to +5V
 * 10-kilohm resistor attached from pin 4 to ground

 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */
/*
#include "Keyboard.h"


const int switchPin = 8;
int switchState = 0;
int incomingByte = 0;  // for incoming serial data

void setup() {
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  pinMode(switchPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
 
}

void loop() {
   //Serial.println("Début");
  switchState = digitalRead(switchPin);
  // read the pushbutton:
   if(switchState == HIGH){
    Serial.println("Début");
    // send data only when you receive data:
      if (Serial.available() > 0) {
       // read the incoming byte:
         incomingByte = Serial.read();
        // say what you got:
        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
        }
     // joystik(valX, callx);
      //Keyboard.print(valX);
      /*if (valX<300) {
      //Keyboard.press(KEY_LEFT_ARROW);
         Keyboard.println("KEY_LEFT_ARROW");
      }
      if (300<valX<700) {
      //Keyboard.release();
      Keyboard.println("rien");
      }
      if (valX>700) {
      //Keyboard.press(KEY_RIGHT_ARROW);
       Keyboard.println("KEY_RIGHT_ARROW");
      }
      if (valY<300) {
      //Keyboard.press(KEY_DOWN_ARROW);
      Keyboard.println("KEY_DOWN_ARROW");
      }
      if (300<valY<700) {
      //Keyboard.releaseAll();
      Keyboard.print("rien");
      }
      if (valY>700) {
      // Keyboard.press(KEY_UP_ARROW);
        Keyboard.print("KEY_UP_ARROW");
      }*/
 /*  }
      delay(60);
}
/*
void joystik(int x, int off){
  if(x > (off+2))
    Keyboard.println("KEY_RIGHT_ARROW");
  else if (x< (off-2))
    Keyboard.println("KEY_LEFT_ARROW");
  else
     Keyboard.println("KOW");
       
  }
 */

 /*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include "Keyboard.h"
#include <SoftwareSerial.h>
const int switchPin = 8;
int switchState = 0;
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


 // Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
 // mySerial.println("Hello, world?");
}

void loop() { // run over and over
   switchState = digitalRead(switchPin);
    // read the pushbutton:
    if(switchState == HIGH){
      if (mySerial.available()) {
      Serial.write(mySerial.read());
      }
      if (Serial.available()) {
        mySerial.write(Serial.read());
      }
   }
}

