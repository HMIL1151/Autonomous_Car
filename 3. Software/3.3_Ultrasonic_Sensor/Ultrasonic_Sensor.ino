//Autonomous Car Project
//Ultrasonic Sensor Script
//Harrison I. L. Milburn
//29.05.2024
//Arduino Uno Rev3

int trigPin = 3; // Trigger pin of the ultrasonic sensor
int echoPin = 4; // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance; // Variables to store the duration of sound wave travel and calculated distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Send a 10us pulse to trigger the sensor
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Measure the time it takes for the echo to return
  distance = (duration * 0.0343) / 2; // Calculate distance in centimeters (speed of sound in air is approximately 343 m/s)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(50); // Delay for stability
}
