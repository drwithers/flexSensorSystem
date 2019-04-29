int max_usec = 20000;
int minn = 550, maxx = 2400;
int bval = (maxx+minn)/2;
bool up = true;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  //int on = bval*max_usec/4069;
  digitalWrite(2,HIGH);
  delayMicroseconds(bval);//on);
  digitalWrite(2,LOW);
  delayMicroseconds(max_usec-bval);//on);
  
  if (digitalRead(8)==LOW){
    int inc = 25;
    if(up){
      bval = bval + inc;
    }else{
      bval = bval - inc;
    }
    if(bval>=maxx)up = false;
    if(bval<=minn)up = true;
    Serial.println(bval);
  }
}
