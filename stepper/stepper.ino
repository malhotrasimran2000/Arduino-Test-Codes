const int dirPin  = 3;
const int stepPin = 4; 
const int enPin   = 5;
void setup() {
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}
void loop() {
  
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(stepPin,HIGH); 
    //delayMicroseconds(100); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
  //delay(500); // One second delay

  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(stepPin,HIGH);
    //delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
  }
  //delay(1000);
  
}
