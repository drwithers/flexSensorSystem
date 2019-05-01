#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "armConstraints.hpp"

//I2C definitions
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

//Globals
int cur_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
int set_ang[6] = {OFF, OFF, OFF, OFF, OFF, OFF};
int bits = 10;

void setup() {
  Serial.begin(9600);
  //Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  delay(10);
  //analogReadResolution(bits);
  pwm.setPWM(0, 0, OFF);
  pwm.setPWM(1, 0, OFF);
  pwm.setPWM(2, 0, OFF);
  pwm.setPWM(3, 0, OFF);
  pwm.setPWM(4, 0, OFF);
  pwm.setPWM(5, 0, OFF);
}

void loop() {
    perset(40,35, 70, 25, 40, 70); //Flexing pose
    //perset(40,5, 10, 25, 40, 20); //Success pose
    //perset(-1,-1,-1,-1,-1,-1);//off
    go();
    delay(1000);
    //Serial.println("Here");
}
