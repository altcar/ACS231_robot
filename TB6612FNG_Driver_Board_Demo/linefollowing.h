
int sensorL = 27;
int sensorC = 29;
int sensorR = 31;


void LFsetup() {

  // put your setup code here, to run once:
  pinMode(sensorL, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorR, INPUT);
}

String LFloop() {
  String p = " ";
p+= digitalRead(sensorL);
p+= digitalRead(sensorC);
p+= digitalRead(sensorR);
Serial.println(p);
return p;
}
