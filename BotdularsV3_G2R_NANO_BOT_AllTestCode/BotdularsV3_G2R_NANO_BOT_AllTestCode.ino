//Botdulars-V3 G2R-NANO-BOT test program. July 2023. 

#include <DHT.h>
#include <IRremote.h>

#define NEED_OLED
   #ifdef NEED_OLED

   #include <Wire.h>
   #include <Adafruit_SSD1306.h>
	 Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire , -1);

#endif

#define IR_RECEIVE_PIN  2

#define DHT11_PIN 12
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);

int value = 0; 
int pos = 0; 
int buttonState = 0;            // variable for reading the pushbutton status
 
const int buttonPin = 10;       // the number of the pushbutton pin
const int ledPin = 4;              // the number of the LED pin
const int trigPin = 9;
const int echoPin = 8;
const int potentioMeter = A3 ; 
const int buzzer = 7; 
const int RightSensor = A0; 
const int LeftSensor = A1;
const int ldrPin = A2;
//Motor A
const int motorPin1  = 11;    
const int motorPin2  = 6;     
//Motor B
const int motorPin3  = 5;     
const int motorPin4  = 3;     

//********************************************************************************

void SetupOLED()
{
#ifdef NEED_OLED    	
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C,true,true); // Address 0x3C for 128x32
	display.display();
	//delay(3000);
	// Clear the buffer.
	display.clearDisplay();
	display.display();
	// text display tests
	display.setTextSize(2);
	display.setTextColor(WHITE);
#endif
}

void OLEDDisplay(int prog)
{
#ifdef NEED_OLED    
	byte Botdulars;
	
	display.clearDisplay();
	display.setCursor(0, 0);
	display.print("Botdulars: ");
	display.setCursor(60, 17);
	display.println(prog);
	display.display();
	delay(1000);

	
#endif
}



void setup() {

	Serial.begin(9600); 

	Serial.println(("Starting Display Test")); 
	SetupOLED();	
	Serial.println(F("Done Display Test")); 
  
	dht.begin(); 
	IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

	//********************************************************  


	pinMode(RightSensor, INPUT); 
	pinMode(LeftSensor, INPUT); 
	pinMode(buttonPin, INPUT) ;     
	pinMode(ledPin, OUTPUT); 
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT);   
	pinMode(ldrPin, INPUT);  
	pinMode(potentioMeter, INPUT); 
	pinMode(buzzer, OUTPUT);   
	//wheels
	pinMode(motorPin1, OUTPUT);
	pinMode(motorPin2, OUTPUT);
	pinMode(motorPin3, OUTPUT);
	pinMode(motorPin4, OUTPUT);
	Serial.println(F("Welcome to the TEST program for Botdulars V2. Start testing with numbers 1-9")); 
	//BTSerial.begin(9600) ; 
	//BTSerial.println("Welcome to the botdulars final program for Levels 1&2") ; 

}



void showIRSensor() 
{
    if (IrReceiver.decode()) {  // Grab an IR code
        // At 115200 baud, printing takes 200 ms for NEC protocol and 70 ms for NEC repeat
        Serial.println(); // blank line between entries
        Serial.println(); // 2 blank lines between entries
        IrReceiver.printIRResultShort(&Serial);
		
		if (IrReceiver.decodedIRData.protocol == NEC)
		{
			if (IrReceiver.decodedIRData.address == 0x0) {
				if (IrReceiver.decodedIRData.command == 0x40) 
				{
					Serial.println(F("OK  Pressed."));
				}
			}
		}			
		
        IrReceiver.resume();                            // Prepare for the next value
    }
}

void turnOnLED() 
{
    digitalWrite(ledPin, HIGH);  
    Serial.println(F("This instruction turns the LED ON for 1 sec")) ; 
    delay(1000); 
    digitalWrite(ledPin, LOW);   
}

void showUltrasonicValues()
{
float duration;
float distance_cm;
float distance_in;

digitalWrite(trigPin, LOW); //PULSE ___|---|___
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance_cm = (duration/2) / 29.1;
distance_in = (duration/2) / 73.914;
   Serial.print(F("Distance_cm: "));
	 Serial.println(distance_cm);
   Serial.print(F("Distance_inch: "));
	 Serial.println(distance_in);

}

void showTemp() 
{
  delay(2000);
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C . Wait..."));
  
  delay(2000);
  Serial.print(F("Done. "));
}

void showLuminance()
{
int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 300) {

digitalWrite(ledPin, HIGH);

Serial.print(F("Its DARK, Turn on the LED : "));

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, LOW);

Serial.print(F("Its BRIGHT, Turn off the LED : "));

Serial.println(ldrStatus);


}
}



void showPotValue() 
{
  int potval = analogRead(potentioMeter);          //Read and save analog value from potentiometer
  //potval = map(value, 0, 1023, 0, 255);         //Map value 0-1023 to 0-255 (PWM)
  Serial.print(F("Potentiometer")); 
  Serial.println(potval) ;   
  
}

void buzzerON() 
{
	Serial.println(F("This instruction turns the Buzzer ON for 1 sec")) ; 
	digitalWrite(buzzer, HIGH); 
	delay(1000); 
	digitalWrite(buzzer, LOW);  
}


void pushButton()
{
	int buttonstate = digitalRead(buttonPin);//Read and save analog value from potentiometer
	Serial.print(F("Button state:")); 
	if (buttonstate==LOW) // Pulled up so LOW is ON
		Serial.println(F("ON")) ;   
	else
		Serial.println(F("OFF")) ;   
}

void wheelSpin()
{
    //This code  will turn Motor A clockwise for 2 sec.
    Serial.println(F("spinning wheels clockwise and anti clockwise for 2 seconds! Keep them raised so they dont run away :)"));
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(300); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(300); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
      
}



void  LineSensor(){
  // read the state of the the input pin:
  int stateR = digitalRead(RightSensor);
  int stateL = digitalRead(LeftSensor);

  if (stateR == LOW)
    Serial.println(F("The BLACK LINE NOT Detected in RightSensor "));
  else 
    Serial.println(F("The BLACK LINE DETECTED in RightSensor"));

  if (stateL == LOW)
    Serial.println(F("The BLACK LINE NOT Detected in LeftSensor "));
  else
    Serial.println(F("The BLACK LINE DETECTED in LeftSensor"));
  
}




void loop() {
	
  // We have to monitor IR Continually.
  showIRSensor();
	
  while (Serial.available() )
  {
    value = Serial.parseInt() ; 
    //value = Serial.read() ; 
    value = (int)value; 
    if (value>=1 && value<=9) 
    {
		Serial.println(value); 
		Serial.print(F("received input as:")) ; 
		Serial.println(value) ; 

		OLEDDisplay(value);
		
			 if (value == 1)  turnOnLED() ; 
		else if (value == 2)  showUltrasonicValues() ; 
		else if (value == 3)  showTemp() ; 
		else if (value == 4)  showLuminance() ; 
		else if (value == 5)  buzzerON() ; 
		else if (value == 6)  wheelSpin() ;
		else if (value == 7)  showPotValue() ; 
		else if (value == 8) pushButton() ;
		else if (value == 9) LineSensor() ;
	}

    while (Serial.available() && Serial.read()); // empty buffer 
  }
}
