#include "Arduino.h"
#include "MP3.h"
#include "HCSR04.h"

// DFRobotDFPlayerMini myDFPlayer;


// pin para el relay
int pinSrelay = 4;
boolean audioIniciado = false;

void relay(bool estadoLuz) {
  // esta funcion activa y desactiva la conexion del relay para la luz
  // escribir en el pin del relay el valor que queremos (en SIGNAL) dependiendo del booleano de entrada
  if (estadoLuz){
    digitalWrite(pinSrelay, HIGH);
  } else {
    digitalWrite(pinSrelay, LOW);
  }
}

int estado = 0;
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long intervalo = 2000;  // interval at which to blink (milliseconds)


void setup() {
  configurarMP3();
  configurarHCSR04();
}

void enciendeLuz(){
  
  relay(true);
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= intervalo) {
      // guarda la vez anterior que se ejecuto
      previousMillis = currentMillis;

      // realiza la accion
      estado =2;
      
    }
  
}


void reproducirAudio(int _duracionAudio){
   
  if (!audioIniciado) {
    tocarMP3();
  }
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= _duracionAudio) {
      // guarda la vez anterior que se ejecuto
      previousMillis = currentMillis;

      // realiza la accion
      estado = 3;
    }
  
}


void apagaLuz(){
 
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= intervalo) {
      // guarda la vez anterior que se ejecuto
      previousMillis = currentMillis;

      // realiza la accion
      relay(false);
      estado = 4;
    }
  
}

void esperaFinal(int _intervaloFinal){
  
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= _intervaloFinal) {
      // guarda la vez anterior que se ejecuto
      previousMillis = currentMillis;

      // realiza la accion
      estado = 0;
    }
  
}

void loop() {

  while(detecta()) {
    switch (estado) {
      case 0:
      break;

      case 1:
      enciendeLuz(); //1
      break;

      case 2:
      reproducirAudio(10000);//2
      break;

      case 3:
      apagaLuz(2000); //3
      break;

      case 4:
      esperaFinal(); //4
      break;

      // default:
      // break;
    }

  }

  // actualizarMP3();
  // if (detecta(6)){
  //   tocarMP3(); 
  // }
}

// -----> sector de RELAY <-----

