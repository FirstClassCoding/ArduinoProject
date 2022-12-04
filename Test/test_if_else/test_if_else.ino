float Volume = 0;

void setup(){

  pinMode(13,OUTPUT);
  
}

void loop(){

  float val = analogRead(Volume);
  val = analogRead(Volume)*0.0046;

  if(val > 4.4){
    digitalWrite(13,HIGH);
  }
  else if(val > 3){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(1000);
  }
  else{
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }
}

