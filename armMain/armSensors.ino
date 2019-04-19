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
float ang = mpu6050.getAccX();
ang = max(-1,ang);
ang = min(1,ang);
ang = ang + 1; // ang is between 0 and 2;
return (1-ang/2)*100;
//return -1;
}

float shoulderRotPercent(){
//  return float(analogRead(A0)) / 1023 * 100;
float ang = mpu6050.getAccY();
ang = max(-1,ang);
ang = min(1,ang);
ang = ang + 1; // ang is between 0 and 2;
return ( ang/2)*100;
//return -1;
}
