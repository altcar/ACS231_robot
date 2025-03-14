

void LFsetup() {

  // put your setup code here, to run once:
  pinMode(22, INPUT);
    pinMode(24, INPUT);
      pinMode(26, INPUT);
}

void LFloop() {
  // put your main code here, to run repeatedly:
    Serial.print(digitalRead(22));
    
    Serial.print(digitalRead(24));
    Serial.print(digitalRead(26));
}
