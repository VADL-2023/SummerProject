#include <Arduino.h>
#include <SPI.h>
#include <VectorNav.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

VN200 IMU(10);

void servoTest();

void imuTest();

void setup() {
  myservo.attach(4);  // attaches the servo on pin 4
  SPI.setSCK(14);
  IMU.begin();
  Serial.begin(9600);
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
  double PosX, PosY, PosZ;
  float yaw, pitch, roll, VelX, VelY, VelZ, ax, ay, az, gx, gy, gz;
  IMU.getNavEcef(&yaw, &pitch, &roll, &PosX, &PosY, &PosZ, &VelX, &VelY, &VelZ, &ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("X/North Position: ");
  Serial.println(PosX);
  Serial.print("Y/East Position: ");
  Serial.println(PosY);
  Serial.print("Z/Down Position: ");
  Serial.println(PosZ);
}