/*
***Codigo de processing para rover
 ***Serial Comandos
 *** A = Adelante / Avanza
 *** B = Atras / Retrocede
 *** C = Frenar / Stop
 *** D = Izquierda / Avanza y gira a la izquierda
 *** E = Derecha  / Avanza y gira a la derecha
 ***Notas
 ***Este codigo recoge las coordenadas en el eje x,z (ver documentacion), estas coordenadas se deben ajustar
 ***Se conecta mediante a Rover mediante el Bluetooth del mismo computador(revisar documentacion)
 ***V.1.2
 */
import de.voidplus.leapmotion.*;// libreria leapmotion
import processing.serial.*;  //libreria serial para enviar datos

LeapMotion leap;// objeto leap
Serial port;// puerto serial 
float valX;// float para eje x
float valZ;// float para eje z
String[] data; 

void setup()
{
  size(800, 500, OPENGL);
  leap = new LeapMotion(this);
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  for (Hand hand : leap.getHands ()) {
    PVector indexTip = hand.getIndexFinger().getRawPositionOfJointTip();

    text("x: " + nf(indexTip.x, 0, 1), 50, 90);
    valX=(indexTip.x);
    println("x:"+ valX);
    text("z: " + nf(indexTip.z, 0, 1), 20, 80);
    valZ=(indexTip.z);

    println("z:" + valZ);
    ////////////////////////////////////////////////////
    if ((valX>=33) && (valZ <=-50)) // ADELANTE Y DERECHA 
    {
      port.write("1");
    } else 
    {
      port.write("0");//SE DETIENE
    }
    ////////////////////////////////////////////////////
    if ((valX>=33) && (valZ >=0)) // ATRAS Y DERECHA 
    {
      port.write("4");
    }
    ////////////////////////////////////////////////////////
    if ((valX<=-33) && (valZ <=-50))// ADELANTE Y IZQUIERDA 
    {
      port.write("2");
    } 
    ////////////////////////////////////////////////////////
    if ((valX<=-33) && (valZ >=0)) // ATRAS Y IZQUIERDA 
    {
      port.write("3");
    }
    ////////////////////////////////////////////////////////
    if ((valX>=-33) &&(valX<=33))//si esta en el centro 
    {
      if (valZ <=-55)//avanza
      {
        port.write("5");
      }
      if (valZ>=0)// retrocede 
      {
        port.write("6");
      }
    }

    hand.draw();//Dibuja mano
  }
}
