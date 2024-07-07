//Autonomous Car Project
//Autonomous Control Script
//Harrison I. L. Milburn
//07.04.2024
//Arduino Uno Rev3

//Setup variables for the speed pins
int Left_Speed_Pin = 10;    //ENA
int Right_Speed_Pin = 5;    //ENB

//Setup variables for the direction
int Left_CW_Pin = 9;        //IN1
int Left_CCW_Pin = 8;       //IN2
int Right_CW_Pin = 7;       //IN3
int Right_CCW_Pin = 6;      //IN4

//Setup variables for Ultrasonic Sensor Pins
int trigPin = 3;            // Trigger pin
int echoPin = 4;            // Echo pin

void setup() {
    //Set Pin Modes to Output or Input
    pinMode(Left_Speed_Pin, OUTPUT);
    pinMode(Right_Speed_Pin, OUTPUT);
    pinMode(Left_CW_Pin, OUTPUT);
    pinMode(Left_CCW_Pin, OUTPUT);
    pinMode(Right_CW_Pin, OUTPUT);
    pinMode(Right_CCW_Pin, OUTPUT);

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

    if (distance < 10){
        stop();
        delay(200);

        left(150);
        delay(300);

        stop();
        delay(200);
    }

    else{
        forwards(200);
    }
}



void forwards(int speed){
    //Left Clockwise
    digitalWrite(Left_CW_Pin, HIGH);
    digitalWrite(Left_CCW_Pin, LOW);

    //Right Clockwise
    digitalWrite(Right_CW_Pin, HIGH);
    digitalWrite(Right_CCW_Pin, LOW);

    //Output Speed
    analogWrite(Left_Speed_Pin, speed);
    analogWrite(Right_Speed_Pin, speed);
}

void backwards(int speed){
    //Left Counter-Clockwise
    digitalWrite(Left_CW_Pin, LOW);
    digitalWrite(Left_CCW_Pin, HIGH);

    //Right Counter-Clockwise
    digitalWrite(Right_CW_Pin, LOW);
    digitalWrite(Right_CCW_Pin, HIGH);

    //Output Speed
    analogWrite(Left_Speed_Pin, speed);
    analogWrite(Right_Speed_Pin, speed);
}

void left(int speed){
    //Left Counter-Clockwise
    digitalWrite(Left_CW_Pin, LOW);
    digitalWrite(Left_CCW_Pin, HIGH);

    //Right Clockwise
    digitalWrite(Right_CW_Pin, HIGH);
    digitalWrite(Right_CCW_Pin, LOW);

    //Output Speed
    analogWrite(Left_Speed_Pin, speed);
    analogWrite(Right_Speed_Pin, speed);
}

void right(int speed){
    //Left Clockwise
    digitalWrite(Left_CW_Pin, HIGH);
    digitalWrite(Left_CCW_Pin, LOW);

    //Right Counter-Clockwise
    digitalWrite(Right_CW_Pin, LOW);
    digitalWrite(Right_CCW_Pin, HIGH);

    //Output Speed
    analogWrite(Left_Speed_Pin, speed);
    analogWrite(Right_Speed_Pin, speed);
}

void stop(){
    analogWrite(Left_Speed_Pin, 0);
    analogWrite(Right_Speed_Pin, 0);
}