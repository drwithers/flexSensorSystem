#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "armConstraints.hpp"
#include <MPU6050_tockn.h>

//I2C definitions
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire1, 0x40);
MPU6050 mpu6050(Wire); //address 0X68 I believe

//Globals
int cur_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
int set_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
float p0, p1, p2, p3, p4, p5;
int bits = 10;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  //Set output pins for each sensor's LED and Photoresistor
  pinMode(30,OUTPUT);pinMode(31,OUTPUT);
  pinMode(34,OUTPUT);pinMode(35,OUTPUT); 
  pinMode(38,OUTPUT);pinMode(39,OUTPUT);
  pinMode(42,OUTPUT);pinMode(43,OUTPUT);
  pinMode(46,OUTPUT);pinMode(47,OUTPUT);
  delay(100);
  //analogReadResolution(bits);
  //Set PWM range values for each motor
  //OFF is defined in armConstraints.hpp as 4096
  pwm.setPWM(pins[shoulder_rot], 0, OFF);
  pwm.setPWM(pins[shoulder_ex], 0, OFF);
  pwm.setPWM(pins[elbow], 0, OFF);
  pwm.setPWM(pins[wrist_b], 0, OFF);
  pwm.setPWM(pins[wrist_t], 0, OFF);
  pwm.setPWM(pins[grip], 0, OFF);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);
}

void loop() {
  Serial.println("=====================");
  mpu6050.update();
  
  Serial.print("  rotate: ");
  p0 = shoulderRotPercent();
  Serial.print(" ", p0);
  
  Serial.print("  extend: ");
  p1 = shoulderExtPercent();
  Serial.print(" ", p1);
  
  Serial.print("  elbow:  ");
  p2 = elbowPercent();
  Serial.print(" ", p2);
  
  Serial.print("  wrist:  ");
  p3 = wristPercent();
  Serial.print(" ", p3);
  
  Serial.print("  twist:  ");
  p4 = twistPercent();
  Serial.print(" ", p4);
  
  Serial.print("  hand:   ");
  p5 = gripPercent();
  Serial.print(" ", p5);
  Serial.println("=====================");
  
  perset(p0, p1, p2, p3, p4, p5);
  //Serial.println("after set");
  go();
  //Serial.println("after go");
  delay(500);
  Serial.println("=====================");
}
