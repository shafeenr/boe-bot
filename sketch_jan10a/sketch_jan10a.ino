#include <Servo.h> // Preprocessor scans Servo header file

/* 

Here we figured out approximately how much milliseconds
in delay would let our bot move approximately one degree
and one centimetre

The #define directive is used instead of declaring
variable of data type int with const keyword
because the former uses less memory in the Arduino

*/

#define oneDeg 6.5 // 1 degree is around 6.5 ms
#define oneCM 60 // 1 centimetre is around 60 ms

Servo leftMotor; // Declare left motor
Servo rightMotor; // Declare right motor

void setup() {

  leftMotor.attach(12); // Set leftMotor signal to pin 12
  rightMotor.attach(13); // Set rightMotor signal to pin 13

  /*
  
  Due to placement differences, for example to go straight, the right motor moves clockwise while
  the left motor moves counterclockwise.
  
  1300 microseconds - Full speed clockwise
  1400 microseconds - Linear speed zone starts
  1500 microseconds - No motion
  1600 microseconds - Linear speed zone ends
  1700 microseconds - Full speed counter-clockwise
  
  */

  leftMotor.writeMicroseconds(1300); // Full speed c
  rightMotor.writeMicroseconds(1700);
  delay(oneCM * 165);
  
  leftMotor.writeMicroseconds(1300);  // Left wheel counterclockwise
  rightMotor.writeMicroseconds(1300); // Right wheel clockwise
  delay(oneDeg * 91);
  
  leftMotor.writeMicroseconds(1300);  // Left wheel counterclockwise
  rightMotor.writeMicroseconds(1700); // Right wheel clockwise
  delay(oneCM * 54);

  leftMotor.detach(); // Stop sending signals to leftMotor
  rightMotor.detach(); // Stop sending signals to rightMotor
}

void loop() {
}


