#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int light; 
void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 allocation failed");
    while(1); //Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);  
  display.setTextSize(4);
  display.setCursor(10, 20);
  display.print("OLED");
  display.display();
  delay(2000);  
  display.setTextSize(3);  
}
 
void loop()
{
  int light_value;
  light_value = analogRead(A2);
  light = map(light_value,15,1015,0,100);  
  display.clearDisplay();
  delay(200);
  
  display.setCursor(5, 0);
  display.println("Li:");
  display.display();
  display.setCursor(60,0);
  display.print(light);
  display.setCursor(110,0);
  display.print('%');
  display.display();
  delay(1000);
 }
