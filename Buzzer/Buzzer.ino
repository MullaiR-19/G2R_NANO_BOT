//BotDulars Arduino Program Kit//
//G2R Nano Bot - Buzzer Program// 

const int buzzer = 7; //buzzer to arduino pin 7


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 7 as an output

}

void loop(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  
}
