const int W1=5;//right wheel
const int W2=6;//left wheel
const int W1dir=7;
const int W2dir=8;
int i;
char motion='s';
char state;
float t;
void setup() {
  // put your setup code here, to run once:
pinMode(W1,OUTPUT);
pinMode(W2,OUTPUT);
pinMode(W1dir,OUTPUT);
pinMode(W2dir,OUTPUT);

Serial.begin(9600);
}

void loop() {
  //Enter 'f' for forward motion,'b' for backward motion,'r' to turn right,'l' to turn left and 's' to stop
  while(Serial.available()){
    motion =Serial.read();
  }
// To move forward 
  if(motion=='f'){
    Serial.println("Enter the time duration");
    t=Serial.read();
  digitalWrite(W1dir,HIGH);
  digitalWrite(W2dir,HIGH);
  analogWrite(W1,150);
  analogWrite(W2,150);
  delay(t);
  analogWrite(W1,50);
  analogWrite(W2,50);

  state='f';
  }
//To move backward 
  if(motion=='b'){
  Serial.println("Enter the time duration");
  t=Serial.read();
  digitalWrite(W1dir,LOW);
  digitalWrite(W2dir,LOW);
  analogWrite(W1,150);
  analogWrite(W2,150);
  delay(t);
  state='b';

  
}
//To turn right 
if (motion=='r'){
  Serial.println("Enter the time duration");
  t=Serial.read();
  digitalWrite(W1dir,HIGH);
  digitalWrite(W2dir,HIGH);
  analogWrite(W1,50);
  analogWrite(W2,150);
  delay(t);
}
//To turn left 
if (motion=='l'){
    Serial.println("Enter the time duration");
  t=Serial.read();
  digitalWrite(W1dir,HIGH);
  digitalWrite(W2dir,HIGH);
  analogWrite(W2,50);
  analogWrite(W1,150);
}
//To stop motion
if(motion=='s'){
  if(state=='f'){
  digitalWrite(W1dir,LOW);
  digitalWrite(W2dir,LOW);

  analogWrite(W1,50);
  analogWrite(W2,50);
  delay(100);
  analogWrite(W1,0);
  analogWrite(W2,0);
}

  if(state=='b'){
  digitalWrite(W1,HIGH);
  digitalWrite(W2,HIGH);

  analogWrite(W1,50);
  analogWrite(W2,50);
  delay(100);
  analogWrite(W1,0);
  analogWrite(W2,0);
  
}


}
} 
