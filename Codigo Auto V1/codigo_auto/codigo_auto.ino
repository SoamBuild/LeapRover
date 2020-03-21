/*
***Documentacion de Motor Shield Adafruit / documentacion / descarga 
*https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/library-reference
***Serial Comandos
*** A = Adelante / Avanza
*** B = Atras / Retrocede
*** C = Frenar / Stop
*** D = Izquierda / Avanza y gira a la izquierda
*** E = Derecha  / Avanza y gira a la derecha
*** F = Aumenta la velocidad solo con app movil
*** G = Disminuye la velocdad solo con app movil
*/


#include <SoftwareSerial.h> // Libreria software Serial
#include <AFMotor.h> //Libreria para shield de motores 
int vel = 100; //Velocidad 100 inicial

AF_DCMotor motor3(3);// Declaracion de motores
AF_DCMotor motor2(2);// Declaracion de motores
AF_DCMotor motor1(1);// Declaracion de motores
SoftwareSerial bluetooth (2, 13);// Rx & Tx
char lectura;//Lectura del bluetooth

void setup() {
  Serial.begin(9600); //Monitor Serial Debug mensajes del bluetooth
  pinMode(8, OUTPUT);
  bluetooth.begin (9600); //Inicia el bluetooth
  motor3.run(RELEASE);// Reset motor
  motor2.run(RELEASE);// Reset motor
  motor1.run(RELEASE);// Reset motor
}
void loop()
{
  //********Velocidad de los motores**********
  motor1.setSpeed(vel);//Set speed desde la variable vel
  motor2.setSpeed(vel);//Set speed desde la variable vel
  motor3.setSpeed(vel - 25);//Set speed desde la variable vel / este motor es de menor potencia por lo tanto le reste 25
  //********Limites de velocidad**********
  if (vel >= 225)// Maxima velocidad
  {
    vel = 100;// Restablece velocidad
  }
  if (vel <= 50)// Minima velocidad
  {
    vel = 100;// Restablece velocidad
  }
  //********Lectura del bluetooth**********
  Serial.println(lectura); // Imprime los datos desde el bluetooth
  if (bluetooth.available() > 0) { // Bluetooth disponible
    lectura = bluetooth.read();//Lectura toma los datos de la lectura del bluetooth

    if (lectura == 'A')// Auto avanza
    {
      digitalWrite(8, HIGH);
      motor3.run(FORWARD);//Motor avanza
      motor3.setSpeed(vel);
      motor2.run(FORWARD);//Motor adelante
    }
    if (lectura == 'B')// atras
    {
      motor3.run(BACKWARD);//Motor retrocede
      motor2.run(BACKWARD);//Motor retrocede
    }
    if (lectura == 'C')//STOP
    {
      motor3.run(RELEASE);//Motor se detiene
      motor2.run(RELEASE);//Motor se detiene
      motor1.run(RELEASE);//Motor se detiene
    }
    if (lectura == 'D')
    {
      motor3.run(FORWARD);//Motor Adelante
      motor2.run(FORWARD);//Motor Adelante
      motor1.run(FORWARD);//Motor Adelante y izquierda
    }
    if (lectura == 'E')
    {
      motor3.run(FORWARD);//Motor Adelante
      motor2.run(FORWARD);//Motor Adelante
      motor1.run(BACKWARD);//Motor Adelante y derecha
    }
    if (lectura == 'F') //Desde app aumenta velocidad
    {
      vel = vel + 10; //velocidad + 10
    }
    if (lectura == 'G') // Desde app disminuye velocidad
    {
      vel = vel - 10; // velocidad -10
    }
  }
}
