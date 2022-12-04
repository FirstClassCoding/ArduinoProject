// CONNECTIONS:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

int Num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int num[5];

int i,Hour,Minute;

void display()
{
  digitalWrite(48,1);
  digitalWrite(49,1);
  digitalWrite(50,1);
  digitalWrite(51,0);
  PORTA = Num[num[1]];
  delay(1);
  digitalWrite(48,1);
  digitalWrite(49,1);
  digitalWrite(50,0);
  digitalWrite(51,1);
  PORTA = Num[num[2]];
  delay(1);
  digitalWrite(48,1);
  digitalWrite(49,0);
  digitalWrite(50,1);
  digitalWrite(51,1);
  PORTA = Num[num[3]];
  delay(1);
  digitalWrite(48,0);
  digitalWrite(49,1);
  digitalWrite(50,1);
  digitalWrite(51,1);
  PORTA = Num[num[4]];
  delay(1);
}

void setup()
{
  Serial.begin(57600);

  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  Rtc.Begin();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  if (!Rtc.IsDateTimeValid()) 
  {
      // Common Causes:
      //    1) first time you ran and the device wasn't running yet
      //    2) the battery on the device is low or even missing

      Serial.println("RTC lost confidence in the DateTime!");
      Rtc.SetDateTime(compiled);
  }

  if (Rtc.GetIsWriteProtected())
  {
      Serial.println("RTC was write protected, enabling writing now");
      Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning())
  {
      Serial.println("RTC was not actively running, starting now");
      Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) 
  {
      Serial.println("RTC is older than compile time!  (Updating DateTime)");
      Rtc.SetDateTime(compiled);
  }
  else if (now > compiled) 
  {
      Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == compiled) 
  {
      Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
  
  for(i=48;i<=52;i++)
  {
    pinMode(i,OUTPUT);
  }
  DDRA = 0xFF;
}

void loop()
{
  RtcDateTime now = Rtc.GetDateTime();

    printDateTime(now);
    Serial.println();

    if (!now.IsValid())
    {
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(1000); // ten seconds

    digitalWrite(48,1);
    digitalWrite(49,1);
    digitalWrite(50,1);
    digitalWrite(51,0);
    PORTA = Num[1];
    digitalWrite(48,1);
    digitalWrite(49,1);
    digitalWrite(50,0);
    digitalWrite(51,1);
    PORTA = Num[2];
    digitalWrite(48,1);
    digitalWrite(49,0);
    digitalWrite(50,1);
    digitalWrite(51,1);
    PORTA = Num[3];
    digitalWrite(48,0);
    digitalWrite(49,1);
    digitalWrite(50,1);
    digitalWrite(51,1);
    PORTA = Num[4];
    
  /*for(num[4]=0;num[4]<10;num[4]++)
  {
    for(num[3]=0;num[3]<10;num[3]++)
    {
      for(num[2]=0;num[2]<10;num[2]++)
      {
        for(num[1]=0;num[1]<10;num[1]++)
        {
          for(num[0]=0;num[0]<250;num[0]++)
          {
            display();
          }
        }
      }
    }
  }*/
  delay(1);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Day(),
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
            Hour = dt.Hour();
            Minute = dt.Minute();
    Serial.print(datestring);
}
