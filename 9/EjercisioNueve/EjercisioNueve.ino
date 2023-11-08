// Velocidad de la estrella
const int velocidad = 100;
// Longitud de la cola
const int cola = 3;

// Variables locales
int i = 0;

void setup() {
  // Inicializa los pines digitales como salidas
  for (int i = 0; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Enciende los LED-s de la cola
  for (int i = 0; i < cola; i++) {
    digitalWrite(i, HIGH);
  }

  // Enciende el siguiente LED
  digitalWrite(i, HIGH);

  // Apaga el LED más a la derecha
  digitalWrite(i - 1, LOW);

  // Avanza la posición del LED
  i++;

  // Si el LED más a la derecha está encendido, apaga la estrella
  if (i == 7) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(i, LOW);
    }
  }

  // Retrasa la ejecución
  delay(velocidad);
}