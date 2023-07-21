const int MOTOR_R_PIN_1 = 11;     // the number of the pushbutton pin
const int MOTOR_R_PIN_2 = 6;     // the number of the pushbutton pin

const int MOTOR_L_PIN_1 = 5;     // the number of the pushbutton pin
const int MOTOR_L_PIN_2 = 3;     // the number of the pushbutton pin


void AllSet(int level)
{
	digitalWrite(MOTOR_R_PIN_1,level);
	digitalWrite(MOTOR_R_PIN_2,level);
	digitalWrite(MOTOR_L_PIN_1,level);
	digitalWrite(MOTOR_L_PIN_2,level);
}



void setup() {
	Serial.begin(9600);
	Serial.println();

	pinMode(MOTOR_R_PIN_1, OUTPUT);
	pinMode(MOTOR_R_PIN_2, OUTPUT);
	pinMode(MOTOR_L_PIN_1, OUTPUT);
	pinMode(MOTOR_L_PIN_2, OUTPUT);
	AllSet(LOW);
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
	while (Serial.available()) 
	{
		ch=Serial.read();
		if(ch>' ')
		{
			if 		
                                (ch=='f') { RunMotors("Front"); }
			else if (ch=='b') 
                                { RunMotors("Back"); }
			else if (ch=='l') 
                                { RunMotors("Left");
                                delay(500);
                                RunMotors("Stop"); 
                                }
			else if (ch=='r') 
                              { RunMotors("Right");
                                delay(500);
                                RunMotors("Stop");  }
			else if (ch=='s') 
			{
				RunMotors("Stop");
			}
			
			
		}
	}

	delay(100);
}
