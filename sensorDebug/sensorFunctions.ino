// This function reads the sensor a number of times and 
// takes the average of those. Then it returns the average.
int bendread(int outpin, int adc){
  static const int avg = 25;
  int data;
  digitalWrite(outpin,HIGH);
  digitalWrite(outpin+1,HIGH);
  delay(30);
  data = 0;
  for(int i=0;i<avg;i++){
    delay(10);
    data = data + analogRead(adc);
  }
  data = data/avg;
//  Serial.print("\t");Serial.println(data);
  digitalWrite(outpin,LOW);
  digitalWrite(outpin+1,LOW);
  //if (data > datamax) datamax = data;
  return data;
}

float accread(char axis){
  delay(10);
  static const int avg = 3;
  float ang = 0,dat = 0;
        //Serial.println("before for:");
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
        //Serial.println("after for:");
  ang = ang / avg;
  Serial.print("\t"); Serial.print(ang);Serial.print("/2.00 ");Serial.println(axis);
  return ang;
}


float gripPercent(){
  static int sensor_max5 = 0;
  int sdata;
  sdata = bendread(46,A6);
  sensor_max5 = max(sdata, sensor_max5);
  Serial.print("\t");Serial.print(sdata);Serial.print("/");Serial.println(sensor_max5);
  return (1-float(sdata)/float(sensor_max5))*100;
//return -1;
}

float twistPercent(){
  static int sensor_max4 = 0;
  int sdata;
  sdata = bendread(34,A3);
  sensor_max4 = max(sdata, sensor_max4);
  Serial.print("\t");Serial.print(sdata);Serial.print("/");Serial.println(sensor_max4);
  return float(sdata)/float(sensor_max4)*100;
//  return float(analogRead(A4)) / 1023 * 100;
//return -1;
}

float wristPercent(){
  static int sensor_max3 = 0;
  int sdataT, sdataB;
  sdataB = bendread(38,A4);
  sdataT = bendread(42,A5);
  sensor_max3 = max(sdataB, sensor_max3);
  Serial.print("\t");Serial.print(sdataB);Serial.print("/");Serial.println(sensor_max3);
  return float(sdataB)/float(sensor_max3)*100;
//  return float(analogRead(A3)) / 1023 * 100;
//return -1;
}

float elbowPercent(){
  static int sensor_max2 = 0;
  int sdata;
  sdata = bendread(30,A2);
  sensor_max2 = max(sdata, sensor_max2);
  Serial.print("\t");Serial.print(sdata);Serial.print("/");Serial.println(sensor_max2);
  return float(sdata)/float(sensor_max2)*100;
//  return float(analogRead(A2)) / 1023 * 100;
//return -1;
}

float shoulderExtPercent(){
//return float(analogRead(A1)) / 1023 * 100;
char ax = 'x';
float ang = accread(ax);
//Serial.println(ang);
return (1-ang/2)*100;
//return -1;
}

float shoulderRotPercent(){
//return float(analogRead(A0)) / 1023 * 100;
char ax = 'y';
float ang = accread(ax);
return ( ang/2)*100;
//return -1;
}
