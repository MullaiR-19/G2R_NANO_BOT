//BotDulars Arduino Program Kit//
//G2R Nano Bot - IR REMOTE OLED DISPLAY Program// 


#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(128, 32, &Wire, -1);

#include <IRremote.h>

#define IR_RECEIVE_PIN  2



void setup()
{
  Serial.begin(115200);
  Serial.println("Hello OK");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Enabled IRin");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //or 0x3C
  display.clearDisplay(); //for Clearing the display
  //display.drawBitmap(0, 0, myBitmap, 64, 16, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();

  delay(3000);
  
  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("IR DECODER");
  display.display();
}
    


void loop() {
   char ch;
   //char key;
   while (IrReceiver.decode()) 
   {  // Grab an IR code
        // At 115200 baud, printing takes 200 ms for NEC protocol and 70 ms for NEC repeat
        Serial.println(); // blank line between entries
        Serial.println(); // 2 blank lines between entries
        IrReceiver.printIRResultShort(&Serial);
        ch=IrReceiver.decodedIRData.command;
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(IrReceiver.decodedIRData.decodedRawData, HEX);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 17);
    display.print("BUTTON:");         
    display.display();
                 
    {    
    if (IrReceiver.decodedIRData.protocol == NEC)
    {
      if (IrReceiver.decodedIRData.address == 0x0)
      {
       if(ch==0x40) 
       {  Serial.println(F("Pressed Key is :"));
          Serial.println(F("OK"));
          display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("OK");
          display.display();
       }
       else if (ch==0x46)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("UP"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("UP");
          display.display();
       }
        else if (ch==0x15)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("DOWN"));
           display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("DN");
          display.display();
       }
       else if (ch==0x44)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("LEFT"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("LT");
          display.display();
       }
       else if (ch==0x43)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("RIGHT"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("RT");
          display.display();
       }  
       else if (ch==0x42)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("*"));
          display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("*");
          display.display();
       } 
       else if (ch==0x4A)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("#"));
              display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("#");
          display.display();
       } 
       else if (ch==0x16)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("1"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("1");
          display.display();
       }
        else if (ch==0x19)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("2"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("2");
          display.display();
       }
       else if (ch==0xD)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("3"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("3");
          display.display();
       }
       else if (ch==0xC)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("4"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("4");
          display.display();
       }  
       else if (ch==0x18)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("5"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("5");
          display.display();
       } 
       else if (ch==0x5E)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("6"));display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("6");
          display.display();
       } 
       else if (ch==0x8)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("7"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("7");
          display.display();
       }
        else if (ch==0x1C)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("8"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("8");
          display.display();
       }
       else if (ch==0x5A)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("9"));
        display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("9");
          display.display();
       }
       else if (ch==0x52)
       {  
        Serial.println(F("Pressed Key is :"));
        Serial.println(F("0"));display.setTextSize(2);
          display.setTextColor(WHITE);
          display.setCursor(90, 17);
          display.print("0");
          display.display();
       }  
       
     }
       
     delay(100);
    }  
      
    }  
        IrReceiver.resume();                            // Prepare for the next value
    
   }
}

  
