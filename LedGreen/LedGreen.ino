//Exercicio
//
#include <SoftwareSerial.h>

#define TX 10
#define RX 11
SoftwareSerial mySerial(RX, TX);

const int ledPin = 12;
const int ledGreen = 13;
int state = 0;
int flag = 0;
int bluna = 0;
int hellen = 0;

void setup() {
  
  pinMode(ledGreen, OUTPUT); //
  pinMode(ledPin, OUTPUT); //
  mySerial.begin(9600);
} 

void loop() {
  if(mySerial.available() > 0){
    state = mySerial.read();
    flag = 0;
    state = mySerial.read();
    flag = 0;
  }
  if (state == '0'){
    digitalWrite(ledPin, LOW);
    if(flag == 0){
      mySerial.println("LED desligado");
      flag = 1;
    }
  }
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    if(flag == 0) {
      mySerial.println("LED ligado");
      flag = 1;
    }
  }
  else if (state == '2'){
    digitalWrite(ledGreen, LOW);
    if(flag == 0){
      mySerial.println("LEDGREEN desligado");
      flag = 1;
    }
  }
  else if (state == '3') {
    digitalWrite(ledGreen, HIGH);
    if(flag == 0) {
      mySerial.println("LEDGREEN ligado");
      flag = 1;
    }
  }
}  
