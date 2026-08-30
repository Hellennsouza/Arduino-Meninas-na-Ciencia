int ledPins[7] = {6,7,8,9,10,11,12,13}
int dicePatterns[7][7] =
{
  {0,0,0,0,0,0,1},
  {0,0,1,1,0,0,0},
  {0,0,1,1,0,1,1}
  {1,0,1,1,0,1,0}
  {1,0,1,1,0,1,1}
  {1,1,1,1,1,1,0}
  {0,0,0,0,0,0,0}
};
int swithPin = 9;
int blank = 6;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i<7; i++)
  {
    pinMode (ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(switchPin, INPUT_PULLUP);
  randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:
{
  if (digitalRead (switchPin))
  {
    rollTheDice();
  }
  delay(100);
}
    
  }
}
}
