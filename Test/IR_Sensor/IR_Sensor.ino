int val;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(8);//อ่านค่าสัญญาณ digital ขา8 ที่ต่อกับ เซ็นเซอร์ตรวจจับวัตถุ IR Infrared
    Serial.println(val);
  if (val == 1) { // ค่า เป็น 0 แสดงว่าตรวจพบวัตถุ
    digitalWrite(13, 1); // เปิดไฟ LED
    Serial.print("Detect Object ");
  }
  else {
    digitalWrite(13, 0); // ปิดไฟ LED
    Serial.print("Not Detect ");
  }
  delay(100);
}
