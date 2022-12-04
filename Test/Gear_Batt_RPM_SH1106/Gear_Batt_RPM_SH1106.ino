#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

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

int led = 13;
int ShiftLight = 12;
int CheckN = 2;
int GearUp = 3;
int GearDown = 4;
int Gear;

float Volume = 0;
float RPM = 1;

void setup()
{
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("   Honda");
  
  display.setCursor(0,20);
  display.println("  Phantom");
  
  display.setCursor(0,40);
  display.println("    150");
  
  display.display();
  delay(1000);

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

void loop()
{
  float val = analogRead(Volume);
  val = analogRead(Volume)*0.0046;//default = 12=0.0118 ,1:1=0.0046
  Serial.println(val);
  //Voltage

  int ShowRPM = analogRead(RPM);
  ShowRPM = analogRead(RPM)*0.0046;//test ShowRPM
  Serial.println(ShowRPM);
  //RPM
 
 display.clearDisplay();
 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  
  display.setCursor(0,0);
  display.println("RPM:");
    if(ShowRPM >= 4)
    {
      display.setCursor(49,0);
      display.print(ShowRPM);
    }
    else
    {
      display.setTextSize(1);
      display.setCursor(49,4);
      display.println("Engine Off");
    }
  
  display.setTextSize(2);
  display.setCursor(0,20);
  display.println("Gear:");
    if(digitalRead(CheckN)==HIGH)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println("N");
      Gear = 0;
    }
    else if(Gear>=7)
    {
      Gear = 6;
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear<=0)
    {
      Gear = 1;
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(digitalRead(GearUp)==HIGH)
    {
      Gear += 1;
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(digitalRead(GearDown)==HIGH)
    {
      Gear -= 1;
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==1)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==2)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==3)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==4)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==5)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }
    else if(Gear==6)
    {
      Serial.println(Gear);
      display.setCursor(63,20);
      display.println(Gear);
    }

  display.drawLine(0,42,128,42,WHITE);

  display.setTextSize(1);
  
  display.setCursor(0,50);
  display.println("Batt :       V.");
    display.setCursor(41,50);
    display.print(val);
  
  display.display();

  digitalWrite(led,HIGH);
  digitalWrite(ShiftLight,LOW);
  delay(100);
  digitalWrite(led,LOW);
  digitalWrite(ShiftLight,HIGH);
  delay(100);
}
