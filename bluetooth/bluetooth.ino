//JuHeMRuBr
#include <Servo.h>

const int servoPin = 9; //1
  int led =4;
  
 Servo servo;//2

 void setup(){
  
  servo.attach(servoPin); //3
  servo.write(90); //4
  Serial.begin(9600); //5
  Serial.println("Enter angle in degress"); 
  digitalWrite(led,led);
 }

void loop() { //6
  digitalWrite(led, LOW);
  
  if(Serial.available()) {
    int angle = Serial.parseInt();
    servo.write(angle); //7
    digitalWrite(led, HIGH);
  }
}
