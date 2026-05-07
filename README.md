# Derby-Car-Timer  
Using I2C 16,2 LCDs
Timer for a 3 Lane Derby Car Track 

Using 1 Arduino Nano for all functions.  
Using photoelectric switches as the stop button at finish line  
Mount stop line switches to underside of track or build a finish line tower and mount everything inside there.  
~30ft track, running CAT-6 using 6/8 wires from controller and LCD bundle up to Start and Reset button at Start Line  

Parts List  
1 x Arduino Nano  
3 x LCD Display  
3 x Photoelectric Switch  
1 x Button for Start  
1 x Button for Reset  
1 x Derby Car Track
  
Wiring from LCD Display to Arduino Nano   
LCD | ARD  | Color  
  
GND | GRND | BLACK  
VCC | 5V   | RED  
SDA | A4   | WHITE  
SCL  | A5  | YELLOW  


Control Functions  
DPin 2 Start (Button or Microswitch)  
DPin 3 Stop and Hold Time for Lane 1 (Photoelectric Switches)  
DPin 4 top and Hold Time for Lane 2 (Photoelectric Switches)  
DPin 5 Stop and Hold Time for Lane 3 (Photoelectric Switches)  
DPin 6 Reset (Button)
