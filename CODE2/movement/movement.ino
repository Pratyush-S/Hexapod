
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


RCSwitch mySwitch = RCSwitch();

int lower_limit=300;
int wait=20;
int t=0;
int t2=200;
int step_size=5;
int pos = 0;
int upper_limit=200;
int tip_limit=400 ;
int mid=317;
int m=290;
int n=340;


/////////////////////////////////////////////////////////////////////////////////////
int limit_f_1=n;
int limit_b_1 =m;

int limit_f_2=n;
int limit_b_2=m;

int limit_f_3=n;
int limit_b_3 =m;



int limit_f_6=m;
int limit_b_6=n;

int limit_f_5=m;
int limit_b_5 =n;

int limit_f_4=m;
int limit_b_4=n;

///////////////////////////////////////////////////////////////////////////  //position varible
int motor[6][2];  


///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void reset();
void reset_array();
void walk();
void tip_set();
void forward();
void back();
void left();
void right();
void up();
void down();
void rotate_right();
void rotate_left();


void leg2up();
void leg2fwd();
void leg2dwn();
void leg2bck();

void leg1up();
void leg1fwd();
void leg1dwn();
void leg1bck();


void leg3up();
void leg3fwd();
void leg3dwn();
void leg3bck();

void leg4up();
void leg4fwd();
void leg4dwn();
void leg4bck();

void leg5up();
void leg5fwd();
void leg5dwn();
void leg5bck();


void leg6up();
void leg6fwd();
void leg6dwn();
void leg6bck();


void leg1tip();
void leg2tip();
void leg3tip();
void leg4tip();
void leg5tip();
void leg6tip();




Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(&Wire, 0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(&Wire, 0x41);

/////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);
// mySwitch.enableReceive(0); //pin2 
  pwm1.begin();  
  pwm1.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm2.begin(); 
  pwm2.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
//pinMode(7,OUTPUT);

  pinMode(3,OUTPUT);  
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
 
    mySwitch.enableReceive(0); //pin2

  delay(10);
}
//////////////////////////////////////////////////////////////////////////////////////////////

void loop(){
 
while(1)
{  
 reset();
  delay(2000);
rotate_left();
rotate_left();
rotate_left();
rotate_left();
rotate_left();

//  reset();
  delay(2000);
  
rotate_right();
rotate_right();
rotate_right();
rotate_right();
rotate_right();

  //reset();
  delay(2000);
  
forward();
forward();
forward();
forward();
forward();

  //reset();
  delay(2000);

  back();
  back();
  back();
    back();
      back();
  delay(2000);
 while(1); 
  }
  
while(1)
{  
 reset();
  delay(2000);
rotate_left();
rotate_left();
rotate_left();
rotate_left();
rotate_left();

//  reset();
  delay(2000);
  
rotate_right();
rotate_right();
rotate_right();
rotate_right();
rotate_right();

  //reset();
  delay(2000);
  
forward();
forward();
forward();
forward();
forward();

  //reset();
  delay(2000);

  back();
  back();
  back();
    back();
      back();
  delay(20000);


  }

//////////////////////////////////////////////

 while(0){
    int buffer1;
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
 }


  }


/////////////////////////////////////////////////////////////////            1 012
void leg1up(){
pwm2.setPWM(1, 0,upper_limit);
delay(t);
}


void leg1fwd(){ //380
    pwm2.setPWM(2, 0,limit_f_1);
delay(t);
}

void leg1dwn(){ //255
  pwm2.setPWM(1, 0,lower_limit);
delay(t);
} 

void leg1bck(){
pwm2.setPWM(2,0,limit_b_1);
delay(t);
}

  
void leg1tip(){
pwm2.setPWM(11, 0,tip_limit);
delay(t);  
}
//////////////////////////////////////////////////             2 456
void leg2up(){
  pwm2.setPWM(5, 0,upper_limit);
delay(t);
}
void leg2fwd(){
pwm2.setPWM(6, 0,limit_f_2);
delay(t);
}
void leg2dwn(){
  pwm2.setPWM(5, 0,lower_limit);
delay(t);
}
void leg2bck(){
pwm2.setPWM(6, 0,limit_b_2);
delay(t);
}


void leg2tip(){
pwm2.setPWM(4, 0,tip_limit);
delay(t);  
}

/////////////////////////////////////////////////////////////////            3: 8910
void leg3up(){
  pwm2.setPWM(9, 0,upper_limit);
delay(t);
}
void leg3fwd(){
  pwm2.setPWM(8, 0,limit_f_3);
delay(t);
}
void leg3dwn(){
  pwm2.setPWM(9, 0,lower_limit);
delay(t);
}
void leg3bck(){
pwm2.setPWM(8, 0,limit_b_3);
delay(t);
}


void leg3tip(){
pwm2.setPWM(10, 0,tip_limit);
delay(t);  
}


//////////////////////////////////////////////////             4:  257
void leg4up(){
  pwm1.setPWM(7, 0,upper_limit);
delay(t);
}
void leg4fwd(){
  pwm1.setPWM(5, 0,limit_f_4);
delay(t);
}
void leg4dwn(){
  pwm1.setPWM(7, 0,lower_limit);
delay(t);
}
void leg4bck(){
pwm1.setPWM(5, 0,limit_b_4);
delay(t);
}


void leg4tip(){
pwm1.setPWM(2, 0,tip_limit);
delay(t);  
}

/////////////////////////////////////////////////////////////////            5  :8910   9108
void leg5up(){
  pwm1.setPWM(9, 0,upper_limit);
delay(t);
}
void leg5fwd(){
  pwm1.setPWM(10, 0,limit_f_5);
delay(t);
}
void leg5dwn(){
  pwm1.setPWM(9, 0,lower_limit);
delay(t);
}
void leg5bck(){
pwm1.setPWM(10, 0,limit_b_5);
delay(t);
}


void leg5tip(){
pwm1.setPWM(8, 0,tip_limit);
delay(t);  
}
/////////////////////////////////////////////////////////////////            6  121315
void leg6up(){
  
  pwm1.setPWM(13, 0,upper_limit);
delay(t);
}
void leg6fwd(){
  pwm1.setPWM(12, 0,limit_f_6);
delay(t);
}
void leg6dwn(){
  pwm1.setPWM(13, 0,lower_limit);
delay(t);
}
void leg6bck(){
pwm1.setPWM(12, 0,limit_b_6);
delay(t);
}

void leg6tip(){
pwm1.setPWM(15, 0,tip_limit);
delay(t);  
}



////////////////////////////////////////////////////////////////////////////     RESET
void reset(){
  int x=320,i,j;
for(i=1;i<16;i++){
//   for(j=1;j<4;j++){

    pwm1.setPWM(i,0,x);
    pwm2.setPWM(i,0,x);
//pwm1.setPWM(motor[i][j].value, 0, motor[i][j].value);
//pwm2.setPWM(motor[i][j].value, 0, motor[i][j].value);
    }   
  }

  
////////////////////////////////////////////////////////////////////////////     reset_array

void reset_array(){
motor[1][1]=317;
motor[1][2]=317;
motor[1][3]=317;
motor[2][1]=317;
motor[2][2]=317;
motor[2][3]=317;
motor[3][1]=317;
motor[3][2]=317;
motor[3][3]=317;
motor[4][1]=317;
motor[4][2]=317;
motor[4][3]=317;
motor[5][1]=317;
motor[5][2]=317;
motor[5][3]=317;
motor[6][1]=317;
motor[6][2]=317;
motor[6][3]=317;


    
    }
  //////////////////////////////////////////////////////////////////////////////////////   Tip set

void tip_set(){
leg1tip();
leg2tip();
leg3tip();
leg4tip();
leg5tip();
leg6tip();  
}

  //////////////////////////////////////////////////////////////////////////////////////   walk mode
void walk(){
reset();
delay(1000);

pwm2.setPWM(10, 0, tip_limit);
pwm2.setPWM(15, 0, tip_limit);
pwm2.setPWM(2, 0, tip_limit);  //1

pwm1.setPWM(7, 0, tip_limit);
pwm1.setPWM(14, 0,tip_limit);
pwm1.setPWM(10, 0, tip_limit);
delay(500);

tip_limit=400;
pwm2.setPWM(10, 0, tip_limit);
pwm2.setPWM(15, 0, tip_limit);
pwm2.setPWM(2, 0, tip_limit);  //1

pwm1.setPWM(7, 0, tip_limit);
pwm1.setPWM(14, 0,tip_limit);
pwm1.setPWM(10, 0, tip_limit);
delay(500);

  }

  //////////////////////////////////////////////////////////////////////////////////////    forward step

void forward(){

delay(t2); 
leg1up();
leg3up();
leg5up();

delay(t2);
leg1fwd();
leg3fwd();
leg5fwd();

leg2bck();
leg4bck();
leg6bck();

delay(t2);

leg1dwn();
leg3dwn();
leg5dwn();
delay(t2);

leg2up();
leg4up();
leg6up();

delay(t2);

leg1bck();
leg3bck();
leg5bck();

leg2fwd();
leg4fwd();
leg6fwd();

delay(t2);

leg2dwn();
leg4dwn();
leg6dwn();
  
}
    //////////////////////////////////////////////////////////////////////////////////////    back step

void back(){

  
delay(t2); 
leg1up();
leg3up();
leg5up();

delay(t2);
leg1bck();
leg3bck();
leg5bck();

leg2fwd();
leg4fwd();
leg6fwd();

delay(t2);

leg1dwn();
leg3dwn();
leg5dwn();
delay(t2);

leg2up();
leg4up();
leg6up();

delay(t2);

leg1fwd();
leg3fwd();
leg5fwd();

leg2bck();
leg4bck();
leg6bck();

delay(t2);

leg2dwn();
leg4dwn();
leg6dwn();

}
 //////////////////////////////////////////////////////////////////////////////////////    roatete RIGHT

void rotate_right(){
   leg1up();
  leg3up();
  leg5up();

delay(t2);
  leg1bck();
  leg3bck();
  leg5fwd();

  leg2fwd();
  leg4bck();
  leg6bck();

delay(t2);
leg1dwn();
leg3dwn();
leg5dwn();

delay(t2);
  leg2up();
  leg4up();
  leg6up();

 delay(t2);
leg6fwd();
leg4fwd();
leg2bck();//2

leg1bck();
leg3bck();
leg5fwd();
delay(t2);
leg2dwn();
leg4dwn();
leg6dwn();
delay(t2);
 
}

  //////////////////////////////////////////////////////////////////////////////////////    roatete LEFT

void rotate_left(){
  leg1up();
  leg3up();
  leg5up();

delay(t2);
  leg1fwd();
  leg3fwd();
  leg5bck();

  leg2bck();
  leg4fwd();
  leg6fwd();

delay(t2);
leg1dwn();
leg3dwn();
leg5dwn();

delay(t2);
  leg2up();
  leg4up();
  leg6up();

 delay(t2);
leg6bck();
leg4bck();
leg2fwd();//2

leg1fwd();
leg3bck();
leg5bck();
delay(t2);
leg2dwn();
leg4dwn();
leg6dwn();
delay(t2);
  

}





