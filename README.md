# Eternal_lamp

## acerca de

Proyecto resignificación de una lámpara de pie con el concepto de cápsula de tiempo.

Nuestro objetivo es recordar a seres queridos. Guarda e inmortaliza audios importantes.

## equipo

Esta lámpara está siendo realizada por @janisepulveda, @menteneon y @ssofiasandoval, estudiantes de diseño industrial UDP.

## tecnología y herramientas de trabajo

* Arduino IDE https://www.arduino.cc/en/software
* GitHub https://github.com
* Sensor HC SR04
* Reproductor MP3
* Tarjeta SD
* Relay
* Soquete
* Ampolleta
* Parlante

## instalación de desarrollador

* Descargar Arduino IDE https://www.arduino.cc/en/software
* Instalar la librería DFRobotDFPlayerMini.h por DFRobot
* Instalar la librería NewPing.h por Tim Eckel

## instalación de uso

*

## funcionamiento

* El sensor al detectar presencia, enciende la ampolleta y tras 2 segundos comienza la reproducción de un audio aleatorio dentro de la tarjeta SD de duración entre 6 a 10 segundos, luego de la reproducción hay un tiempo de espera de 2 segundos y la luz se apaga. Si el sensor sigue detectando presencia, comienza de nuevo el ciclo.
  
## informes de entrega

* Fecha inicio del proyecto: 17 octubre 2023.
* Fecha de entrega: 08 diciembre 2023.

## desarrollo del proyecto

* Objetivo principal:
    almacenar, a modo de cápsula del tiempo, archivos de audio como mensajes de voz o recuerdos recuerdos personales.
* Contexto de creación:
    El desarrollo respectivo fue de investigación de interacciones, resignificaión de los objetos y uso e implementación de sensores en arduino. Las decisiones de diseño tomadas en el proyecto fueron pensando en la emocionalidad del usuario, la intención detrás de esto es permitir a las personas mantener cerca de ellas las voces y recuerdos de sus seres queridos, brindando consuelo y alegría.
* Aprendizajes:
    * Entender el funcionamiento de un sensor ultrasónico HC SR04.
    * Entender el funcionamiento de un relay conectado a la corriente y a un soquete con ampolleta.
    * Entender el funcionamiento de un reproductor MP3 conectado a Arduino y a un parlante como salida de audio.

## bibliografía 

* https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
* https://github.com/DFRobot/DFRobotDFPlayerMini
  
