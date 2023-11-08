/*Led parpadeante. Se trata de conectar un led al pin 13, haciendo que luzca durante
500 ms y que se apague durante 100 ms, este proceso se repetirá cíclicamente.*/
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin 13 como salida
}

void loop() {
  digitalWrite(ledPin, HIGH); // Enciende el LED
  delay(500); // Espera 500 ms (medio segundo)

  digitalWrite(ledPin, LOW); // Apaga el LED
  delay(100); // Espera 100 ms (una décima de segundo)
}
