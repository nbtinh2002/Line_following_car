// You have to install AFMOTOR library before upload code
// Sketch >> Include Library >> Add .Zip Library >> select AFMotor.zip

#include <AFMotor.h>

//Define pins ,motors
#define left_sensor  A4
#define right_sensor A5
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
int leftState, rightState;

void setup() {
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor,INPUT);
  Serial.begin(9600);
}

void loop(){
  // read sensor values once
  leftState = digitalRead(left_sensor);
  rightState = digitalRead(right_sensor);

  if(leftState == 0 && rightState == 0){
    // Move forward
    motor1.run(FORWARD); 
    motor1.setSpeed(80);
    motor2.run(FORWARD);
    motor2.setSpeed(80);
  }
  else if(leftState == 1 && rightState == 0){
    // Turn left
    motor1.run(BACKWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
  }
  else if(leftState == 0 && rightState == 1){
    // Turn right
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(BACKWARD);
    motor2.setSpeed(70);
  }
  else if(leftState == 1 && rightState == 1){
    // Stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
  }
}