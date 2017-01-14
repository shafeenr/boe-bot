/* 

Copyright (c) 2017, Shafeen Rahman & Pavit Buttar
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <Servo.h> // Preprocessor scans Servo header file

#define oneDeg 6.5 // 1 degree is around 6.5 ms
#define oneCM 60 // 1 centimetre is around 60 ms

/* 

Here we figured out approximately how much milliseconds
in delay would let our bot move approximately one degree
and one centimetre

The #define directive is used instead of declaring
variable of data type int with const keyword
because the former uses less memory in the Arduino

*/

Servo leftMotor; // Declare left motor
Servo rightMotor; // Declare right motor

void setup() {

  // License is printed via Serial communications to conform to our second clause
  
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("Copyright (c) 2017, Shafeen Rahman & Pavit Buttar");
  Serial.println("All rights reserved.");
  Serial.println("Redistribution and use in source and binary forms, with or without");
  Serial.println("modification, are permitted provided that the following conditions are met:");
  Serial.println(" ");
  Serial.println("1. Redistributions of source code must retain the above copyright notice, this");
  Serial.println("   list of conditions and the following disclaimer.");
  Serial.println("2. Redistributions in binary form must reproduce the above copyright notice,");
  Serial.println("   this list of conditions and the following disclaimer in the documentation");
  Serial.println("   and/or other materials provided with the distribution.");
  Serial.println(" ");
  Serial.println('THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND');
  Serial.println("ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED");
  Serial.println("WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE");
  Serial.println("DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR");
  Serial.println("ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES");
  Serial.println("(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;");
  Serial.println("LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND");
  Serial.println("ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
  Serial.println("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS");
  Serial.println("SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
  
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


