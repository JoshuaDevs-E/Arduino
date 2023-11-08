/*Se trata de encender y apagar 4 leds secuencialmente al accionar un pulsador. El
pulsador debe estar conectado al pin 4, y los leds a los pines 5,6,7 y 8. Se deben
encender y posteriormente apagar los leds desde el pin 5 al 8, con un tiempo de
duración de encendido y apagado de 200 milisegundos. Nota: la secuencia principal
del programa debe estar reproducida en una función a la que llamará el programa
principal.*/

const int buttonPin = 2; 
const int ledPins[] = {3, 4, 5, 6};  
const int numLeds = 4;

int ledIndex = -1;
int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonSta
    
    te) {
      buttonState = reading;
      if (buttonState == LOW) {
        ledIndex = (ledIndex + 1) % numLeds;
        Serial.print("Encendiendo LED ");
        Serial.println(ledIndex);
        digitalWrite(ledPins[ledIndex], HIGH);
      }
    }
  }
  ledIndex = (ledIndex + 1) % numLeds;
  lastButtonState = reading;
}
