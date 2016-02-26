#include <Servo.h>

Servo xServo;
Servo yServo;
char inData[1000]; // Allocate some space for the string
byte index = 0; // Index into array; where to store the character
char inChar=-1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xServo.attach(9);
  yServo.attach(10);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0) // Don't read unless
   // there you know there is data
 {
   if(index < 19) // One less than the size of the array
   {
     inChar = Serial.read(); // Read a character
     inData[index] = inChar; // Store it
     index++; // Increment where to write next
     inData[index] = '\0'; // Null terminate the string
   }
 }
 index = 0;
 String val(inData);
    String myString = val;
    int commaIndex = myString.indexOf(',');
    String firstValue = myString.substring(0, commaIndex);
    String secondValue = myString.substring(commaIndex+1);
    int bluestX = firstValue.toInt();
    int bluestY = secondValue.toInt();
    xServo.write(bluestX);
    yServo.write(bluestY);
    digitalWrite(13,HIGH);
   delay(50);
}
