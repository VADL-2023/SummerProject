#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  SerialTest.py
#  
#  Copyright 2022  <pi@sift1>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  
import serial
import string as str
from time import sleep
from time import sleep

def main(args):
    print("Hello World")
    ser = serial.Serial("/dev/ttyAMA0",115200) #Open Port with Baud Rate
    command = "$VNWRG,06,19*XX\r\n" #Quaternion cmd
    #command = "$VNWRG,06,02*XX\r\n" #Quaternion cmd
    command_as_bytes = command.encode()
    print(type(command_as_bytes))
#   my_decoded_command = command_as_bytes.decode()
#  print(type(my_decoded_command))
    
    ser.write(command_as_bytes)
    while True:
        received_data = ser.read()
        print("Received the Data")
        sleep(0.5)
        data_left = ser.inWaiting()
        received_data += ser.read(data_left)
        print(received_data)
        print("Received the Data")
    return 0
    
if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
 