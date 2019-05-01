// This function reads the sensor a number of times and 
// takes the average of those. Then it returns the average.
int bendread(int outpin, int adc){
  static const int avg = 25;
  int data;
  digitalWrite(outpin,HIGH);
  delay(30);
  data = 0;
  for(int i=0;i<avg;i++){
    //delay(10);
    data = data + analogRead(adc);
  }
  data = data/avg;
  digitalWrite(outpin,LOW);
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
        //Serial.print("ang:"); Serial.print(ang);Serial.println(axis);
        break;
      case 'y':
        dat = mpu6050.getAccY();
        ang = constrain(dat,-1,1) + ang + 1;
        //Serial.print("ang:"); Serial.print(ang);Serial.println(axis);
        break;
      default:
        Serial.println("Error running accread:");
        break;
    }
  }
        //Serial.println("after for:");
  ang = ang / avg;//calculate average angle
  return ang;
}


float gripPercent(){
  static int sensor_max5 = 0;
  int sdata;
  sdata = bendread(11,A7);
  sensor_max5 = max(sdata, sensor_max5);
  Serial.print(sdata);Serial.print("/");Serial.println(sensor_max5);
  return (1-float(sdata)/float(sensor_max5))*100;
}

float twistPercent(){
  static int sensor_max4 = 0;
  int sdata;
  sdata = bendread(10,A6);
  sensor_max4 = max(sdata, sensor_max4);
  Serial.print("\t");Serial.print(sdata);Serial.print("/");Serial.println(sensor_max4);
  return float(sdata)/float(sensor_max4)*100;
}

float wristPercent(){
  static int sensor_max3 = 0;
  int sdataT, sdataB;
  sdataB = bendread(38,A4);
  sdataT = bendread(42,A5);
  sensor_max3 = max(sdataB, sensor_max3);
  Serial.print("\t");Serial.print(sdataB);Serial.print("/");Serial.println(sensor_max3);
  return float(sdataB)/float(sensor_max3)*100;
}

float elbowPercent(){
  static int sensor_max2 = 0;
  int sdata;
  sdata = bendread(9,A2);
  sensor_max2 = max(sdata, sensor_max2);
  Serial.print("\t");Serial.print(sdata);Serial.print("/");Serial.println(sensor_max2);
  return float(sdata)/float(sensor_max2)*100;
}

float shoulderExtPercent(){
char axis = 'x';
float ang = accread(axis);
Serial.println(ang);
return (1-ang/2)*100;

}

float shoulderRotPercent(){
char axis = 'y';
float ang = accread(axis);
Serial.println(ang);
return ( ang/2)*100;
}
