
const int trigPin = 25;
const int echoPin = 23;

void USsetup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long USloop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  if (duration == 0) {
    Serial.println("No echo detected!");
  } else {
    long cm = (duration / 2) / 29.1;
    Serial.print("Distance: ");
    Serial.println(cm);
    // Serial.println(" cm");
    return cm;
}
  }
  
