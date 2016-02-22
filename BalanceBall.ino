#include <Servo.h>

String val; //recieved value
Servo xServo;
Servo yServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xServo.attach(9);
  yServo.attach(10);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) 
   { // If data is available to read,
      val = Serial.read(); // read it and store it in val
     
   }
   if (val != "") {
    String myString = val;
    int commaIndex = myString.indexOf(',');
    String firstValue = myString.substring(0, commaIndex);
    String secondValue = myString.substring(commaIndex+1);
    float bluestX = firstValue.toFloat();
    float bluestY = secondValue.toFloat();
    xServo.write(bluestX*180);
    yServo.write(bluestY*180);
    digitalWrite(13,HIGH);
   }
   else {
    digitalWrite(13,LOW);
   }
    Serial.println("Val is " + val);
   delay(50);
}
