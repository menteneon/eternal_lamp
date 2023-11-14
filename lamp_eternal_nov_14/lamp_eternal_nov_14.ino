#include "Arduino.h"
// #include "DFRobotDFPlayerMini.h"

#include "MP3.h"
#include "HCSR04.h"

#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;



void setup() {
  configurarMP3();
  configurarHCSR04();
}

void loop() {
  actualizarMP3();
  if (detecta(6)){
    myDFPlayer.play(random(1,10));
  }
}

