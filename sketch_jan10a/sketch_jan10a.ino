#include <Servo.h>

#define oneDeg 6.5
#define oneCM 60

Servo leftMotor;
Servo rightMotor;

int buttonPin = 4;
byte button = 0;

void setup() {
  leftMotor.attach(12);
  rightMotor.attach(13);

  delay(50);
  pinMode(10, INPUT);
  delay(50);
  pinMode(11, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  if (digitalRead(buttonPin) == HIGH) {
    lineTracker();
  }
  else if (digitalRead(buttonPin) == LOW && button == 0) {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1700);
    delay(oneDeg * 90);
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
    delay(1500);
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1500);
    delay(1500);
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
    delay(1500);
    button = 1;
  }
  else if (digitalRead(buttonPin) == HIGH && button == 1) {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1300);
    delay(oneDeg * 110);

    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
    delay(oneCM * 25);

    leftMotor.writeMicroseconds(1250);
    rightMotor.writeMicroseconds(1540);
    delay(oneCM * 90);
  }
}

void lineTracker() {

  int leftSensor = digitalRead(11);
  int rightSensor = digitalRead(10);

  if ((leftSensor == HIGH) && (rightSensor == HIGH)) {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
  }
  else if ((leftSensor == LOW) && (rightSensor == HIGH)) {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1700);
  }
  else if ((leftSensor == HIGH) && (rightSensor == LOW)) {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1500);
  }
  else if ((leftSensor == LOW) && (rightSensor == LOW)) {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
  }
  else {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1500);
  }
}
