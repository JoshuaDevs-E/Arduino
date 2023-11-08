/*Ruleta de la fortuna. Se trata de cinco leds que se van encendiendo y apagando
formando una secuencia, el jugador debe dar al pulsador cuando el led intermedio
se enciende, si acierta funciona un zumbador y la velocidad de la secuencia
aumenta. Los leds deben estar conectados de los pines 5 a 9, el zumbador al pin 10,

el pulsador al pin 11. El tiempo inicial entre encendido y encendido de leds debe ser
200 ms, si se acierta se decrementa el tiempo en 20 ms, si el tiempo entre
encendidos llegase a 10 ms, se devuelve el tiempo a 200 ms.*/
#include <Tone.h> 

const int ledPins[] = {5, 6, 7, 8, 9};
const int buzzerPin = 10;
const int buttonPin = 11;
int sequenceSpeed = 200;  
int currentLed = 0;       
unsigned long lastTime = 0; 
bool buttonPressed = false;

Tone tone1;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
  tone1.begin(buzzerPin); 
  digitalWrite(ledPins[currentLed], HIGH);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    if (currentLed == 2) {
      tone1.play(3000, 100);       
      sequenceSpeed -= 20;
      if (sequenceSpeed < 10) {
        sequenceSpeed = 200;
      }
    } else {
      tone1.play(261.63, 500); 
    }
  } else if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = false;
  }

  unsigned long currentTime = millis();
  if (currentTime - lastTime >= sequenceSpeed) {
    digitalWrite(ledPins[currentLed], LOW);  
    currentLed = (currentLed + 1) % 5; 
    digitalWrite(ledPins[currentLed], HIGH);  
    lastTime = currentTime;
  }
}
