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

int onshelf,empty,count,ONSHELF[31];
int pos[31]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

String inString;

void setup()
{
  Serial.begin(115200);
  Serial3.begin(115200);
  
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(36,0);
  display.print("Smart");
  display.setCursor(32,22);
  display.print("Mobile");
  display.setCursor(36,44);
  display.print("Shelf");
  display.display();

  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SMART");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print("MOBILE");
  delay(1000);
  lcd.setCursor(3,2);
  lcd.print("SHELF");
  delay(1000);
  lcd.setCursor(6,3);
  lcd.print("E-TECH");
  delay(2000);

  for(count=22;count<52;count++)
  {
    pinMode(count,INPUT_PULLUP);
  }
  pinMode(13,OUTPUT);
}

void loop()
{
  onshelf = ONSHELF[1]+ONSHELF[2]+ONSHELF[3]+ONSHELF[4]+ONSHELF[5]+ONSHELF[6]+ONSHELF[7]+ONSHELF[8]+ONSHELF[9]+ONSHELF[10]+ONSHELF[11]+ONSHELF[12]+ONSHELF[13]+ONSHELF[14]+ONSHELF[15]+ONSHELF[16]+ONSHELF[17]+ONSHELF[18]+ONSHELF[19]+ONSHELF[20]+ONSHELF[21]+ONSHELF[22]+ONSHELF[23]+ONSHELF[24]+ONSHELF[25]+ONSHELF[26]+ONSHELF[27]+ONSHELF[28]+ONSHELF[29]+ONSHELF[30];
  empty = 30-onshelf;

  lcd.clear();
  display.clearDisplay();

  lcd.setCursor(0,0);
  lcd.print("PLACE : ");
  lcd.print(onshelf);
  lcd.setCursor(0,1);
  lcd.print("EMPTY : ");
  lcd.print(empty);
  lcd.setCursor(-4,2);
  lcd.print("Check at another");
  lcd.setCursor(-4,3);
  lcd.print("Display !");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Number of Empty");

  Serial.println("==========");
  Serial.print("PLACE : ");
  Serial.println(onshelf);
  Serial.print("EMPTY : ");
  Serial.println(empty);
  Serial.print("Number of Empty : ");
  
  if(digitalRead(22)==1)
  {
    display.setCursor(0,15);
    display.println(pos[1]);
    Serial.print(pos[1]);
    Serial.print(",");
    ONSHELF[1] = 0;
  }
  else
  {
    ONSHELF[1] = 1;
  }
  if(digitalRead(23)==1)
  {
    display.setCursor(16,15);
    display.println(pos[2]);
    Serial.print(pos[2]);
    Serial.print(",");
    ONSHELF[2] = 0;
  }
  else
  {
    ONSHELF[2] = 1;
  }
  if(digitalRead(24)==1)
  {
    display.setCursor(32,15);
    display.println(pos[3]);
    Serial.print(pos[3]);
    Serial.print(",");
    ONSHELF[3] = 0;
  }
  else
  {
    ONSHELF[3] = 1;
  }
  if(digitalRead(25)==1)
  {
    display.setCursor(48,15);
    display.println(pos[4]);
    Serial.print(pos[4]);
    Serial.print(",");
    ONSHELF[4] = 0;
  }
  else
  {
    ONSHELF[4] = 1;
  }
  if(digitalRead(26)==1)
  {
    display.setCursor(64,15);
    display.println(pos[5]);
    Serial.print(pos[5]);
    Serial.print(",");
    ONSHELF[5] = 0;
  }
  else
  {
    ONSHELF[5] = 1;
  }
  if(digitalRead(27)==1)
  {
    display.setCursor(80,15);
    display.println(pos[6]);
    Serial.print(pos[6]);
    Serial.print(",");
    ONSHELF[6] = 0;
  }
  else
  {
    ONSHELF[6] = 1;
  }
  if(digitalRead(28)==1)
  {
    display.setCursor(96,15);
    display.println(pos[7]);
    Serial.print(pos[7]);
    Serial.print(",");
    ONSHELF[7] = 0;
  }
  else
  {
    ONSHELF[7] = 1;
  }
  if(digitalRead(29)==1)
  {
    display.setCursor(112,15);
    display.println(pos[8]);
    Serial.print(pos[8]);
    Serial.print(",");
    ONSHELF[8] = 0;
  }
  else
  {
    ONSHELF[8] = 1;
  }
  if(digitalRead(30)==1)
  {
    display.setCursor(0,25);
    display.println(pos[9]);
    Serial.print(pos[9]);
    Serial.print(",");
    ONSHELF[9] = 0;
  }
  else
  {
    ONSHELF[9] = 1;
  }
  if(digitalRead(31)==1)
  {
    display.setCursor(16,25);
    display.println(pos[10]);
    Serial.print(pos[10]);
    Serial.print(",");
    ONSHELF[10] = 0;
  }
  else
  {
    ONSHELF[10] = 1;
  }
  if(digitalRead(32)==1)
  {
    display.setCursor(32,25);
    display.println(pos[11]);
    Serial.print(pos[11]);
    Serial.print(",");
    ONSHELF[11] = 0;
  }
  else
  {
    ONSHELF[11] = 1;
  }
  if(digitalRead(33)==1)
  {
    display.setCursor(48,25);
    display.println(pos[12]);
    Serial.print(pos[12]);
    Serial.print(",");
    ONSHELF[12] = 0;
  }
  else
  {
    ONSHELF[12] = 1;
  }
  if(digitalRead(34)==1)
  {
    display.setCursor(64,25);
    display.println(pos[13]);
    Serial.print(pos[13]);
    Serial.print(",");
    ONSHELF[13] = 0;
  }
  else
  {
    ONSHELF[13] = 1;
  }
  if(digitalRead(35)==1)
  {
    display.setCursor(80,25);
    display.println(pos[14]);
    Serial.print(pos[14]);
    Serial.print(",");
    ONSHELF[14] = 0;
  }
  else
  {
    ONSHELF[14] = 1;
  }
  if(digitalRead(36)==1)
  {
    display.setCursor(96,25);
    display.println(pos[15]);
    Serial.print(pos[15]);
    Serial.print(",");
    ONSHELF[15] = 0;
  }
  else
  {
    ONSHELF[15] = 1;
  }
  if(digitalRead(37)==1)
  {
    display.setCursor(112,25);
    display.println(pos[16]);
    Serial.print(pos[16]);
    Serial.print(",");
    ONSHELF[16] = 0;
  }
  else
  {
    ONSHELF[16] = 1;
  }
  if(digitalRead(38)==1)
  {
    display.setCursor(0,35);
    display.println(pos[17]);
    Serial.print(pos[17]);
    Serial.print(",");
    ONSHELF[17] = 0;
  }
  else
  {
    ONSHELF[17] = 1;
  }
  if(digitalRead(39)==1)
  {
    display.setCursor(16,35);
    display.println(pos[18]);
    Serial.print(pos[18]);
    Serial.print(",");
    ONSHELF[18] = 0;
  }
  else
  {
    ONSHELF[18] = 1;
  }
  if(digitalRead(40)==1)
  {
    display.setCursor(32,35);
    display.println(pos[19]);
    Serial.print(pos[19]);
    Serial.print(",");
    ONSHELF[19] = 0;
  }
  else
  {
    ONSHELF[19] = 1;
  }
  if(digitalRead(41)==1)
  {
    display.setCursor(48,35);
    display.println(pos[20]);
    Serial.print(pos[20]);
    Serial.print(",");
    ONSHELF[20] = 0;
  }
  else
  {
    ONSHELF[20] = 1;
  }
  if(digitalRead(42)==1)
  {
    display.setCursor(64,35);
    display.println(pos[21]);
    Serial.print(pos[21]);
    Serial.print(",");
    ONSHELF[21] = 0;
  }
  else
  {
    ONSHELF[21] = 1;
  }
  if(digitalRead(43)==1)
  {
    display.setCursor(80,35);
    display.println(pos[22]);
    Serial.print(pos[22]);
    Serial.print(",");
    ONSHELF[22] = 0;
  }
  else
  {
    ONSHELF[22] = 1;
  }
  if(digitalRead(44)==1)
  {
    display.setCursor(96,35);
    display.println(pos[23]);
    Serial.print(pos[23]);
    Serial.print(",");
    ONSHELF[23] = 0;
  }
  else
  {
    ONSHELF[23] = 1;
  }
  if(digitalRead(45)==1)
  {
    display.setCursor(112,35);
    display.println(pos[24]);
    Serial.print(pos[24]);
    Serial.print(",");
    ONSHELF[24] = 0;
  }
  else
  {
    ONSHELF[24] = 1;
  }
  if(digitalRead(46)==1)
  {
    display.setCursor(0,45);
    display.println(pos[25]);
    Serial.print(pos[25]);
    Serial.print(",");
    ONSHELF[25] = 0;
  }
  else
  {
    ONSHELF[25] = 1;
  }
  if(digitalRead(47)==1)
  {
    display.setCursor(16,45);
    display.println(pos[26]);
    Serial.print(pos[26]);
    Serial.print(",");
    ONSHELF[26] = 0;
  }
  else
  {
    ONSHELF[26] = 1;
  }
  if(digitalRead(48)==1)
  {
    display.setCursor(32,45);
    display.println(pos[27]);
    Serial.print(pos[27]);
    Serial.print(",");
    ONSHELF[27] = 0;
  }
  else
  {
    ONSHELF[27] = 1;
  }
  if(digitalRead(49)==1)
  {
    display.setCursor(48,45);
    display.println(pos[28]);
    Serial.print(pos[28]);
    Serial.print(",");
    ONSHELF[28] = 0;
  }
  else
  {
    ONSHELF[28] = 1;
  }
  if(digitalRead(50)==1)
  {
    display.setCursor(64,45);
    display.println(pos[29]);
    Serial.print(pos[29]);
    Serial.print(",");
    ONSHELF[29] = 0;
  }
  else
  {
    ONSHELF[29] = 1;
  }
  if(digitalRead(51)==1)
  {
    display.setCursor(80,45);
    display.println(pos[30]);
    Serial.print(pos[30]);
    Serial.println();
    ONSHELF[30] = 0;
  }
  else
  {
    ONSHELF[30] = 1;
  }
  display.display();

  if (Serial.available())
  {
    int inByte = Serial.read();
    Serial.write(inByte);
  }
  
  delay(500);
}

void serialEvent3()
{
  while (Serial.available())
  {
    char inChar = Serial.read();
    Serial.write(inChar);
    inString += inChar;
    if (inChar == ']') 
    {
      if (inString.indexOf("[ON]")>0)
      {
        digitalWrite(13, HIGH);
      }
      else if (inString.indexOf("[OFF]")>0)
      {
        digitalWrite(13, LOW);
      }
      else
      {
        Serial.println("Wrong command");
      }
      inString = "";
    }
  }
}
