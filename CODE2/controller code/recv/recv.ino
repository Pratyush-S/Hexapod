#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
//int pos = 0;
void setup() {
    Serial.begin(9600);
    pinMode(A2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
 
    mySwitch.enableReceive(0); //pin2
}
void loop() {
int buffer1;
digitalWrite(A2,HIGH);
delay(100);
digitalWrite(A2,LOW);
delay(100);
digitalWrite(A2,HIGH);
delay(100);
digitalWrite(A2,LOW);
  while(1){
    
    if (mySwitch.available()) {
   // Serial.println("2");
        //int buffer1 =-1;
        buffer1 =mySwitch.getReceivedValue();
        if (buffer1 >= 0) {
          Serial.println(buffer1); 
            if (buffer1==0){Serial.println("reset");}
            else if (buffer1==1){Serial.println("up_1");}
            else if (buffer1==2){Serial.println("down_1");}
            else if (buffer1==3){Serial.println("right_1");}
            else if (buffer1==4){Serial.println("left_1");}
            else if (buffer1==5){Serial.println("dead zone");}
            else if (buffer1==6){Serial.println("up_2");digitalWrite(3,HIGH);delay(1000);digitalWrite(3,LOW);}
            else if (buffer1==7){digitalWrite(4,HIGH);delay(1000);digitalWrite(4,LOW);}
            else if (buffer1==8){digitalWrite(5,HIGH);delay(1000);digitalWrite(5,LOW);}
            else if (buffer1==9){digitalWrite(6,HIGH);delay(1000);digitalWrite(6,LOW);}
        
        }
        
     if (buffer1==0)digitalWrite(A2,HIGH);
     else digitalWrite(A2,LOW);
        
       mySwitch.resetAvailable();
      buffer1=-1;
   // delay(500);
    }

  }}
