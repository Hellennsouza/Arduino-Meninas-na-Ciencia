#include <NewPing.h>        //Chama a biblioteca NewPing 
#define TRIGGER_PIN  8    //Define a porta 5 como TRIGGER_PIN  
#define ECHO_PIN     13      //Define a porta 8 como ECHO_PIN 
#define MAX_DISTANCE 200   //Define a máxima distância como 200cm 
#define buz 12                     //Define a porta 12 como buz 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Função recebe dados do sensor e retorna a distância
void setup() {    
pinMode(buz,OUTPUT);    // Define a porta buz como saída   
} 
void loop(){                      
  if ((sonar.ping_cm() > 0) and (sonar.ping_cm() <= 15)){ // Se a distância for menor que 10cm então chama a função som com parâmetro 1 
           som(1);   
}
  if ((sonar.ping_cm() > 15) and (sonar.ping_cm() <= 50)){ // Se a distância for maior que 10cm e menor que 50cm então chama a função som com parâmetro 4
som(4);   
}
 } 
void som(int x){ // Função do efeito sonoro que recebe o tempo    
  int i;
  for (i=0;i<80;i++){
  digitalWrite(buz,HIGH);
         delay(x); 
  digitalWrite(buz,LOW);
delay(x);
} 
delay(50);
     for (i=0;i<100;i++){
digitalWrite(buz,HIGH);
delay(x);
digitalWrite(buz,LOW);
delay(x);
}
}
