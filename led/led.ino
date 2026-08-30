 //Cria um array para os pinos dos Leds
byte Pinosled[]={6,7,8,9,10,11,12,13};

int ledDelay; // Intervalo entre as alterações

int direcao = 1; // Direcao do "movimento"

int ledatual = 0;


unsigned long changeTime;

//Pino analogico 2 definido como entrada para o potenciometro
int potPin = A2;

void setup()
{
  
  Serial.begin(9600); // Inicializa a comunicacao serial
  for (int x=0; x<10; x++) // Loop que define todos os pinos como saída
  {
    pinMode(Pinosled[x],OUTPUT);
  }
  changeTime=millis();
 pinMode(potPin,INPUT);
}

void loop()

{
  // Varia o valor de ledDelay conforme o valor do potenciometro,
  // alterando a velocidade do efeito
  ledDelay = analogRead(potPin);

  // Escreve o valor de leitura do potenciometro na saida serial
  Serial.println(ledDelay);

  // Verifica se já transcorreram ledDelay ms desde a última alteração
  if ((millis() - changeTime) > ledDelay)

  {
    changeLED();
    changeTime = millis();
  }
}

void changeLED()
{
  for (int x=0; x<10; x++)   //Apaga todos os LEDs
  {
    digitalWrite(Pinosled[x], LOW);
  }
  digitalWrite(Pinosled[ledatual], HIGH); // Acende o LED atual
  ledatual += direcao;  //incrementa de acordo com o valor de direction
  //altera a direção se tivermos atingido o fim
  if (ledatual == 9) {direcao = -1;}
  if (ledatual == 0) {direcao = 1;}
}
