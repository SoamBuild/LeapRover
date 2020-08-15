/*
*SoamBuild
 *15/08/2020
 */

//Libreria : http://michaelkipp.de/interaction/leap.html
//Librerias

import de.voidplus.leapmotion.*;// libreria leapmotion

//Objeto LeapMotion y Variables Leap.
LeapMotion leap;
float Pitch; 
float Roll; 

//Otras variables
String ip = "192.168.0.25";//Tu ip estatica leap motion
String Command; //Comandos
String lastmsg = "";//String para funcion

void setup()
{
  Command= "Wait";//Estado default de comandos.
  size(1000, 800); // Tamaño del canvas
  leap = new LeapMotion(this); // Objeto de Leap
}

void draw()
{
  background(250); 

  //Obtener datos de mano Leap
  for (Hand hand : leap.getHands ()) 
  {
    Roll  =  hand.getRoll(); //get Roll
    Pitch =  hand.getPitch(); //get Pitch

    textSize(26); //Tamaño de texto
    text("Roll: " +round(Roll), 100, 30); //Roll redondeado
    text("Pitch: " +round (Pitch), 100, 60);//Pitch redondeado
    text("Command: " +Command, 100, 90);//Comandos en pantalla

    textSize(12); //Tamaño texto data mano
    hand.draw();//Dibujar mano con valores

    // Detener motores.
    if ((Pitch<=20)&&(Pitch>=-20)) 
    {
      Command = "Detenido";
      Send("detener");
    }

    // Adelante 
    if (Pitch>=20)
    {
      Command = "Adelante";
      Send("adelante");
      
      //Adelante * Izquierda
      if (Roll<=-25)
      {
        Command = "Adelante + Izquierda";
        Send("izquierda");
      }
      //Adelante * Derecho
      if (Roll>=25)
      {
        Command = "Adelante + Derecha";
        Send("derecha");
      }
    }
    
    // Atras
    if (Pitch<=-20)
    {
      Command = "Atras";
      Send("atras");
    }
  }
} 

/*
*Esta funcion recibe un valor y lo envia.
*Solamente lo envia una vez, asi el codigo no se detiene o pega.
*Recoge automaticamente la ip que ingresaste
*/

//Funcion de envio de datos
void Send(String msg) {
  if (msg.equals(lastmsg)==false) {
    loadStrings("http://"+ip+"/"+msg);
    lastmsg = msg;
  }
}
