
#define pinoled 3
#define sensor 2
bool rele,n;
int i;
unsigned long tempoZero,delae;
void setup() {
  
  pinMode(pinoled, OUTPUT);
  pinMode(sensor, INPUT);
  rele= false;
  digitalWrite(pinoled,rele);
  i=0;
}

void loop() {
tempoZero= millis();
  delay(30);
  if (digitalRead(sensor)==true){
    i+=1;
  }
  if (i==2){
    rele=!rele;
    i=0;
    }
  if (millis()-tempoZero>250){
    i=0;
    }
  digitalWrite(pinoled,rele);  
}
