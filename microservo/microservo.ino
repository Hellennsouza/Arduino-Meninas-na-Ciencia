// Programa : Controle de servo pelo Android utilizando Bluetooth  
// Autor : Arduino e Cia  
//CoAutora: Hellen
   
#include <Servo.h>  
   
Servo myservo;  
   
int val;  
   
void setup()  
{  
  //Pino de dados do servo ligado na porta 4  
  myservo.attach(4);  
  Serial.begin(9600);  
}  
    
void loop()  
{  
   if(Serial.available()>=2)  
   {  
     int key=Serial.read();  
     int val=Serial.read();  
     myservo.write(val);  
   }  
}
