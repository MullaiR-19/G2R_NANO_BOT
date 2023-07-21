//BotDulars Arduino Program Kit//
//G2R Nano Bot - IR Remote Program// 


#include <IRremote.h>

#define IR_RECEIVE_PIN  2

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello OK");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
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
       if(ch==0x40) 
       {  Serial.println(F("Pressed Key is :"));
          Serial.println(F("OK"));
       }
       else if (ch==0x46)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("UP"));
       }
        else if (ch==0x15)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("DOWN"));
       }
       else if (ch==0x44)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("LEFT"));
       }
       else if (ch==0x43)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("RIGHT"));
       }  
       else if (ch==0x42)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("*"));
       } 
       else if (ch==0x4A)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("#"));
       } 
       else if (ch==0x16)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("1"));
       }
        else if (ch==0x19)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("2"));
       }
       else if (ch==0xD)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("3"));
       }
       else if (ch==0xC)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("4"));
       }  
       else if (ch==0x18)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("5"));
       } 
       else if (ch==0x5E)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("6"));
       } 
       else if (ch==0x8)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("7"));
       }
        else if (ch==0x1C)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("8"));
       }
       else if (ch==0x5A)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("9"));
       }
       else if (ch==0x52)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("0"));
       }  
       
     }
       
     delay(100);
    }  
      
    }  
        IrReceiver.resume();                            // Prepare for the next value
    
   }
}
