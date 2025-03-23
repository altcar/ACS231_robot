// unsigned long timestamp;
// unsigned long elapsed;
// unsigned long controlRate = 15; // milliseconds

// void setup() {
//   timestamp = millis();
// }
 
// void loop() {
//   // anything here will execute at an unrestricted rate
//   // (e.g. reading Analog Inputs)
  
//   elapsed = millis() - timestamp;
//   if ( elapsed > controlRate ) {
//     // anything here will execute at the "controlRate"
//     // (e.g. sending commands to your servos)

//     // update the timestamp each time this executes:
//     timestamp = millis();
//   }
// }
