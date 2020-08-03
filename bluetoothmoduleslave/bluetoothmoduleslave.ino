void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
Serial3.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
 while(Serial.available()){
Serial3.write(Serial.read());
 } 
while(Serial3.available()){
Serial.print((char)Serial3.read());

}
}
