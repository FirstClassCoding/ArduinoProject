#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 64 
#define LOGO16_GLCD_WIDTH  128 
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
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int led = 13;
int Check = 2;
int Reset = 3;
int Sec;
int Min;
int Hour;

void setup() {       
           
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("   Timer");
  
  display.setCursor(0,30);
  display.println("    On!");
  
  display.setCursor(0,40);
  display.println("   ");
  
  display.display();
  delay(2000);

  pinMode(2,INPUT);
  pinMode(3,INPUT);

}

void loop() {
 
 display.clearDisplay();
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  display.setCursor(0,2);
  display.println("====Timer Ready!!====");

  display.drawLine(0,13,128,13,WHITE);

  if(digitalRead(Check) == HIGH)
  {
    display.setCursor(0,17);
    display.println("Start!");
    display.setCursor(0,30);
    display.println("Hour   Minute  Second");
    display.setCursor(103,45);
    display.println(Sec);
    display.setCursor(55,45);
    display.println(Min);
    display.setCursor(7,45);
    display.println(Hour);
    Sec += 1;
    delay(800);
    if(Sec >= 60)
    {
      Min += 1;
      Sec = 0;
    }
    if(Min >= 60)
    {
      Hour += 1;
      Min = 0;
    }
  }
  else
  {
    display.setCursor(0,17);
    display.println("Stop!");
    display.setCursor(0,30);
    display.println("Hour   Minute  Second");
    display.setCursor(103,45);
    display.println(Sec);
    display.setCursor(55,45);
    display.println(Min);
    display.setCursor(7,45);
    display.println(Hour);
  }

  if(digitalRead(Reset) == HIGH)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(32,25);
    display.println("Reset!");

    Sec = 0;
    Min = 0;
    Hour = 0;

    delay(800);
  }
   
  display.display();

  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);

}
