#include "Arduino.h"
// #include "DFRobotDFPlayerMini.h"
#include "NewPing.h"
#include "MP3.h"

// definir los pines en el arduino
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 60
#define SPEAKER_PIN 3
#define MP3_PIN 10
#define MP3_PIN2 11

// acorta la distancia del sensor, (pinTrigger, pinEcho, distancia maxima en cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, 60);

void setup() {
  configurarMP3();
}

void loop() {
  actualizarMP3();
}
