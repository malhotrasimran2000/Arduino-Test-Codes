
#include <RazorIMU_9DOF.h>
#include <FourSBase.h>

// Declare an object of RazorIMU_9DOF type
RazorIMU_9DOF IMU;

FourSBase Base;


int PWM_pins[] = {9,11,3,5}; // List of PWM pins
int DIR_pins[] = {8,10,2,4}; // List of DIR pins
bool reverseDIRs[] = {false, false, false, false};

float trans_vel = 0;
float angle = 0;
float ang_vel = 0;



void setup() {

  // Initialize the Serials
  Serial1.begin(57600);
  Serial.begin(115200);
  // Attach the debugger serial
  IMU.debugger.Initialize("IMU_9DOF", &Serial);
  // Attach the IMU Serial
  IMU.AttachIMUSerial(&Serial1);
  // Set the IMU reference values (in the beginning)
  IMU.ResetReference();
  Base.AttachPins(PWM_pins, DIR_pins, reverseDIRs);
}

void loop() {
  // Update data from IMU
  IMU.UpdateData();
  // Get the YAW value
  float yaw = IMU.GetYaw();         // Continuous YAW value (0 to 360)
  float yaw_raw = IMU.GetRaw_YAW(); // Raw YAW value (-180 to 180)
  float yaw_rel = IMU.GetRel_YAW(); // Relative to the previous positioning

  String msg = "Yaw [Continuous, Raw, Relative]: ";
  msg.concat(yaw);
  msg.concat(" ");
  msg.concat(yaw_raw);
  msg.concat(" ");
  msg.concat(yaw_rel);
  Serial.println(msg);
  // Same for pitch
  float pitch = IMU.GetPitch();         // Continuous PITCH value (0 to 360)
  float pitch_raw = IMU.GetRaw_PITCH(); // Raw PITCH value (-180 to 180)
  float pitch_rel = IMU.GetRel_PITCH(); // Relative to the previous positioning
  msg = "Pitch [Continuous, Raw, Relative]: ";
  msg.concat(pitch);
  msg.concat(" ");
  msg.concat(pitch_raw);
  msg.concat(" ");
  msg.concat(pitch_rel);
  Serial.println(msg);


  if (pitch_rel >= 30) {
    angle = 0;
    trans_vel = 100;
    Base.Move(trans_vel, angle, ang_vel);
    
  }
  else if (pitch_rel <-30) {
    angle = 180;
    trans_vel = 100;
    Base.Move(trans_vel, angle, ang_vel);
  }

  else if (yaw_rel >= 30) {
    angle = -45;
    trans_vel = 100;
    Base.Move(trans_vel, angle, ang_vel);
  }
  else if (yaw_rel <-30) {
    angle = 45;
    trans_vel = 100; 
    Base.Move(trans_vel, angle, ang_vel);
  }
 else
   Base.Move(0,0,0);

}
