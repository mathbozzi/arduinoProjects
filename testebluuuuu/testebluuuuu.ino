#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 11);
int BLUE;

void setup()
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop()
{
  Bluetooth.listen();
  delay(500);
  if (Bluetooth.available())
  {
    BLUE = Bluetooth.read();
    Serial.write(BLUE);

  }
  LOCK_UNLOCK();
}

void LOCK_UNLOCK()
{
  if (BLUE == '6')
  {
    Bluetooth.println("data from outdoor to app");
  }
}
