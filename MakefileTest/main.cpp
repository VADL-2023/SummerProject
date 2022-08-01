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
  int serial_port = open("/dev/ttyAMA0",O_RDWR);  //Serial ports are stored as files by pi, second argument is "open for read and write"
  if (serial_port < 0){
    printf("Error %ivadl@raspberrypi:~/SummerProject/MakefileTest $ ./a.out
Started Main
Error 20 from open: Not a directory
Error 9 from tcgetattr: Bad file descriptor
Error 9 from tcsetattr: &s
Ended Main
 from open: %s\n", errno, strerror(errno));
  }
  
  //Create new termios struct
  struct termios my_tty;
  
  // tcgetattr test -> can read termios documentation for more info
  // returns 0 if successful, sets errno and returns -1 if unsuccessful
  if(tcgetattr(serial_port, &my_tty) != 0){
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }
  
  
// -------------------------
// Control Modes
// -------------------------
    
    // Parity - Useful Explanation: electronics.stackexchange.com/questions/9108/for-uart-should-i-use-parity-on-a-board-level
    my_tty.c_cflag &= ~PARENB; //Disable parity bit
    //my_tty.c_cflag |= PARENB; // Enable parity bit
    
    
    // Num of Stop Bits
    my_tty.c_cflag &= ~CSTOPB; // Clear stop bits, 1 Stop bit default
    //my_tty.c_cflag |= CSTOPB; // 2 Stop Bits (less common)
    
    // Bits per byte
    my_tty.c_cflag &= ~CSIZE; // Clear the size bits
    my_tty.c_cflag |= CS8; // Set size bit to 8 bits per byte (can choose 5-8)
    
    
    // Flow Control
    // Handshake system where data is only sent from sensor if we say we're ready
    // implemented using the RTS / CTS pins, which we have disconnected
    my_tty.c_cflag &= ~CRTSCTS; //Disable control
    //my_tty.c_cflag |= CRTSCTS //Enable control
    
    
    // Cread and Clocal
    my_tty.c_cflag |= CREAD | CLOCAL; //CREAD allows us to read 
    
// -------------------------
// Local Modes
// -------------------------

  // Canonical Mode (process input when newline char is received)
  my_tty.c_lflag &= ~ICANON; // Disable canonical
  
  // Echo - disable all
  my_tty.c_lflag &= ~ECHO;
  my_tty.c_lflag &= ~ECHOE;
  my_tty.c_lflag &= ~ECHONL;
  
  // Signal Chars
  my_tty.c_lflag &= ~ISIG; //Signal chars not used with serial

// -------------------------
// Input Modes
// -------------------------

  // Software Flow Control
  my_tty.c_lflag &= ~(IXON | IXOFF | IXANY);
  
  // Special handling of bytes - Disabling all so we just get raw data
  my_tty.c_lflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);


// -------------------------
// Output Modes
// -------------------------

  // Prevent unwanted conversion of special chars (newline, carriage, tabs)
  my_tty.c_oflag &= ~OPOST;
  my_tty.c_oflag &= ~ONLCR;
  
// -------------------------
// Vtime && VMin
// -------------------------

  // VMin and VTime are codependent - look at documentation for selection
  // Basically determines when we stop waiting for bits after calling read()
  my_tty.c_cc[VTIME] = 10; //Wait for up to 10 deciseconds, returning as soon as any data is received
  my_tty.c_cc[VMIN] = 0;  //Note: IMU Measurement Register is 44 bytes

// -------------------------
// Baud Rate
// -------------------------

  // VN UART supports 9600 - 921600
  cfsetispeed(&my_tty, B115200);
  cfsetospeed(&my_tty, B115200);
  

// -------------------------
// Save Termios Configuration
// -------------------------

  if (tcsetattr(serial_port, TCSANOW, &my_tty) != 0){
    printf("Error %i from tcsetattr: &s\n",errno, strerror(errno));
  }

// -------------------------
// Read and Write Configuration
// -------------------------
command = "$";

// -------------------------
// Close Serial
// -------------------------
  
  std::cout << "Ended Main" << std::endl;
  return 0;
}

