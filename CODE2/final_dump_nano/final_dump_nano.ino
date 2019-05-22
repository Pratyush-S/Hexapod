#include <RCSwitch.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

RCSwitch mySwitch = RCSwitch();
//int pos = 0;
void setup() {
    Serial.begin(9600);
    pinMode(A2,OUTPUT);
    mySwitch.enableReceive(0); //pin2
}
void loop() {
//  int buffer1=mySwitch.getReceivedValue()==1;
  
    if (mySwitch.available()) {
        int buffer1 = mySwitch.getReceivedValue();
        if (buffer1 >= 0) { 
            if (buffer1==100){Serial.println("reset");}
            else if (buffer1==1){Serial.println("up_1");}
            else if (buffer1==2){Serial.println("down_1");}
            else if (buffer1==3){Serial.println("right_1");}
            else if (buffer1==4){Serial.println("left_1");}
            else if (buffer1==5){Serial.println("dead zone");}
            else if (buffer1==6){Serial.println("up_2");}
            else if (buffer1==7){Serial.println("down_2");}
            else if (buffer1==8){Serial.println("right_2");}
            else if (buffer1==9){Serial.println("left_2");}
        
        }
     if (buffer1==100)digitalWrite(A2,HIGH);
     else digitalWrite(A2,LOW);
        mySwitch.resetAvailable();
      buffer1=-1;
    delay(200);
    }
}
