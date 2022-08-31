
const byte LED = 2; //pino que o LED do módulo ESP12E está ligado

void setup() {
  pinMode(LED, OUTPUT);

}

void loop() {
  digitalWrite(LED,LOW);  //liga o LED
  delay(1000);            //espera 1 segundo
  digitalWrite(LED,HIGH); //apaga o LED
  delay(1000);            //espera 1 segundo
}
