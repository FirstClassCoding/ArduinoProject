int Num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int num[5];

int i;

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
  for(i=48;i<=52;i++)
  {
    pinMode(i,OUTPUT);
  }
  DDRA = 0xFF;
}

void loop()
{
  for(num[4]=0;num[4]<10;num[4]++)
  {
    for(num[3]=0;num[3]<10;num[3]++)
    {
      for(num[2]=0;num[2]<10;num[2]++)
      {
        for(num[1]=0;num[1]<10;num[1]++)
        {
          for(num[0]=0;num[0]<1;num[0]++)
          {
            display();
          }
        }
      }
    }
  }
}
