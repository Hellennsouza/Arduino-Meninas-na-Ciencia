#include <dht.h>
#define DHT11_PIN 2
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "dlink-759A";
const char* password = "semsenha";

ESP8266WebServer server(80);
dht DHT;

const int led = 2;

void handleRoot() {
  int chk = DHT.read11(DHT11_PIN);
  delay (1000);
  Serial.begin(115200);
  digitalWrite(led, 1);
  
  String textoHTML;
  
 textoHTML += "<!DOCTYPE html><html><head><meta charset = 'UTF-8'/><meta http-equiv='refresh' content='10'><title>Gráfico JS</title></head><body><br><br><br><br><br><center><canvas id= 'canvasGrafico'></canvas></center><script>window.onload = function(){var canvas = document.getElementById('canvasGrafico');if (canvas) {var altura = 300;var largura = 1000;var x = 0;var valor;canvas.setAttribute('width', largura);canvas.setAttribute('height', altura);var ctx = canvas.getContext('2d');ctx.fillStyle = 'lime';ctx.fillRect(0, 0, largura, altura);ctx.font = '30px Courier';}";
 
  int j;
  int conv;
  
  delay (1000);
  chk = DHT.read11(DHT11_PIN);
  textoHTML += "var temp = ["; 
  textoHTML += DHT.temperature;
  
  for (j = 0; j< 10; j++){
    delay (1000);
    chk = DHT.read11(DHT11_PIN);
    textoHTML += ",";
    conv = (float)DHT.temperature; 
    textoHTML += conv;
  }
  
    textoHTML += "];";
    textoHTML += "var i = -1;function desenharGrafico() {    i++;    x+=70;    valor = a[i];    ctx.lineTo(x, altura-valor);    ctx.stroke();    ctx.fillStyle = 'lime';    ctx.fillRect(0, 0, largura, 50);    ctx.fillStyle = 'red';    ctx.fillText(valor, x, 50);}setInterval(desenharGrafico, 1000);};</script>   </body></html>";
    textoHTML += "<br><b>Temperatura: </b>";
    textoHTML += DHT.temperature;
    textoHTML += "<br><b>Umidade: </b>";
    textoHTML += DHT.humidity;
    textoHTML += "</body> </html> ";
    
    textoHTML += "</body>";
    textoHTML += "</html>";
    server.send(200, "text/html", textoHTML);
    digitalWrite(led, 0);    
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
