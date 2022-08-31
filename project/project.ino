
#include <WiFi.h>                          //importa biblioteca para conectar esp32 com wifi
#include <IOXhop_FirebaseESP32.h>          //importa biblioteca para esp32 se comunicar com firebase
#include <ArduinoJson.h>                   //importa biblioteca para colocar informação no formato json, utilizado no firebase

#include "max6675.h"                       //importa sensor de temperatura
int thermoDO = 19;
int thermoCS = 23;
int thermoCLK = 5;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

#include <ModbusIP_ESP8266.h> //Biblioteca MODBUS para ESP8266/ESP32
IPAddress local_IP(192, 168, 81, 218);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress PRIMARY_DNS(8, 8, 8, 8);
IPAddress SECONDARY_DNS(8, 8, 4, 4);
ModbusIP mb;

//#include "BluetoothSerial.h"              // importa bluetooth
//#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
//#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
//#endif
//BluetoothSerial SerialBT;

//#define WIFI_SSID "NET_2G973E90"                      // nome wifi
//#define WIFI_PASSWORD "4A973E90"                      // Senha wifi
#define WIFI_SSID "MatheusBozzi"                      // nome wifi 
#define WIFI_PASSWORD "matheusb"                      // Senha wifi
#define FIREBASE_HOST "https://projectopicos-34007-default-rtdb.firebaseio.com/"    //link do banco de dados 
#define FIREBASE_AUTH "brBwYYj94Osmtg8NytvQj1wVPm5ApNAZFk3fklaq"                    //senha banco de dados

double *temperaturas, *tempos;
int numVirgulas = 0;
int torrando = 0;

//int flag = 0;


void setup() {
  Serial.begin(115200);      //inicia comunicação serial
  Serial.println();          //imprime pulo de linha

  //  SerialBT.begin("Torrador"); //Bluetooth device nome

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());

  //  Configurando o WiFi///////////////////////////
  //  if (!WiFi.config(WiFi.localIP(), gateway, PRIMARY_DNS, SECONDARY_DNS, subnet)) {
  //    Serial.println("STA Failed to configure");
  //  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   //inicia comunicação com firebase

  mb.server();
  for (int i = 0; i < 30; i++) {
    mb.addHreg(i);  //Adicionando 30 Holding registers
    mb.addCoil(i);  //Adicionando 30 Coils
    mb.addIsts(i, 0); //Adicionando 30 Input discrete registers
    mb.addIreg(i, 0); //Adicionando 30 Input registers
  }

  thermocouple.readCelsius();

}


void montaVetores2(double *v, int cont) {
  double *temp;
  temp = (double*) malloc(sizeof(double) * (cont / 2));
  double *tempo;
  tempo = (double*) malloc(sizeof(double) * (cont / 2));

  int j = 0, k = 0;
  for (int i = 0; i < cont; i++) {
    if (i % 2 == 0) {
      temp[j] = v[i];
      j++;
    } else {
      tempo[k] = v[i];
      k++;
    }
  }
  temperaturas = temp;
  tempos = tempo;
  //  free(temp);
  //  free(tempo);
  torrando = 1;
  Firebase.setBool("torrando", true);
}


void montaVetores(String curva, int cont) {
  char c[2048];                                         // essa parte abaixo monta um vetor de double com os dados
  curva.toCharArray(c, 2048);
  if (curva != "") {
    char* token = strtok(c, ",");
    double v[cont];
    for (int i = 0; i < cont; i++) {
      token = strtok(NULL, ",");
      v[i] = strtod(token, NULL);                      // o vetor v possui os dados recebidos
    }

    montaVetores2(v, cont);                          // vai para a funcao que separa os valores de temperatura e tempo
    v[cont] = NULL;
    numVirgulas = cont;
  }
}

void loop() {

  mb.task();
//  mb.Ireg(2, torrando);
  //    mb.Hreg(1,)
  mb.Ireg(3, thermocouple.readCelsius() * 100); //Dando valor da temperatura para o para o Input register com o endereço 3

  if (Firebase.getBool("/torrando")) {
    torrando = 1;
  } else {
    torrando = 0;
  }

  bool x = Firebase.getBool("novaCurvaCsv/status");
  if (x == true) {             // verifica status
    String curvaRecebida = Firebase.getString("novaCurvaCsv/dados");        // le o Csv da chave novaCurva
    if (curvaRecebida != NULL) {                                      // se tem algo, é porque chegou uma nova torra
      //    Serial.println(Firebase.getString("novaCurvaCsv"));
      //      Serial.println("tem curva");
      int cont = 0;
      for (int i = 0; i < curvaRecebida.length(); i++) {
        if (curvaRecebida[i] == ',') cont++;                  // conta o numero de linhas
      }
      montaVetores(curvaRecebida, cont);              // funcao que armazena os valores em dois vetores de double (temperaturas, tempos)
    }
    Firebase.setBool("novaCurvaCsv/status", false);
  }


  Firebase.setFloat("/temperatura", thermocouple.readCelsius());

}
