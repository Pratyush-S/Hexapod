

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  mySwitch.enableTransmit(10);
  
  
}

void loop() {

  mySwitch.send(6);
  Serial.println("Sending 6");
  delay(4000);  
  mySwitch.send(9);
    Serial.println("Sending 9");
  delay(4000);


}
