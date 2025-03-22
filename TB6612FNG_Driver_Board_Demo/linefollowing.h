
int sensorL = 29;
int sensorC = 31;
int sensorR = 33;


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
return p;
}
