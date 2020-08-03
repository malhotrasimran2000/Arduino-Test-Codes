void setup() {
  Serial.begin(38400);
  Serial1.begin(38400);

}

void loop() {
  
  while(Serial1.available())
  {
    Serial.print((char)Serial1.read());
  }
  while(Serial.available()){
    Serial1.write(Serial.read());
  }
}
