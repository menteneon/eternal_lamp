#include "Arduino.h"
#include "HCSR04.h"
#include "NewPing.h"


#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 60

// acorta la distancia del sensor, (pinTrigger, pinEcho, distancia maxima en cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, 60);

bool detecta(int pin) {
  if (digitalRead(pin) == HIGH) {
    return true;
  } else {
    return false;
  }
}

void configurarHCSR04() {


  Serial.print("Distancia: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  int distance = sonar.ping_cm();

  // si la cantidad de personas es mayor a 1, enciende la ampolleta y reproduce el audio aleatorio
  if (sonar.ping_cm() >= 1 && sonar.ping_cm() <= 60) {
    digitalWrite(LED_BUILTIN, HIGH);

    // si la medicion es 0, apaga la ampolleta y deten la reproduccion del audio aleatorio
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

}




void configurarPines() {
}
