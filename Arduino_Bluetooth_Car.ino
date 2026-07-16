/*
=========================================================
Project : Bluetooth Controlled RC Car using Arduino
Author  : Ansh Rastogi
Board   : Arduino Uno
Bluetooth Module : HC-05
Language : Arduino (C++)

Description:
A Bluetooth-controlled robotic car that receives commands
from an Android smartphone via the HC-05 Bluetooth module
and controls four DC motors through a motor driver.

Supported Commands:
F - Forward
B - Backward
L - Left
R - Right
S - Stop

=========================================================
*/

// -------------------- Pin Configuration --------------------

// Motor A
const int ENA = 5;
const int IN1 = 2;
const int IN2 = 3;

// Motor B
const int ENB = 6;
const int IN3 = 4;
const int IN4 = 7;

// Motor Speed (0–255)
const int MOTOR_SPEED = 255;

char command = 'S';


// -------------------- Setup --------------------

void setup() {

  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();
}


// -------------------- Main Loop --------------------

void loop() {

  if (Serial.available() > 0) {

    command = Serial.read();

    switch (command) {

      case 'F':
        moveForward();
        break;

      case 'B':
        moveBackward();
        break;

      case 'L':
        turnLeft();
        break;

      case 'R':
        turnRight();
        break;

      case 'S':
        stopCar();
        break;

      default:
        stopCar();
        break;
    }
  }
}


// -------------------- Movement Functions --------------------

void moveForward() {

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void moveBackward() {

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void turnLeft() {

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void turnRight() {

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void stopCar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
