//Autonomous Car Project
//"Hello World" Script
//Harrison I. L. Milburn
//07.04.2024
//Arduino Uno Rev3

void setup() {
  //Begin the Serial Monitor with Baud Rate of 9600
  Serial.begin(9600);
}

void loop() {
  //Print line to monitor and start a new line after
  Serial.println("Hello World");
  //Pause the program for 1/2 a second
  delay(500);
}
