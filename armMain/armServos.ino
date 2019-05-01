// This function determines the servo PWM value based 
// off the percent posible movement values.
void perset(float j1, float j2, float j3, float j4, float j5, float j6) {
  j1 = min(j1, 100); j2 = min(j2, 100);
  j3 = min(j3, 100); j4 = min(j4, 100);
  j5 = min(j5, 100); j6 = min(j6, 100);
  set_ang[0] = int((j1 >= 0) ? (smin[0] + ((smax[0] - smin[0]) * j1 / 100)) : OFF);
  set_ang[1] = int((j2 >= 0) ? (smin[1] + ((smax[1] - smin[1]) * j2 / 100)) : OFF);
  set_ang[2] = int((j3 >= 0) ? (smin[2] + ((smax[2] - smin[2]) * j3 / 100)) : OFF);
  set_ang[3] = int((j4 >= 0) ? (smin[3] + ((smax[3] - smin[3]) * j4 / 100)) : OFF);
  set_ang[4] = int((j5 >= 0) ? (smin[4] + ((smax[4] - smin[4]) * j5 / 100)) : OFF);
  set_ang[5] = int((j6 >= 0) ? (smin[5] + ((smax[5] - smin[5]) * j6 / 100)) : OFF);
}

// This function is used to move the servos from the 
// current values to the set values all simultaneously.
void go() {
//  int inc;
//  const int inc_val = 1;
//  while (set_ang[0] != cur_ang[0] || set_ang[1] != cur_ang[1] ||
//         set_ang[2] != cur_ang[2] || set_ang[3] != cur_ang[3] ||
//         set_ang[4] != cur_ang[4] || set_ang[5] != cur_ang[5]) {
//    for (uint8_t j = 0; j < JOINTS; j++) { 
//      if (set_ang[j] > cur_ang[j]) {
//        if (set_ang[j] == OFF) {
//          cur_ang[j] == OFF;
//          inc = 0;
//        }
//        else inc = inc_val;
//      }
//      else if (set_ang[j] < cur_ang[j]) {
//        if (cur_ang[j] == OFF) {
//          cur_ang[j] = smin[j] + ((smax[j] - smin[j]) * 50 / 100);// set the current agle to 50% of the range of motion.
//          inc = 0;
//        }
//        else inc = -inc_val;
//      }
//      else {
//        inc = 0;
//      }
//      cur_ang[j] = cur_ang[j] + inc;
//      pwm.setPWM(pins[j], 0, cur_ang[j]);
//      Serial.print(cur_ang[j]);Serial.print(":");Serial.println(set_ang[j]);
//      if(j==5) Serial.println("go");
//    }
//    delay(1);
//  }
// this may not work if the motors are not plugged into ports 0-5
  for (uint8_t j = 0; j < JOINTS; j++) {
    cur_ang[j] = set_ang[j];
    pwm.setPWM(pins[j], 0, cur_ang[j]);
  }
}
