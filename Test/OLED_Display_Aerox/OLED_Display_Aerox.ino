#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <LiquidCrystal_I2C.h>
#include <MemoryFree.h>
#include <EEPROM.h>
//#include <SoftwareSerial.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

LiquidCrystal_I2C lcd(0x27, 16, 4);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

int oled;

void setup()
{
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.clearDisplay();

  display.drawLine(0,0,127,0,WHITE);
  display.drawLine(0,0,0,63,WHITE);
  display.drawLine(0,63,127,63,WHITE);
  display.drawLine(127,0,127,63,WHITE);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(4,5);
  display.println("Yamaha");
  
  display.setCursor(41,25);
  display.println("Aerox");
  
  display.setCursor(88,45);
  display.println("155");

  display.display();
  delay(1000);

  oled = 0;

  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
  display.display();
  if(oled == 0)
  {
    display.clearDisplay();
    oled++;
  }
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  
  display.setCursor(0,0);
  display.println("RPM:");
  display.setTextSize(1);
  display.setCursor(49,4);
  display.println("Engine Off");

  display.setTextSize(1);
  display.setCursor(0,24);
  display.print("Engine Temp : ");
  display.print("100");
  display.setCursor(99,24);
  display.print("  C");
  display.setCursor(105,19);
  display.print(".");

  display.drawLine(0,42,128,42,WHITE);

  display.setTextSize(1);
  
  display.setCursor(0,50);
  display.println("Batt :       V.");
  display.setCursor(41,50);
  display.print("12.59");
}
