//BotDulars Arduino Program Kit//
//G2R Nano Bot - Motor Test Program// 

//Motor A
const int motorPin1  = 11;    
const int motorPin2  = 6;     
//Motor B
const int motorPin3  = 5;     
const int motorPin4  = 3; 
void setup() 
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}
void loop()
{
   //This code  will turn Motor A clockwise for 2 sec.
    //Serial.println("spinning wheels clockwise and anti clockwise for 2 seconds! Keep them raised so they dont run away :)");
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(500); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(500); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
 }

