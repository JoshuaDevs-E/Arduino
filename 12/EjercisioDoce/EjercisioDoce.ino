/*Se trata de generar hasta 8 notas musicales por una de las salidas analógicas de
Arduino –PIN10-
Se debe crear un array (vector) de datos compuesto por los valores
correspondientes a las 8 notas que se pretende sacar:
int notas[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
Se deben definir también el tiempo de pausa entre nota y nota y el tiempo de pausa
de fin de secuencia de notas:
int tnota=100; int pausa=100;
Las iteraciones para el recorrido de las 8 notas se realizan con una instrucción de
tipo for:
for(n=0;n<8;n++)
El tiempo de activado y desactivado de la salida del zumbador también se resuelve
con un bucle for:
for(m=0;m<=tnota;m++)*/
int zumbadorPin = 10; // Pin al que está conectado el zumbador (salida analógica)
int notas[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956}; // Valores de frecuencia para las notas
int tnota = 100; // Tiempo de duración de cada nota en milisegundos
int pausa = 100; // Tiempo de pausa entre notas en milisegundos

void setup() {
  pinMode(zumbadorPin, OUTPUT);
}

void loop() {
  for (int n = 0; n < 8; n++) {
    // Generar la nota actual
    tone(zumbadorPin, notas[n]);

    // Mantener la nota durante el tiempo especificado (tnota)
    for (int m = 0; m <= tnota; m++) {
      delay(1); // Pequeña pausa para mantener la nota
    }

    // Apagar el zumbador
    noTone(zumbadorPin);

    // Hacer una pausa entre notas
    delay(pausa);
  }
}
