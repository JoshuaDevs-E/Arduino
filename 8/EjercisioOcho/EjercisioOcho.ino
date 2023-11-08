/*Se trata de un dispositivo que haga lucir un led más o menos en función del valor de
un potenciómetro. Para ello conectaremos el potenciómetro a la entrada analógica 0
y un led al pin 9. Cuando el potenciómetro se encuentre entre 0 y 512 el led debe
colocarse en el nivel de potencia máxima (255), si el potenciometro se encuentra
entre valores 512 y 1024 él led debe lucir al nivel de potencia 64. Además, se deberá
mostrar el valor de voltaje en la entrada analógica (valor entre 0 y 1024) en una
consola en el PC.*/

const int potPin = A0;  // Pin analógico del potenciómetro
const int ledPin = 9;  // Pin para el LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  int potValue = analogRead(potPin);  // Lee el valor analógico del potenciómetro
  int ledBrightness;

  // Mapea el valor del potenciómetro al rango de brillo del LED
  if (potValue >= 0 && potValue <= 512) {
    ledBrightness = 255;  // Nivel de potencia máxima
  } else if (potValue > 512 && potValue <= 1024) {
    ledBrightness = 64;   // Nivel de potencia 64
  }

  analogWrite(ledPin, ledBrightness);  // Controla la intensidad del LED
  Serial.println(potValue);  // Envía el valor analógico a la consola

  delay(100);  // Pequeña pausa para evitar una rápida actualización de la consola
}
