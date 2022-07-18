#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 


void servoTest();

void imuTest();

void setup() {
  myservo.attach(4);  // attaches the servo on pin 4
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  servoTest();
  imuTest();
}

void servoTest() {
  for(pos = 10; pos < 170; pos += 1)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}

void imuTest() {
  int incomingByte;
  if(Serial1.available() > 0) {
    incomingByte = Serial1.read();
    Serial1.print("UART 1 received:");
    Serial1.println(incomingByte, DEC);
  }
  if(Serial2.available() > 0) {
    incomingByte = Serial2.read();
    Serial2.print("UART 2 received:");
    Serial2.println(incomingByte, DEC);
  }
}