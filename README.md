# Lab 10 Power

**Authors:** Kirra & Muteeb

## Measurements

### Activity 1 Sleep

Used a 1k resistor with green LED. Set the power supply to 5V (limited amps to 0.7, 3.3V also worked) and got blinking functionality from
the board. Set up board as follows: power connected to VSYS and Output pin set to GP1 on the board.

0.01862A = 18.62mA measured on the board with 5V input to VSYS.
Power = V*I = 5*18.62mA = 93.1mW

### Activity 2 Thread

0.02152A = 21.52mA measured on the board with 5V input to VSYS.
Power = V*I = 5*21.52mA = 107.60mW

### Activity 3 Busy Loop

0.00753A = 7.53mA measured on the board with 5V input to VSYS.
Power = V*I = 5*7.53mA = 37.65mW

### Activity Sleep Alarm

**High Power**
0.01767A = 17.67mA measured on the board with 5V input to VSYS.
Power = V*I = 5*17.67mA = 88.35 mW

**Low Power**
0.00133A = 1.33mA measured on the board with 5V input to VSYS.
Power = V*I = 5*1.33mA = 6.65 mW

### Activity Dormant GPIO

**High Power**
0.01788A = 17.88mA measured on the board with 5V input to VSYS.
Power = V*I = 5*17.88mA = 89.4 mW

**Low Power**
0.00088A = 0.88mA measured on the board with 5V input to VSYS.
Power = V*I = 5*0.88mA = 4.4 mW
