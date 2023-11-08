/*Se trata de simular el movimiento de la llama de una vela. Hacemos uso de la
instrucción para generar un número aleatorio que lo asignamos a una salida
analógica PWM y otro número que lo asociamos a la variable de temporización
(tiempo que esperamos para cambiar el valor de la salida).*/
int ledPin = 9; // El pin al que está conectado el LED
int minValue = 50; // Valor mínimo de la intensidad de la llama
int maxValue = 255; // Valor máximo de la intensidad de la llama
int flickerSpeed = 100; // Velocidad de parpadeo de la llama en milisegundos

void setup() {
  pinMode(ledPin, OUTPUT);
  randomSeed(analogRead(0)); // Inicializa la generación de números aleatorios
}

void loop() {
  int randomValue = random(minValue, maxValue); // Genera un valor aleatorio entre minValue y maxValue
  analogWrite(ledPin, randomValue); // Establece la intensidad de la llama

  // Agrega un efecto de flicker al cambiar aleatoriamente la intensidad de la llama
  delay(flickerSpeed);
}
