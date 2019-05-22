void setup() {

pinMode(A0,INPUT);
pinMode(A2,INPUT);
Serial.begin(9600);

}

void loop() {
Serial.print(analogRead(A0));
Serial.print("                   ");
delay(200);
Serial.println(analogRead(A2));
delay(200);


}
