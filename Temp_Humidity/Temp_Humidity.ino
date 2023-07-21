//BotDulars Arduino Program Kit//

//G2R Nano Bot - Temperature and Humidity Program// 


#include "DHT.h"
#define DHT11Pin 12
#define DHTType DHT11
//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

DHT HT(DHT11Pin,DHTType);
float humi;
float tempC;
float tempF;

//OLED define
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  //For DHT11
  HT.begin();
  //For OLED I2C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display(); //Display logo
  delay(1000); 
  display.clearDisplay();
}

void loop() {
 delay(1000);
 humi = HT.readHumidity();
 tempC = HT.readTemperature();
 tempF = HT.readTemperature(true);
 if (isnan(humi) || isnan(tempC))
  {
    display = "Failed";
  } else {

 Serial.print("Humidity:");
 Serial.print(humi,0);
 Serial.print("%");
 Serial.print(" Temperature:");
 Serial.print(tempC,1);
 Serial.print("C ~ ");
 Serial.print(tempF,1);
 Serial.println("F");
  }
 display.clearDisplay();
 oledDisplay(); 
 display.display(); 
 
}
void oledDisplay()
{
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(0, 0);
 display.print("Tem:");

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(50, 0);
 display.print(tempC,1);

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(100, 0); 
 display.print("`C");

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(0, 17);
 display.print("Hum:");

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(50, 17);
 display.print(humi,1);

 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(100, 17);
 display.print("%"); 
 
}
