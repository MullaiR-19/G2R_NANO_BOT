//BotDulars Arduino Program Kit//
//G2R Nano Bot - Bluetooth Program// 
/*Code to control an LED via bluetooth through a phone app *///Bluetooth  uses serial communication. So, we use many serial functions 
//in this sketch.  
//Get Blutooth phone app from the playstore//
// https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en&gl=US  //


const int LED = 4;

char switchstate;

void setup()  {//Here the code only runs once.
Serial.begin(9600);
/*To start serial communication  at a rate of 9600 bits per second. This  
is the default rate anyways.*/
pinMode(LED,  OUTPUT);
//Declaring that the LED is an output.
}
void loop() {//This code  repeats. This is our main code.
while(Serial.available()>0){ 
 //code to be  executed only when Serial.available()>0
 /*Serial.available>0 is to check if  there is any reading from the 
 HC-05 Bluetooth module.*/ 
switchstate = Serial.read();
/*The  character we had declared earlier is now being assigned a value-
the value of  whatever Serial.read() is.*/
//Serial.read() is to read the value coming from  app.
Serial.print(switchstate);
//This will print the value onto the Serial  monitor.
Serial.print("\
");
//This moves to the next line after every  new line printed.
delay(15);
/*Gives a break of 15 milliseconds. Delay is  for human eye, and for
speed of some computers, as some will crash at high speeds.*/
if(switchstate  == '1'){//Checking if the value from app is '1'
 digitalWrite(4, HIGH);
 //If  it is, write the component on pin 5(LED) high. 
}
else if(switchstate == '0'){//Else,  if the vaue from app is '0',
 digitalWrite(4, LOW);//Write the component on pin  5(LED) low.
}
}
}
