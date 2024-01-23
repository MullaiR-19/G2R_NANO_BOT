int led1 = 4;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);  
 }

void loop() {
  digitalWrite(led1, HIGH); 
  
    // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW); 
 
  
   // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
