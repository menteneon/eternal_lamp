#include "Arduino.h"

// libreria para reproducir el audio desde la tarjeta SD
#include "DFRobotDFPlayerMini.h"

// libreria que nos va a servir para acortar la distancia de medicion del sensor
#include <NewPing.h>

// definir los pines en el arduino
#define TRIGGER_PIN 8
#define ECHO_PIN 9 
#define MAX_DISTANCE 60
#define SPEAKER_PIN 3
#define MP3_PIN 10
#define MP3_PIN2 11


// acorta la distancia del sensor, (pinTrigger, pinEcho, distancia maxima en cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, 60);

// libreria mp3
void configurarMp3();

// 
void configurarPines();


void setup() {
  Serial.begin(9600);
}

void loop() {

  configurarPines();
  Serial.print("Distancia: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  // leer la distancia del sensor hc
  int distance = sonar.ping_cm();

  // si la cantidad de personas es mayor a 1, enciende la ampolleta y reproduce el audio aleatorio
  if (sonar.ping_cm() >= 1 && sonar.ping_cm() <= 60) {
    digitalWrite(LED_BUILTIN, HIGH);

  // si la medicion es 0, apaga la ampolleta y deten la reproduccion del audio aleatorio
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
