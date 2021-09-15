# DIY-Arduino-based-Heat-shrink-Tube-cutting-Machine-Arduino-project

![GK](https://user-images.githubusercontent.com/19898602/133376619-ee9fae01-b1a0-44e2-bd58-b84dc4229ec8.png)




  

Hey guys this time I have made a heat shrink tube cutting machine, heat shrinks are frequently needed in small length, 

manually cutting them is to boring job so I build this mini machine it can cut heat shrink from 2mm to 8mm in any length and quantity, 

user just have to insert data from HMI and need to press start so this machine automatically start cutting heat shrink tube.

In this machine first user will feed the heat shrinkk tube in between two slider rollers.

Then user have to provide some data using HMI like length of Heat shrink and quantity of heat shrink tube.




## COMPONENT USED

1. Custom PCB 
2. Arduino Nano
3. A4988 Stepper driver
4. High torque stepper motor
5. Nema 17 stepper motor 
6. some ball joint rod
7. 8mm smooth rod
8. SC8UU linear bearing
9. Nextion HMI



# CIRCUID DRAWING 

Making such projects without PCB is night mare yes trust me
you cannot get wanted result and professional touch in your project if you ignore PCB
So some days back I have developed my Multipurpose PCB.
This PCB is used to build wide range of arduino projects 

![Schematic_Multipurpose pcb_2021-09-15](https://user-images.githubusercontent.com/19898602/133383877-24044b9a-8d05-445a-808f-b6960dbe0e07.png)


followings are the some features of PCB

1. Wide range of power input 9V to 24V DC
2. Cross polarity protection
3. DC motor voltage selection 9V or 12 V DC
4. Servo motor voltage selection 5V or 9V DC
5. Manual microstepping setting for stepper motor
6. Power indication LED
7. L298N IC for heavier DC motor
8. ON board 5V and 9V regulator no need to arrange different power sources
9. Header pins and screw terminals for easy connections

List of the Components you can connect to the PCB

1. 2 DC motor ( 9V to 24V DC)
2. 2 Potentiometer
3. 2 Servo motors ( 5V to 9V DC)
4. 1 Serial device (BT module, HMI, Communication module, RX, TX)
5. 1 Encoder (2 interrupt pin & 1 PB pin)
6. 1 I2C device (SCL/SDA Device, display, MPU6050 etc)
7. 2 Stepper motors 


![MVI_0001 00_06_45_21 Still003](https://user-images.githubusercontent.com/19898602/133377296-ba24f45e-dcf4-4f97-9aa5-77aaed90175a.jpg)
![MVI_0001 00_07_21_22 Still004](https://user-images.githubusercontent.com/19898602/133377355-12dca9e1-068f-4cf5-ae58-84663ff57dde.jpg)

I have design circuit and PCB in [easyEDA](https://easyeda.com/) and ordered PCB from [JLCPCB](https://jlcpcb.com/IAT )

This is the link of [PCB editabl file](https://oshwlab.com/sharmaz747/multipurpose-pcb)

If you seriously need quality PCB quickly in your hand then you must have to try [JLCPCB](https://jlcpcb.com/IAT ) PCB manufacturing service.
They have Special offer of $2 for 1-4 Layer PCBs, free SMT assembly monthly.
If you get yourself registered today at [JLCPCB](https://jlcpcb.com/IAT ) you get 18$ welcome coupon from [JLCPCB](https://jlcpcb.com/IAT ).









