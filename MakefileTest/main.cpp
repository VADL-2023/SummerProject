/* main.cpp file created for testing makefile linking
 * Created by Kush Hari and Andrew Noonan
 * 
 * File also used for serial port testing with VectorNav
 * Previous years used UART-USB converter, but trying to do with direct pin connections
 */

#include "driver/IMU.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "./VectorNav/include/vn/ezasyncdata.h"


int main() {
  VnSensor* myVn = new VnSensor();
  //myVn->connect("/dev/USB0", 115200);
  //myVN.connect("/dev/USB0", 115200);
  
}

double computeAltitude(double kPa) {
  double altitudeFeet = 145366.45 * (1.0 - std::pow(10.0 * kPa / 1013.25, 0.190284)); // https://en.wikipedia.org/wiki/Pressure_altitude
  return altitudeFeet;
}
