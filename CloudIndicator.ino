/*
  Sun Light Pointer. To learn more about this project, read the readME.adoc
*/
//Header
#import <Servo.h>
//Define
Servo servo1;
const int PhotoPin = A0;
const int servoPin = 11;
//Variables
int PhotoVal;
int servoAng;
int pos;
int dT = 50;
//Functions

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  servo1.attach(servoPin);
  pinMode(PhotoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  PhotoVal = analogRead(PhotoPin);
  int movePos = 180./974.*(PhotoVal-32);
  servo1.write(movePos);
  servoAng = servo1.read();
  Serial.println(servoAng);
  delay(dT);

}
