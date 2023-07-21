#include<Wire.h>

#include<Adafruit_GFX.h>

#include<Adafruit_SSD1306.h>

 

#define SCREEN_WIDTH 128

#define SCREEN_HEIGHT 32

 

Adafruit_SSD1306
display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire , -1);

 

 

void
setup(void) {

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void
loop() {

 

  display.clearDisplay ();

  display.setCursor (10, 5);

  display.setTextSize (2);

  display.setTextColor (WHITE);

  display.print ("Hello");

 

  display.setCursor (10, 23);

  display.setTextSize (1);

  display.print ("Friends");

  delay (1000);

 

  display.drawCircle (110, 15, 15, WHITE); //Head frame

  display.drawCircle (105, 14, 4, WHITE); //Left eye

  display.drawCircle (115, 14, 4, WHITE); //Right eye

 

  display.drawPixel (103, 22, WHITE); // Mouth

  display.drawPixel (118, 22, WHITE); // Mouth

  display.drawPixel (104, 23, WHITE); // Mouth

  display.drawPixel (117, 23, WHITE); // Mouth

  display.drawPixel (105, 24, WHITE); // Mouth

  display.drawPixel (116, 24, WHITE); // Mouth

  display.drawLine (106, 25, 115, 25, WHITE);
// Mouth

  display.display ();

 

  delay (1000);

}
