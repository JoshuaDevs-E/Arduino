/*Cruce de semáforos. Se trata de un cruce de semáforos controlado por arduino, para
ello utilizaremos en el primer semáforo los pines 3 (led rojo), 4 (led ambar), 5 (led
verde), en el segundo semáforo utilizaremos los pines 6 (led rojo), 7 (led ambar) y 8
(led verde). La secuencia de funcionamiento debe ser: rojo 1 – verde 2 durante 3
segundos, rojo 1 – ambar 2 (parpadea) durante 500 ms, verde 1 – rojo 2 durante 3
segundos, ambar 1 ( parpadea) - rojo 2 durante 500 ms.*/
const int semaforo1_rojo = 3;
const int semaforo1_ambar = 4;
const int semaforo1_verde = 5;
const int semaforo2_rojo = 6;
const int semaforo2_ambar = 7;
const int semaforo2_verde = 8;

void setup() {
  // Inicializa los pines como salidas
  for(int i = 3; i< 8; i++){
    pinMode(i , OUTPUT);
  }
}

void loop() {
  // Rojo 1 - Verde 2 durante 3 segundos
 secuencia(1, 1)

  // Rojo 1 - Amarillo 2 (parpadea) durante 500 ms
  digitalWrite(semaforo2_verde, LOW);
  for (int i = 0; i < 4; i++) {
    digitalWrite(semaforo2_ambar, HIGH);
    delay(250);
    digitalWrite(semaforo2_ambar, LOW);
    delay(250);
  }

  secuencia(0, 1)

  // Amarillo 1 (parpadea) - Rojo 2 durante 500 ms
  digitalWrite(semaforo1_verde, LOW);
  for (int i = 0; i < 4; i++) {
    digitalWrite(semaforo1_ambar, HIGH);
    delay(250);
    digitalWrite(semaforo1_ambar, LOW);
    delay(250);
  }
}
void secuencia(h, l){
  digitalWrite(semaforo1_rojo, h);
  digitalWrite(semaforo2_verde, h);
  delay(3000);
}
