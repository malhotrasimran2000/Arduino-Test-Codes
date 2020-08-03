int IRpin=8;
void setup() {
  // put your setup code here, to run once:
pinMode(IRpin,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("IR sensor value: ");
Serial.println(digitalRead(IRpin));
delayMicroseconds(20);

if(digitalRead(IRpin)==1)
{
digitalWrite(13,HIGH);
}
else{
digitalWrite(13,LOW);
}
}
