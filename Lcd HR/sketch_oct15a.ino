#include<LiquidCrystal.h>//inclui a biblioteca LCD
LiquidCrystal lcd(13,12,4,3,2,1);
int tempo;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("RUTH");
  lcd.setCursor(0,1);
  lcd.print("HELLEN");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(13,1);
  lcd.print(tempo);
  delay(1000);
  tempo++;
  if(tempo==300){
    tempo = 0;
  }
}
