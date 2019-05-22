#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int val = 0;
int val2 = 0;
int x=0;
int y=0;
int pos;
int buttonPin_1 = 3; int buttonPin_2= 5;//SW of controller 1&2 respectively
int buttonState_1 =0;
int buttonState_2= 0;
void setup() {
  Serial.begin(9600);

  pinMode(buttonPin_1, INPUT_PULLUP); 
  pinMode(buttonPin_2, INPUT_PULLUP); 
  mySwitch.enableTransmit(10);
}

void loop() {

   
   
 val = analogRead(0);//x of controller 1
   val2 = analogRead(1);//y of controller 1
   x = analogRead(3);//x of controller 2
    y = analogRead(2);//y of controller 2
 buttonState_1=digitalRead(buttonPin_1);
 buttonState_2=digitalRead(buttonPin_2);
 // Serial.println(val); 
  //Serial.println(val2);
   Serial.println(x);
 Serial.println(y); 
 delay(500);
 Serial.println(buttonState_1); 
 Serial.println(buttonState_2);  
 

 if((buttonState_1 == 0) && (buttonState_2 == 0))
  {
    pos=0;
    Serial.println("reset");
  }
  
  else if((buttonState_1 == 1) && (buttonState_2 == 1) && (x==524) && (y>=520))
  {
    if((val<=1023)&& (val>517) && (val2=505))
    {
  Serial.println("up_1");
  pos=1; 
    delay(500);
    }
   else if((val>=0)&& (val<517) && (val2=505))
    {
  Serial.println("down_1"); 
  pos=2;
    delay(500);
    }
    else if((val=517) && (val2>506) && (val2<=1023))
    {
  Serial.println("right_1"); 
  pos=3;
    delay(500);
    }
    else if((val=517)&& (val2>=0) && (val2<505))
    {
  Serial.println("left_1"); 
  pos=4;
    delay(500);
    }
   
  }
  
   else if ((buttonState_1 == 1) && (buttonState_2 == 1) && (val==517) && (val2==505))
   {
      if((x<=1023)&& (x>524) && (y=520))
    {
  Serial.println("up_2");
  pos=6; 
    delay(500);
    }

    else if((x==524) && (y>520) &&(y<=1023)&& (val==517) && (val2==505))
    {
  Serial.println("right_2"); 
  pos=8;
    delay(500);
    }
   else if((x>=0)&& (x<524) && (y==520)&& (val==517) && (val2==505))
    {
  Serial.println("down_2"); 
  pos=7;
    delay(500);
    }
    else if((x>=524)&& (y>=0) && (y<520))
    {
  Serial.println("left_2"); 
  pos=9;
    delay(500);
    }
   }
   mySwitch.send(pos, 23);
}
