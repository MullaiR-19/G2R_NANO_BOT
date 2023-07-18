//BotDulars Arduino Program Kit//
//G2R Nano Bot - Line Follower Car / Robot Program// 

/*//Before start the motor please calibrate the line sensors with trimpot adjustments
the yellow led sholud on in the black line and off in the white area
The black line width should be in between the sensors. //*/ 	
	



#define MOTOR_R_PIN_1 11     // the number of the Front motor Right side pin
#define MOTOR_R_PIN_2 6     // the number of the Back motor Right side pin
#define MOTOR_L_PIN_1 5     // the number of the Front motor Left side pin
#define MOTOR_L_PIN_2 3     // the number of the Back motor Left side pin

#define LEFT_LINE_SENSOR		A0
#define RIGHT_LINE_SENSOR		A1
#define PUSH_BUTTON				10
#define LED_PIN					4

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
	pinMode(LED_PIN, OUTPUT);
	
	AllSet(LOW);
	
	pinMode(LEFT_LINE_SENSOR, INPUT);
	pinMode(RIGHT_LINE_SENSOR, INPUT);
	pinMode(PUSH_BUTTON, INPUT);
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

int AutoDrive=0;
int RunCount=0;
int StopCount=0;

void loop() 
{
	char ch;
	while (Serial.available()) 
	{
		ch=Serial.read();
		if(ch>' ')
		{
			if 		(ch=='f') { RunMotors("Front"); }
			else if (ch=='b') { RunMotors("Back"); }
			else if (ch=='l') { RunMotors("Left"); }
			else if (ch=='r') { RunMotors("Right"); }
			else if (ch=='s') 
			{
				RunMotors("Stop");
			}
			else if (ch=='1') 
			{
				LeftForward();
			}
			else if (ch=='2') 
			{
				LeftBackward();
			}
			else if (ch=='3') 
			{
				RightForward();
			}
			else if (ch=='4') 
			{
				RightBackward();
			}
		}
	}

	int LeftSensor=digitalRead(LEFT_LINE_SENSOR);
	int RightSensor=digitalRead(RIGHT_LINE_SENSOR);
	int Button=digitalRead(PUSH_BUTTON);
	
//****************************************************************************************************
	
	Serial.print(Button);Serial.print("  :  ");
	Serial.print(AutoDrive);Serial.print("  :  ");
	Serial.print(LeftSensor);Serial.print("--");Serial.println(RightSensor);

//****************************************************************************************************

	if (Button==LOW) 
	{
		// Turn On/Off AutoDrive 
		if (AutoDrive==0)
			AutoDrive=1;
		else
			AutoDrive=0;

		digitalWrite(LED_PIN,AutoDrive);

		for(;;) 
		{
			// Wait for Button Release.
			if (digitalRead(PUSH_BUTTON)==HIGH) break;
			delay(1);
		}
	}
	
	
	
	if (AutoDrive)
	{
		if ((LeftSensor==0)&&(RightSensor==1))
		{
			RunMotors("Left");
		}
		else if ((LeftSensor==1)&&(RightSensor==0))
		{
			RunMotors("Right");
		}
		else
		{
			RunMotors("Front");	
		}
	}
	
//****************************************************************************************************	
	delay(10);
	RunMotors("Stop");
	delay(20);
}
