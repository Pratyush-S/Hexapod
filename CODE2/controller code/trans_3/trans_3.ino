#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int x1 = 0;
int y1 = 0;
int x=0;
int y=0;
int pos;
int time1=500;
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

   
   
 x1 = analogRead(0);//x of controller 1
   y1 = analogRead(1);//y of controller 1
   x = analogRead(3);//x of controller 2
    y = analogRead(2);//y of controller 2
 buttonState_1=digitalRead(buttonPin_1);
 buttonState_2=digitalRead(buttonPin_2);
  //Serial.println(x1); 
 //Serial.println(y1);
   //Serial.println(x);
 //Serial.println(y); 
 //delay(500);
 //Serial.println(buttonState_1); 
 //Serial.println(buttonState_2);  
 

 if((buttonState_1 == 0)||(buttonState_2 == 0))
  {
    pos=0;
    Serial.println("reset");
  }
  

  ////////////////////////////////////////////////////////////////////////////////////////////left
   else if ((buttonState_1 == 1) && (buttonState_2 == 1) )
   {
      if(x>700)
    {
  Serial.println("up_2");
  pos=6; 
    delay(time1);
    }

 else if(x<300)
    {
  Serial.println("down_2"); 
  pos=7;
    delay(time1);
    }

    else if(y>700)
    {
  Serial.println("right_2"); 
  pos=8;
    delay(time1);
    }
   
    else if(y<300)
    {
  Serial.println("left_2"); 
  pos=9;
    delay(time1);
    }
   

///////////////////////////////////////////////////////////////////////////////////////right
  //else if ((buttonState_1 == 1) && (buttonState_2 == 1) )
   
      if(x1>700)
    {
  Serial.println("up_1");
  pos=1; 
    delay(time1);
    }

    else if(y1>700)
    {
  Serial.println("right_1"); 
  pos=3;
    delay(time1);
    }
    else if(x1<300)
    {
  Serial.println("down_1"); 
  pos=2;
    delay(time1);
    }
    else if(y1<300)
    {
  Serial.println("left_1"); 
  pos=4;
    delay(time1);
    }
   }

   

   Serial.println(pos);
   mySwitch.send(pos, 24);
//delay(100);
pos=-1;
mySwitch.send(pos, 24);
//delay(100);
}
