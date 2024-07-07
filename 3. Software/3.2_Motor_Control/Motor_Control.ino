//Autonomous Car Project
//Motor Control Script
//Harrison I. L. Milburn
//29.05.2024
//Arduino Uno Rev3

//Setup variables for the speed pins
int Left_Speed_Pin = 10;    //ENA
int Right_Speed_Pin = 5;    //ENB

//Setup variables for the direction
int Left_CW_Pin = 9;        //IN1
int Left_CCW_Pin = 8;       //IN2
int Right_CW_Pin = 7;       //IN3
int Right_CCW_Pin = 6;      //IN4

void setup() {
  //Set Pin Modes to Output or Input
  pinMode(Left_Speed_Pin, OUTPUT);
  pinMode(Right_Speed_Pin, OUTPUT);
  pinMode(Left_CW_Pin, OUTPUT);
  pinMode(Left_CCW_Pin, OUTPUT);
  pinMode(Right_CW_Pin, OUTPUT);
  pinMode(Right_CCW_Pin, OUTPUT);
}

void loop() {
  forwards(200);
  delay(100);

  left(100);
  delay(100);

  forwards(200);
  delay(100);

  right(100);
  delay(100);
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
