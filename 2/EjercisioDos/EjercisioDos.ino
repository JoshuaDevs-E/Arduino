/*Secuencia de leds. Se trata de encender y apagar 4 leds secuencialmente. Los leds
deben estar conectados a los pines 5,6,7 y 8. Se deben encender y posteriormente
apagar los leds desde el pin 5 al 8, con un tiempo de duración de encendido y
apagado de 200 milisegundos.*/
void setup(){
  for(int i = 5;i<9;i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  for(int j = 5;j<9;j++){
    digitalWrite(j, HIGH);
    delay(200);
    digitalWrite(j, LOW);
    delay(200);
  }
}
