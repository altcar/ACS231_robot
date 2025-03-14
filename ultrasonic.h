
const int trigPin = 40;
const int echoPin = 42;

void USsetup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void USloop() {
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
    Serial.print(cm);
    Serial.println(" cm");
  }
}
