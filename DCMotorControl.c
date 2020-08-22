/************************************************
This program is used to control one DC motor with
L298N motor driver module.
************************************************/
#define IN1 7
#define IN2 6 #Provide PWM signal
#define MAX_SPEED  255
#define MIN_SPEED  0

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void stop_motor(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void forward(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}

void backward(int speed){
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}

void loop() {
  // put your main code here, to run repeatedly:
 forward(MAX_SPEED);
 delay(5000);
 stop_motor();
 delay(2000);
 backward(MAX_SPEED);
 delay(5000);
 stop_motor();
 delay(2000);
}