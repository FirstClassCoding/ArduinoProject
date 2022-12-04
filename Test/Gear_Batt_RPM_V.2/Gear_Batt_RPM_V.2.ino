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
int ShiftLight = 12;
int CheckN = 2;
int Gear1 = 3;
int Gear2 = 4;
int Gear3 = 5;
int Gear4 = 6;
int Gear5 = 7;
int Gear6 = 8;

float Volume = 0;
float RPM = 1;

void setup()   {       
           
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
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
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);

}

void loop() {

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
      display.setCursor(63,20);
      display.println("N");
    }
    else if(digitalRead(Gear1)==HIGH)
    {
      display.setCursor(63,20);
      display.println("1");
    }
    else if(digitalRead(Gear2)==HIGH)
    {
      display.setCursor(63,20);
      display.println("2");
    }
    else if(digitalRead(Gear3)==HIGH)
    {
      display.setCursor(63,20);
      display.println("3");
    }
    else if(digitalRead(Gear4)==HIGH)
    {
      display.setCursor(63,20);
      display.println("4");
    }
    else if(digitalRead(Gear5)==HIGH)
    {
      display.setCursor(63,20);
      display.println("5");
    }
    else if(digitalRead(Gear6)==HIGH)
    {
      display.setCursor(63,20);
      display.println("6");
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
