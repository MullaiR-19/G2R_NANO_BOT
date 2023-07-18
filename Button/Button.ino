//BotDulars Arduino Program Kit//
//G2R Nano Bot - Button/Switch Program// 


/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 4, when pressing a pushbutton attached to digital pin 10. 
 
 
 The circuit:
 * LED attached from pin 4 to ground 
 * pushbutton attached to pin 10 from ground
 * 10K resistor attached to pin 10 from +5V
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 

 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin =10;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH); 
  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}
