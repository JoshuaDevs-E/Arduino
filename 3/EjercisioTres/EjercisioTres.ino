/*En una segunda solución para las luces del ejercicio #2, la secuencia principal del
programa debe estar reproducida en una función a la que llamará el programa
principal. Crear distintas secuencias de encendido para el juego de luces (usar 8
Leds), una secuencia en reversa, todos apagan-encienden juntos cada un segundo
(3 vcs) y una secuencia de salto con un led de diferencia.*/
#include <Arduino.h>

const int pinU = 3;
const int pinD = 4;
const int pinT = 5;
const int pinC = 6;
const int pinCI = 7;
const int pinS = 8;
const int pinSI = 9;
const int pinSE = 10;
const int delayTime = 150;

void setup() {
  for (int i = pinU; i <= pinSE; i++) {
    pinMode(i, OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < 3; i++) {
    secU();
  }

  secD();

  for (int i = 0; i < 3; i++) {
    secT();
  }

  for (int i = 0; i < 3; i++) {
    secC();
  }
}
void secU() {
  for (int i = pinU; i <= pinSE; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    delay(delayTime);
  }
}

void secD() {
  for (int i = 0; i < 5; i++) {
    for (int j = pinU; j <= pinSE; j++) {
      digitalWrite(j, HIGH);
    }
    delay(1000);
    for (int j = pinU; j <= pinSE; j++) {
      digitalWrite(j, LOW);
    }
    delay(1000);
  }
}

void secT() {
  for (int i = pinU; i <= pinSE; i += 2) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(pinSE, HIGH);
  delay(1000);

  for (int i = pinU; i <= pinSE; i += 2) {
    digitalWrite(i + 1, HIGH);
  }
  delay(1000);

  for (int i = pinU; i <= pinSE; i++) {
    digitalWrite(i, HIGH);
  }
  delay(1000);
}

void secC() {
  for (int i = pinU; i <= pinSE; i++) {
    digitalWrite(i, HIGH);
  }
  delay(1000);

  for (int i = pinSE; i >= pinU; i--) {
    digitalWrite(i, LOW);
  }
  delay(1000);
}
