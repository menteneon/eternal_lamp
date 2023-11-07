#include "Arduino.h"

// libreria para reproducir el audio
#include "DFRobotDFPlayerMini.h"

// libreria que nos va a servir para acortar la distancia de medicion del sensor
#include <NewPing.h>

// definir los pines en el arduino
#define TRIGGER_PIN 8
#define ECHO_PIN 9 
#define MAX_DISTANCE 60
// #define SPEAKER_PIN 
#define MP3_PIN 10
#define MP3_PIN2 11

// definir reproductor mp3 y sus respectivos pines
#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266)) 

// comunicacion serial
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif


// acorta la distancia del sensor, (pinTrigger, pinEcho, distancia maxima en cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, 60);

void setup() {
  Serial.begin(9600);
  configurarPines();
  configurarMp3();
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
