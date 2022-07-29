/* main.cpp file created for testing makefile linking
 * Created by Kush Hari and Andrew Noonan
 * 
 * File also used for serial port testing with VectorNav
 * Previous years used UART-USB converter, but trying to do with direct pin connections
 */

#include "driver/IMU.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

// Linux Headers
#include <fcntl.h> // File control (allows us to call 'open')
#include <errno.h> // Used for error reporting - errno value changes depending on different errors
#include <termios.h> // Struct used to configure serial port - most low-level thing we do
#include <unistd.h>

int main() {
  std::cout << "Started Main" << std::endl;
 
  
// -------------------------
// Initial Serial Port Tests
// -------------------------

  // check options by using 'ls -l /dev/t*' in terminal
  int serial_port = open("/dev/ttyAMA0",9600);  //Serial ports are stored as files by pi
  if (serial_port < 0){
    printf("Error %i from open: %s", errno, strerror(errno));
  }
  
  //Create new termios struct
  struct termios my_tty;
  
  // tcgetattr test -> can read termios documentation for more info
  // returns 0 if successful, sets errno and returns -1 if unsuccessful
  if(tcgetattr(serial_port, &my_tty) != 0){
      printf("Error %i from tcgetattr: %s", errno, strerror(errno));
  }
  
  
// -------------------------
// Control Modes
// -------------------------
    
    // Parity
    
    // Num of Stop Bits
    
    // Bits per byte
    
    // Flow Control
    // Handshake system where data is only sent from sensor if we say we're ready
    // implemented using the RTS / CTS pins, which we have disconnected
    
    // Cread and Clocal
    
// -------------------------
// Local Modes
// -------------------------

  // Canonical Mode
  
  // Echo
  
  // Signal Chars

// -------------------------
// Input Modes
// -------------------------

  // Software Flow Control
  
  // Special handling of bytes


// -------------------------
// Output Modes
// -------------------------

  // Prevent unwanted conversion of special chars (newline, carriage, tabs)
  
// -------------------------
// Vtime && VMin
// -------------------------

  // VMin and VTime are codependent - look at documentation for selection

// -------------------------
// Baud Rate
// -------------------------

  

// -------------------------
// Save Termios Configuration
// -------------------------

// -------------------------
// Read and Write Configuration
// -------------------------

// -------------------------
// Close Serial
// -------------------------
  
  std::cout << "Ended Main" << std::endl;
  return 0;
}
