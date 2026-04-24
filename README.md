# Derby-Car-Timer
Timer for a 3 lane Derby Car Track 

Using 3 Arduino Nanos, one for each lane.  
Lane 1 used as main for buttons, wiring all buttons to all controllers, jumping from Lane 1 controller 
Using photoelectric switches as the stop button at finish line  
Mount stop line switches to underside of track or build a finish line tower and mount everything inside there.  
~30ft track, running CAT-6 using 6/8 wires from controller and LCD bundle up to Start and Reset button at Start Line  

  
Wiring from LCD Display to Arduino Nano   
LCD | ARD  | Color  
  
GND | GRND | BLACK  
VDD | 5V   | RED  
VO  | SKIP  
RS  | D12  | BLACK  
RW  | 5V   | WHITE  
E   | D11  | BLUE  
D0  | SKIP  
D1  | SKIP  
D2  | SKIP  
D3  | SKIP   
D4  | D10  | WHITE  
D5  | D09  | YELLOW  
D6  | D08  | BLUE  
D7  | D07  | WHITE  
BLA | SKIP  
BLK | 5V   | BLACK  

Control Functions  
DPin 3 Start (Button or Microswtich)  
DPin 4 Stop and Hold Time (Photoelectric Switches)  
DPin 5 Reset (Button)
