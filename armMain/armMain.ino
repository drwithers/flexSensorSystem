#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "armConstraints.hpp"
#include <MPU6050_tockn.h>

//I2C definitions
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);
MPU6050 mpu6050(Wire); //address 0X68 I believe

//Globals
int cur_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
int set_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
float p0, p1, p2, p3, p4, p5;
int bits = 10;

void setup() {
  Serial.begin(9600);
  //Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  //pinMode(11,OUTPUT);
  //pinMode(10,OUTPUT);
  //pinMode(9,OUTPUT);
  //pinMode(20,OUTPUT);
  //pinMode(21,OUTPUT);
  //pinMode(2,OUTPUT);
  delay(10);
  //analogReadResolution(bits);
  pwm.setPWM(pins[shoulder_rot], 0, OFF);
  pwm.setPWM(pins[shoulder_ex], 0, OFF);
  pwm.setPWM(pins[elbow], 0, OFF);
  pwm.setPWM(pins[wrist_b], 0, OFF);
  pwm.setPWM(pins[wrist_t], 0, OFF);
  pwm.setPWM(pins[grip], 0, OFF);
  mpu6050.begin();
  //mpu6050.calcGyroOffsets(true);
}

void loop() {
  //mpu6050.update();
  p0 = shoulderRotPercent();
  Serial.println("after p0");
  p1 = shoulderExtPercent();
  Serial.println("after p1");
  p2 = elbowPercent();
  Serial.println("after p2");
  p3 = wristPercent();
  Serial.println("after p3");
  p4 = twistPercent();
  Serial.println("after p4");
  p5 = gripPercent();
  Serial.println("after p5");
  //delay(50);
  Serial.println("after read");
  perset(p0, p1, p2, p3, p4, p5);
  Serial.println("after set");
  go();
  Serial.println("after go");
  //delay(40);
}
