

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
//     Serial.print("in");
  if (mySwitch.available()) {
    
    Serial.print("Received   ");
    Serial.println( mySwitch.getReceivedValue() );

    mySwitch.resetAvailable();
  }
}
