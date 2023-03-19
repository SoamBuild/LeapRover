/*
 *Desarrollado con Wemos d1 mini && Motor control l298d
 *15/08/2020
 *Codigo base https://makersportal.com/blog/2019/6/12/wemos-d1-mini-esp8266-arduino-wifi-board
 *Modificada:SoamBuild 
*/


//Librerias
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//Configurar Ip estatica y señal wifi
const char* ssid = ""; 
const char* password = "";
IPAddress ip(192, 168, 3, 25);
IPAddress gateway(192, 168, 3, 1);
IPAddress subnet(255, 255, 255, 0);

//ENA&ENB
int enA = 12;//D6 WEMOS
int enB = 5;//D1 WEMOS

//Canal 1&2
int cha1 = 14;//D5 WEMOS
int cha2 = 16;//D0 WEMOS

//Canal 3&4
int cha3 = 0;//D3 WEMOS
int cha4 = 4;//D2 WEMOS

ESP8266WebServer server(80);

//Crear primera conexion
void handleRoot() {
  server.send(200, "text/plain", "MagicRover Conectado");
}

//Adelante
void adelante() {
  server.send(200, "text/plain", "MagicRover Adelante");
  analogWrite(enA, 440);
  digitalWrite(cha1, HIGH);
  digitalWrite(cha2, LOW);
}

//Atras
void atras() {
  server.send(200, "text/plain", "MagicRover Atras");
  analogWrite(enA, 440);
  digitalWrite(cha1, LOW);
  digitalWrite(cha2, HIGH);
}

//se detienen todos los motores
void detener() {
  server.send(200, "text/plain", "MagicRover se Detiene");
  digitalWrite(cha1, LOW);
  digitalWrite(cha2, LOW);
  digitalWrite(cha3, LOW);
  digitalWrite(cha4, LOW);
}

//Izquierda y adelante
void izquierda() {
  server.send(200, "text/plain", "MagicRover gira Izquierda");
  analogWrite(enA, 440);
  digitalWrite(cha1, HIGH);
  digitalWrite(cha2, LOW);
  analogWrite(enB, 700);
  digitalWrite(cha3, HIGH);
  digitalWrite(cha4, LOW);
}

//derecha y adelante
void derecha() {
  server.send(200, "text/plain", "MagicRover gira Derecha");
  analogWrite(enA, 440);
  digitalWrite(cha1, HIGH);
  digitalWrite(cha2, LOW);
  analogWrite(enB, 700);
  digitalWrite(cha3, LOW);
  digitalWrite(cha4, HIGH);
}

void setup(void) {

  //PinMode canales y enable A&B  
  pinMode(enA, OUTPUT);//ENA
  pinMode(enB, OUTPUT);//ENB
  pinMode(cha1, OUTPUT);//CANAL1
  pinMode(cha2, OUTPUT);//CANAL2
  pinMode(cha3, OUTPUT);//CANAL3
  pinMode(cha4, OUTPUT);//CANAL4
  
  //Wifi setup
  Serial.begin(115200);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Esperando conexion
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Mostrar IP estatica
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  //Funciones
  server.on("/", handleRoot); // Primera conexion
  server.on("/adelante", adelante); // mover adelante y adelante()
  server.on("/atras", atras); // mover atras y atras()
  server.on("/detener", detener); // detener y detener()
  server.on("/izquierda", izquierda); //girar izquierda y izquierda()
  server.on("/derecha", derecha); // girar derecha y derecha()

  //Inicia server
  server.begin();
  Serial.println("HTTP server started");
}
//The loop
void loop(void) {
  server.handleClient();
}
