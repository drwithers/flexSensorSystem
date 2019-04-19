#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

#define SERVOMIN  50 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

int buttonPin = 13;
int btn = 0;
uint8_t servonum = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Range Finder!");
  pinMode(13,INPUT);
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  delay(10);
}

void loop() {
  Serial.print("Testing Servo: "); Serial.println(servonum);
  Serial.println("Finding SERVOMAX:");
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX;) {
    btn = digitalRead(buttonPin);
    if(btn == LOW){ 
      pulselen++;
      pwm.setPWM(servonum, 0, pulselen);
      Serial.println(pulselen);
      delay(50);
    }
  }

  Serial.println("Finding SERVOMIN:");
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN;) {
    btn = digitalRead(buttonPin);
    if(btn == LOW){ 
      pulselen--;
      pwm.setPWM(servonum, 0, pulselen);
      Serial.println(pulselen);
      delay(50);
    }
  }
  pwm.setPWM(servonum, 0, 4096);
  delay(500);
  servonum --;
  if (servonum < 0) servonum = 5;
}
