#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire); //address 0X68 I believe

float p0,p1,p2,p3,p4,p5;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("= Sensor Debug =");
  delay(100);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);
  Serial.println("= Good Luck!!! =");
  delay(100);
  pinMode(30,OUTPUT);pinMode(31,OUTPUT);
  pinMode(34,OUTPUT);pinMode(35,OUTPUT);
  pinMode(38,OUTPUT);pinMode(39,OUTPUT);
  pinMode(42,OUTPUT);pinMode(43,OUTPUT);
  pinMode(46,OUTPUT);pinMode(47,OUTPUT);
}

void loop() {
  Serial.println("=====================");
  mpu6050.update();
  Serial.print("  rotate: ");
  p0=shoulderRotPercent();
  Serial.print("  extend: ");
  p1=shoulderExtPercent();
  Serial.print("  elbow:  ");
  p2=elbowPercent();
  Serial.print("  wrist:  ");
  p3=wristPercent();
  Serial.print("  twist:  ");
  p4=twistPercent();
  Serial.print("  hand:   ");
  p5=gripPercent();
  Serial.print("=====================");
  delay(500);
}
