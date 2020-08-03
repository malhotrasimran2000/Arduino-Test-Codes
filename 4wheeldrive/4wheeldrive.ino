const int LF=5;//LpwmPin1
const int LB=6;//LpwmPin2
const int LFdir=2;//Ldir1Pin
const int LBdir=4;//Ldir2Pin
const int RF=10;//RpwmPin1
const int RB=11;//RpwmPin2
const int RFdir=12;//Rdir1Pin
const int RBdir=13;//Rdir2Pin
int i;
char motion='s';
char state;
void setup() {
  // put your setup code here, to run once:
pinMode(LF,OUTPUT);
pinMode(LB,OUTPUT);
pinMode(RF,OUTPUT);
pinMode(RB,OUTPUT);
pinMode(LFdir,OUTPUT);
pinMode(LBdir,OUTPUT);
pinMode(RFdir,OUTPUT);
pinMode(RBdir,OUTPUT);
Serial.begin(9600);
}

void loop() {
  //Enter 'f' for forward motion,'b' for backward motion,'r' to turn right,'l' to turn left and 's' to stop
  while(Serial.available()){
    motion =Serial.read();
  }
// To move forward 
  if(motion=='f'){
  digitalWrite(LFdir,HIGH);
  digitalWrite(LBdir,HIGH);
  digitalWrite(RFdir,HIGH);
  digitalWrite(RBdir,HIGH);
  analogWrite(LF,150);
  analogWrite(LB,150);
  analogWrite(RF,150);
  analogWrite(RB,150);
  delay(2000);
  analogWrite(LF,50);
  analogWrite(LB,50);
  analogWrite(RF,50);
  analogWrite(RB,50);
  state='f'
  }
//To move backward 
  if(motion=='b'){
  digitalWrite(LFdir,LOW);
  digitalWrite(LBdir,LOW);
  digitalWrite(RFdir,LOW);
  digitalWrite(RBdir,LOW);
  analogWrite(LF,150);
  analogWrite(LB,150);
  analogWrite(RF,150);
  analogWrite(RB,150);
  delay(2000);
  state='b';

  
}
//To turn right 
if (motion=='r'){
  digitalWrite(LFdir,HIGH);
  digitalWrite(RBdir,HIGH);
  analogWrite(LF,150);
  analogWrite(LB,150);
  analogWrite(RF,50);
  analogWrite(RB,50);
}
//To turn left 
if (motion=='l'){
  digitalWrite(RFdir,HIGH);
  digitalWrite(LBdir,HIGH);
  analogWrite(LF,50);
  analogWrite(LB,50);
  analogWrite(RF,150);
  analogWrite(RB,150);
}
//To stop motion
if(motion=='s'){
  if(state=='f'){
  digitalWrite(LFdir,LOW);
  digitalWrite(LBdir,LOW);
  digitalWrite(RFdir,LOW);
  digitalWrite(RBdir,LOW);
  analogWrite(LF,50);
  analogWrite(LB,50);
  analogWrite(RF,50);
  analogWrite(RB,50);
  delay(100);
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}

  if(state=='b'){
  digitalWrite(LFdir,HIGH);
  digitalWrite(LBdir,HIGH);
  digitalWrite(RFdir,HIGH);
  digitalWrite(RBdir,HIGH);
  analogWrite(LF,50);
  analogWrite(LB,50);
  analogWrite(RF,50);
  analogWrite(RB,50);
  delay(100);
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}


}
} 
