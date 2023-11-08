/*(Usar ciclo FOR) Se trata de encender y apagar 7 leds secuencialmente. Los leds
deben estar conectados a los pines 5,6,7,8,9,10 y 11. Se deben encender y apagar
los leds desde el pin 5 al 11, con un tiempo de encendido y apagado de 50 ms, más
tarde se deben encender y apagar los leds desde el pin 11 al 5, con un tiempo de
encendido y apagado de 50 ms. La secuencia se debe repetir indefinidamente. El
efecto del programa es el de las luces delanteras de nuestro querido "Coche
fantástico".*/
int leds[] = {5, 6, 7, 8, 9, 10, 11};
int numLeds = 7;
int tiempoEncendido = 50; // Tiempo de encendido en milisegundos

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT); // Configura los pines como salidas
  }
}

void loop() {
  // Encender LEDs desde el pin 5 al 11
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH); // Enciende el LED actual
    delay(tiempoEncendido);     // Espera el tiempo de encendido
    digitalWrite(leds[i], LOW);  // Apaga el LED actual
  }

  // Encender LEDs desde el pin 11 al 5
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH); // Enciende el LED actual
    delay(tiempoEncendido);     // Espera el tiempo de encendido
    digitalWrite(leds[i], LOW);  // Apaga el LED actual
  }
}
