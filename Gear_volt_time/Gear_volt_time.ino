#include <Wire.h> 
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Wire.h"
//#include "SPI.h"  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
RTC_DS3231 RTC;
extern uint8_t MegaNumbers[]; // Подключение больших шрифтов
extern uint8_t SmallFont[];
Adafruit_SSD1306 OLED(-1); 
#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5
#define SW5 6
#define SW6 7
#define SW7 8
int A = 0;
int B = 0;
int C = 0;
int D = 0;
int E = 0;
int F = 0;
int G = 0;
float Volume = 0;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));

 if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
   // RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  DateTime now = RTC.now();
  /* ตั้งเวลา ในตัวอย่างนี้ เซตค่าเป็นเวลา 23:09 ถ้าถึงเวลานี้จะให้ทำงานที่ฟังก์ชัน 
    RTC.setAlarm1Simple(23, 9);
   if (RTC.checkIfAlarm(1)) {
   Serial.println("Alarm Triggered");
   }*/
  RTC.setAlarm1Simple(23, 9);

  RTC.turnOnAlarm(1);

  if (RTC.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }
  
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // initialize with the I2C addr 0x3C (for the 128x64)

  pinMode(SW1, INPUT_PULLUP);  //เกียร์ N
  pinMode(SW2, INPUT_PULLUP);  //เกียร์ 1
  pinMode(SW3, INPUT_PULLUP);  //เกียร์ 2
  pinMode(SW4, INPUT_PULLUP);  //เกียร์ 3
  pinMode(SW5, INPUT_PULLUP);  //เกียร์ 4
  pinMode(SW6, INPUT_PULLUP);  //เกียร์ 5
  pinMode(SW7, INPUT_PULLUP);} //เกียร์ 6
  
void loop(){
  A = digitalRead(SW1); 
  B = digitalRead(SW2); 
  C = digitalRead(SW3);
  D = digitalRead(SW4);
  E = digitalRead(SW5);
  F = digitalRead(SW6);
  G = digitalRead(SW7);
 
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;
  int g = 0;
  int s = 0;

float val = analogRead(Volume);
  val = analogRead(Volume)*0.0118;
  Serial.println(val);
  DateTime now = RTC.now();

   
  //////////////////////////////////////////////
  if((A==LOW)&&(B==HIGH))                                                                         //   GEAR N
{
    a=1;
  }
  if(a==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,3);
  OLED.setTextSize(8);  
  OLED.println("N");
  
  OLED.display(); 
  delay(100); }
 
else if((B==LOW)&&(A==HIGH))                                                                        //   GEAR 1
{
    b=1;
  }
  if(b==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("1"); 
  OLED.display(); 
  delay(100); }
  
  
  else if((C==LOW)&&(A==HIGH))                                                                        //   GEAR 2
{
    c=1;
  }
  if(c==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
   OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("2"); 
  OLED.display(); 
  delay(100); }


   else if((D==LOW)&&(A==HIGH))                                                                        //   GEAR 3
{
    d=1;
  }
  if(d==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
  OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("3"); 
  OLED.display(); 
  delay(100); }

     else if((E==LOW)&&(A==HIGH))                                                                        //   GEAR 4
{
    e=1;
  }
  if(e==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
 OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("4"); 
  OLED.display(); 
  delay(100); }

       else if((F==LOW)&&(A==HIGH))                                                                        //   GEAR 5
{
    f=1;
  }
  if(f==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
 OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("5"); 
  OLED.display(); 
  delay(100); }

         else if((G==LOW)&&(A==HIGH))                                                                        //   GEAR 6
{
    g=1;
  }
  if(g==1){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);   //Text is white ,background is black
  OLED.setCursor(0, 0);
  OLED.setTextSize(3); 
  OLED.println("GEAR");
 OLED.setCursor(0, 30);
  OLED.setTextSize(1);    
  OLED.print("BATT");
  
   OLED.setCursor(31, 30);
  OLED.setTextSize(1);    
  OLED.print(val);

     OLED.setCursor(60, 30);
  OLED.setTextSize(1);    
  OLED.print("V.");
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text  
     OLED.setCursor(20, 43);
  OLED.setTextSize(1);    
  OLED.print("CLOCK");
 
  OLED.setTextColor(WHITE,BLACK); // 'inverted' text
    OLED.setCursor(7, 55);
  OLED.println(now.hour(), DEC);
      OLED.setCursor(21, 55);
  OLED.println(":");
      OLED.setCursor(29, 55);
  OLED.println(now.minute(), DEC);
        OLED.setCursor(43, 55);
  OLED.println(":");
        OLED.setCursor(51, 55);
  OLED.println(now.second(), DEC);
  
  OLED.setCursor(80,0);
  OLED.setTextSize(8);  
  OLED.println("6"); 
  OLED.display(); 
  delay(100); }

}
