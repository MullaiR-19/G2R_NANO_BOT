//BotDulars Arduino Program Kit//
//G2R Nano Bot - Potentiometer Program// 

//Constants:
const int ledPin = 4;  //pin 4 
const int potPin = A3; //pin A3 to read analog input

//Variables:
int value; //save analog value


void setup(){
  //Input or output?
  pinMode(ledPin, OUTPUT); 
  pinMode(potPin, INPUT); //Optional 

}

void loop(){
  
  value = analogRead(potPin);          //Read and save analog value from potentiometer
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);                          //Small delay
  
}


                           
