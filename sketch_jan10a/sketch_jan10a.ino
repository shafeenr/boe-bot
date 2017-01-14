#include <Servo.h> // Preprocessor scans Servo header file

/* 

Here we figured out approximately how much milliseconds in delay 
would let our bot move approximately one degree and one centimetre

The #define directive is used instead of
declaring variable of data type int with const
keyword because the former uses less memory

*/

#define oneDeg 6.5 // 1 degree is around 6.5 ms
#define oneCM 60 // 1 centimetre is around 60 ms

Servo leftMotor; // Declare left motor
Servo rightMotor; // Declare right motor

void setup() {

  leftMotor.attach(13); // Broadcast left motor's signal to pin 13
  rightMotor.attach(12); // Broadcast right motor's signal to pin 12

  /*
  
  Due to placement differences, for example to go straight, the right motor moves clockwise while
  the left motor moves counterclockwise.
  
  1300 microseconds - Full speed clockwise
  1400 microseconds - Linear speed zone starts
  1500 microseconds - No motion
  1600 microseconds - Linear speed zone ends
  1700 microseconds - Full speed counter-clockwise
  
  */

  // Travel 165 centimetres straight forward
  
  leftMotor.writeMicroseconds(1300); // Left wheel full speed counter-clockwise
  rightMotor.writeMicroseconds(1700); // Right wheel full speed clockwise
  delay(oneCM * 165);
  
  // Turn left in place
  
  leftMotor.writeMicroseconds(1300);  // Left wheel full speed counter-clockwise
  rightMotor.writeMicroseconds(1300); // Right wheel full speed counter-clockwise
  delay(oneDeg * 91); // Set for 91 degrees as a little tweak to turn harder
  
  // Travel 54 centimetres straight forward
  
  leftMotor.writeMicroseconds(1300);  // Left wheel full speed clockwise
  rightMotor.writeMicroseconds(1700); // Right wheel full speed counter-clockwise
  delay(oneCM * 54);

  leftMotor.detach(); // Stop broadcast of signals to left motor
  rightMotor.detach(); // Stop broadcast of signals to right motor
}

void loop() {
}


