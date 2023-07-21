//Botdulars-V3 G2R-NANO-BOT Kit//
//G2R NANO BOT - Remote Car Program //

#include <IRremote.h>

const int MOTOR_R_PIN_1 = 11;     // the number of the pushbutton pin
const int MOTOR_R_PIN_2 = 6;     // the number of the pushbutton pin

const int MOTOR_L_PIN_1 = 5;     // the number of the pushbutton pin
const int MOTOR_L_PIN_2 = 3;     // the number of the pushbutton pin

#define IR_RECEIVE_PIN  2

void AllSet(int level)
{
	digitalWrite(MOTOR_R_PIN_1,level);
	digitalWrite(MOTOR_R_PIN_2,level);
	digitalWrite(MOTOR_L_PIN_1,level);
	digitalWrite(MOTOR_L_PIN_2,level);
}



void setup() {
	Serial.begin(115200);
	Serial.println();

	pinMode(MOTOR_R_PIN_1, OUTPUT);
	pinMode(MOTOR_R_PIN_2, OUTPUT);
	pinMode(MOTOR_L_PIN_1, OUTPUT);
	pinMode(MOTOR_L_PIN_2, OUTPUT);
	AllSet(LOW);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void LeftForward()
{
	Serial.println("LeftForward");
	digitalWrite(MOTOR_L_PIN_1,LOW);digitalWrite(MOTOR_L_PIN_2,HIGH);
}

void LeftBackward()
{
	Serial.println("LeftBackward");
	digitalWrite(MOTOR_L_PIN_1,HIGH);digitalWrite(MOTOR_L_PIN_2,LOW);
}


void RightForward()
{
	Serial.println("RightForward");
	digitalWrite(MOTOR_R_PIN_1,HIGH);digitalWrite(MOTOR_R_PIN_2,LOW);
}

void RightBackward()
{
	Serial.println("RightBackward");
	digitalWrite(MOTOR_R_PIN_1,LOW);digitalWrite(MOTOR_R_PIN_2,HIGH);
}



int runcount=0;
void RunMotors(char *dir)
{
	Serial.println(dir);
	if (strcmp(dir,"Front")==0)	
	{	
		LeftForward();
		RightForward();
	}
	if (strcmp(dir,"Back")==0)	
	{	
		LeftBackward();
		RightBackward();
	}
	if (strcmp(dir,"Left")==0)	
	{	
		LeftBackward();
		RightForward();
	}
	if (strcmp(dir,"Right")==0)	
	{	
		LeftForward();
		RightBackward();
	}

	runcount=1;

	if (strcmp(dir,"Stop")==0)	
	{	
		digitalWrite(MOTOR_R_PIN_1,LOW);digitalWrite(MOTOR_R_PIN_2,LOW);
		digitalWrite(MOTOR_L_PIN_1,LOW);digitalWrite(MOTOR_L_PIN_2,LOW);

		runcount=0;
	}

}

void loop() 

{
   char ch;
   while (IrReceiver.decode()) 
   {  // Grab an IR code
        // At 115200 baud, printing takes 200 ms for NEC protocol and 70 ms for NEC repeat
        Serial.println(); // blank line between entries
        Serial.println(); // 2 blank lines between entries
        IrReceiver.printIRResultShort(&Serial);
        ch=IrReceiver.decodedIRData.command;
                 
    {    
    if (IrReceiver.decodedIRData.protocol == NEC)
    {
      if (IrReceiver.decodedIRData.address == 0x0)
      {
       if    (ch==0x46) { RunMotors("Front"); }
       else if (ch==0x15) { RunMotors("Back"); }
       else if (ch==0x44) 
      { 
        RunMotors("Left");
        delay(500);
        RunMotors("Stop"); 
      }
      else if (ch==0x43)
      {
        RunMotors("Right");
        delay(500);
        RunMotors("Stop"); 
      }
      else if (ch==0x40) 
      {
        RunMotors("Stop");
      } 
        }

     delay(100);
    }
      }
        
        IrReceiver.resume();                            // Prepare for the next value
    }
}
