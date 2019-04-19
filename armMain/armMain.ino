#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "armConstraints.hpp"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

//Globals
int cur_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
int set_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
float p0, p1, p2, p3, p4, p5;
int bits = 10;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  delay(10);
  analogReadResolution(bits);
  pwm.setPWM(pins[shoulder_rot], 0, OFF);
  pwm.setPWM(pins[shoulder_ex], 0, OFF);
  pwm.setPWM(pins[elbow], 0, OFF);
  pwm.setPWM(pins[wrist_b], 0, OFF);
  pwm.setPWM(pins[wrist_t], 0, OFF);
  pwm.setPWM(pins[grip], 0, OFF);
}

void loop() {
  p0 = shoulderRotPercent();
  p1 = shoulderExtPercent();
  p2 = elbowPercent();
  p3 = wristPercent();
  p4 = twistPercent();
  p5 = gripPercent();
  //delay(50);
  //Serial.println("after read");
  perset(p0, p1, p2, p3, p4, p5);
  //Serial.println("after set");
  go();
  //Serial.println("after go");
  //delay(40);
}
