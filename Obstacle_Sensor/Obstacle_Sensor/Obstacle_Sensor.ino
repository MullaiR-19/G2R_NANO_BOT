/*
 //BotDulars Arduino Program Kit//
//G2R Nano Bot - Obstacle Sensor / Line Sensor Program// 

 */

// Arduino's pin connected to OUT pin of IR obstacle avoidance sensor

const int SENSOR1_PIN = A0;
const int SENSOR2_PIN = A1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
}

void loop() {
  // read the state of the the input pin:
  int state1 = digitalRead(SENSOR1_PIN);
  int state2 = digitalRead(SENSOR2_PIN);


  if (state1 == LOW)
    Serial.println("The obstacle is present in Sensor 1 ");
  else
    Serial.println("The obstacle is NOT present in Sensor 1");

  delay(500);
  
 if (state2 == LOW)
    Serial.println("The obstacle is present in Sensor 2 ");
  else
    Serial.println("The obstacle is NOT present in Sensor 2");

  delay(500);
}

