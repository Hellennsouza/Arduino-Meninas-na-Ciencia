
//Hellen e Mirla
/*Sensor de Temperatura contra agua NTC 10K<br>Instrucciones:
El sensor para temperatura contra agua NTC 10k es un thermistor con dos salidas
que requieren de una configuracion pull down. Conecte una terminal del sensor a Vcc 
y la otra utilizando resistencia pull down a tierra y al pin análogo 2.
*/
#include <math.h><br>        
void setup() {            
Serial.begin(115200);//Recuerda ajustar to monitor serial a 115200   
} 
double Thermister(int RawADC) {  
double Temp;
//Tentar simplificar:
Temp = log(((10240000/RawADC) - 10000));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;// Converte de Kelvin para celsius
//Para converter Celsius a Farenheith escreva: Temp = (Temp * 9.0)/ 5.0 + 32.0; 
return Temp;
} 
void loop() {             
int val;//Cria uma variável inteira
double temp;//Variavel de temperatura
val=analogRead(0);//Ler o valor do pin(0)
temp=Thermister(val);//Converte o valor do  analogico para graus celsius
Serial.println(temp);//Escreve a temperatura no monitor serial
delay(1000);//Espera um segundo
}
