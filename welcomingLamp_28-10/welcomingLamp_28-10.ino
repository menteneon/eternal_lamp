// libreria del modulo reproductor mp3
#include <DFMiniMp3.h>

// libreria que nos va a servir para acortar la distancia de medicion del sensor
#include <NewPing.h>

// definir los pines en el arduino
#define TRIGGER_PIN 8
#define ECHO_PIN 9 
#define MAX_DISTANCE 60
#define SPEAKER_PIN 6
#define MP3_PIN
// const int pinEcho = 9;
// const int pinTrigger = 8;
// const int pinRelay = 3;
// const int pinSpeaker = 4;
// const int pinMP3 = 5;


// acorta la distancia del sensor, (pinTrigger, pinEcho, distancia maxima en cm)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, 60);

// inicia el reproductor mp3
// DFPlayerMini mp3(pinMP3);

// funcion para reproducir un archivo de audio
int playFile() {
  // numero de archivos de audio en la SD
  // int numFiles = SD.countFiles();

  // generar un numero aleatorio entre 0 y el numero total de archivos
  // int randomFile = random(numFiles);

  // devolver el numero aleatorio
  // return randomFile;
}

void setup() {
  Serial.begin(9600);

  // iniciar el sensor hc
  // sonar.begin();

  // iniciar la comunicacion spi
  // SPI.begin();

  // iniciar la tarjeta SD
  // SD.begin();

  configurarPines();

  // reproducir el archivo de audio de inicio
  playFile();
}

void loop() {
  Serial.print("Distancia: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  // leer la distancia del sensor hc
  int distance = sonar.ping_cm();

  // si la cantidad de personas es mayor a 1, enciende la ampolleta y reproduce el audio aleatorio
  if (sonar.ping_cm() >= 1 && sonar.ping_cm() <= 60) {
    digitalWrite(LED_BUILTIN, HIGH);
    int randomFile = playFile();
    // mp3.playRandom(randomFile);

  // si la medicion es 0, apaga la ampolleta y deten la reproduccion del audio aleatorio
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    // mp3.stop();
  }
}
