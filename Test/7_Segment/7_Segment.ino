int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int h = 9;

void setup(){

  pinMode(a,INPUT_PULLUP);
  pinMode(b,INPUT_PULLUP);
  pinMode(c,INPUT_PULLUP);
  pinMode(d,INPUT_PULLUP);
  pinMode(e,INPUT_PULLUP);
  pinMode(f,INPUT_PULLUP);
  pinMode(g,INPUT_PULLUP);
  pinMode(h,INPUT_PULLUP);
  
}

void loop(){

  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(h,LOW);
  
}

