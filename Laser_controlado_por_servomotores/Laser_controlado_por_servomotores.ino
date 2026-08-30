//Mirla e Hellen
#include <Servo.h>

int laserPin = 4;
Servo servoV;
Servo servoH;

int x = 90;
int y = 90;
int minX = 10;
int maxX= 170;
int minY = 50;
int mazY = 130;

void setup() {
  // put your setup code here, to run once:
  servoH.attach(3);
  servoH.attach(2);
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char ch;
  if (Serial.available())
  {
    digitalWrite(laserPin,LOW);
  }
  else if (ch=='0')
  {
    digitalWrite(laserPin,HIGH);
  }
  else if (ch == '-')
  {
    delay(100);
  }  
  else if (ch == 'c')
  {
    x= 90;
    y = 90;
  }
  else if (ch == '1' || ch == 'r'|| ch=='u'||ch=='d')
  {
   moverLaser(ch,1);
  }
  else if (ch == 'L'|| ch == 'R'|| ch=='U'||ch=='D')
  {
   moverLaser(ch,5);
  }
 }
 servoH.write(x);
 servoV.write(y);
 delay(15);
}
void moverLaser(char dir, int amount)
{
  if((dir == 'r'||dir == 'R')&& x > minX)
  {
    x=x-amount;
  }
  else if((dir == 'l'||dir == 'L')&& x < maxX)
  {
    x=x+amount;
  }
  else if((dir == 'u'||dir == 'U')&& y < maxY)
  {
    y=y+amount;
  else if((dir == 'd'||dir == 'D')&& x > minY)
  {
    y=y-amount;
  }
  }
}
