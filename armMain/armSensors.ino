// This function reads the sensor a number of times and 
// takes the average of those. Then it returns the average.
int bendread(int outpin, int adc){
  static const int avg = 25;
  int data;
  digitalWrite(outpin,HIGH);
  delay(20);
  data = 0;
  for(int i=0;i<avg;i++){
    data = data + analogRead(adc);
  }
  data = data/avg;
  digitalWrite(outpin,LOW);
  //if (data > datamax) datamax = data;
  return data;
}

float accread(char axis){
  static const int avg = 25;
  float ang = 0,dat = 0;
  for(int i=0;i<avg;i++){
    mpu6050.update();
    switch(axis){
      case 'x':
        dat = mpu6050.getAccX();
        ang = constrain(dat,-1,1) + ang + 1;
        break;
      case 'y':
        dat = mpu6050.getAccY();
        ang = constrain(dat,-1,1) + ang + 1;
        break;
      default:
        Serial.println("Error running accread:");
        break;
    }
  }
  ang = ang / avg;
  return ang;
}


float gripPercent(){
//  static int sensor_max5 = 0;
//  int sdata;
//  sdata = bendread(11,A5);
//  sensor_max5 = max(sdata, sensor_max5);
//  return (1-float(sdata)/float(sensor_max5))*100;
return -1;
}

float twistPercent(){
//  static int sensor_max4 = 0;
//  int sdata;
//  sdata = bendread(10,A4);
//  sensor_max4 = max(sdata, sensor_max4);
//  return float(sdata)/float(sensor_max4)*100;
//  return float(analogRead(A4)) / 1023 * 100;

return -1;
}

float wristPercent(){
//  return float(analogRead(A3)) / 1023 * 100;
return -1;
}

float elbowPercent(){
//  static int sensor_max2 = 0;
//  int sdata;
//  sdata = bendread(9,A2);
//  sensor_max2 = max(sdata, sensor_max2);
//  return float(sdata)/float(sensor_max2)*100;
//  return float(analogRead(A2)) / 1023 * 100;
return -1;
}

float shoulderExtPercent(){
//  return float(analogRead(A1)) / 1023 * 100;
char ax = 'x';
float ang = accread(ax);
Serial.println(ang);
return (1-ang/2)*100;
//return -1;
}

float shoulderRotPercent(){
//  return float(analogRead(A0)) / 1023 * 100;
char ax = 'y';
float ang = accread(ax);
return ( ang/2)*100;
//return -1;
}
