#include <Stepper.h>
#include <Arduino.h>
#include "BasicStepperDriver.h"
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3); // RX, TX
Servo myservo;  

int A = 0;
int B = 0;
int state = 0;
String message;
int QTY, numMessages, endBytes;
byte inByte;
int flag = 0;



#define MOTOR_STEPS 200
#define RPM 40
#define MICROSTEPS 16
#define DIR 14
#define STEP 15
int pos = 0;


BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);



void setup()
{
  numMessages, endBytes = 0;
  
  
  Serial.begin(9600);
  mySerial.begin(9600);
  myservo.attach(5); 
  myservo.write(180);
  stepper.begin(RPM, MICROSTEPS);
  delay(1000);
  
}

void loop()
{
  data();
  
  if (A > 0 && B > 0) {
    delay(1000);
    
myservo.write(70);
delay(1000);
    for (int i = 0; i < B; i++) {

 stepper.rotate(-(2.75*A));
 cut();

    }
    A=0;
    B=0;

  }
}

  void data() {
    if (state < 1) {
      if (numMessages == 1) { //Did we receive the anticipated number of messages? In this case we only want to receive 1 message.
        A = QTY;
       // Serial.println(A);//See what the important message is that the Arduino receives from the Nextion
        numMessages = 0; //Now that the entire set of data is received, reset the number of messages received
        state = 1;
      }
    }

    if (state > 0) {
      if (numMessages == 1) { //Did we receive the anticipated number of messages? In this case we only want to receive 1 message.
        B = QTY;
       // Serial.println(B);//See what the important message is that the Arduino receives from the Nextion
        numMessages = 0; //Now that the entire set of data is received, reset the number of messages received
        state = 0;
      }
    }






    if (mySerial.available()) { //Is data coming through the serial from the Nextion?
      inByte = mySerial.read();

      // Serial.println(inByte); //See the data as it comes in

      if (inByte > 47 && inByte < 58) { //Is it data that we want to use?
        message.concat(char(inByte)); //Cast the decimal number to a character and add it to the message
      }
      else if (inByte == 255) { //Is it an end byte?
        endBytes = endBytes + 1; //If so, count it as an end byte.
      }

      if (inByte == 255 && endBytes == 3) { //Is it the 3rd (aka last) end byte?
        QTY = message.toInt(); //Because we have now received the whole message, we can save it in a variable.
        message = ""; //We received the whole message, so now we can clear the variable to avoid getting mixed messages.
        endBytes = 0; //We received the whole message, we need to clear the variable so that we can identify the next message's end
        numMessages  = numMessages + 1; //We received the whole message, therefore we increment the number of messages received.

        //Now lets test if it worked by playing around with the variable.

      }
    }
  }

  void cut (){
    for (pos = 70; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(5);        
  }

  for (pos = 180; pos >= 70; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(10);                       
  }
  }
  
