
#include <WiFi.h>                          //importa biblioteca para conectar esp32 com wifi
#include <IOXhop_FirebaseESP32.h>          //importa biblioteca para esp32 se comunicar com firebase
#include <ArduinoJson.h>                   //importa biblioteca para colocar informação no formato json, utilizado no firebase

#include "max6675.h"                       //importa sensor de temperatura
int thermoDO = 19;
int thermoCS = 23;
int thermoCLK = 5;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

#include <ModbusIP_ESP8266.h> //Biblioteca MODBUS para ESP8266/ESP32
IPAddress local_IP(192, 168, 0, 32);
IPAddress gateway(10, 0, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress PRIMARY_DNS(8, 8, 8, 8);
IPAddress SECONDARY_DNS(8, 8, 4, 4);
ModbusIP mb;

//#define WIFI_SSID "NET_2G973E90"                      // nome wifi
//#define WIFI_PASSWORD "4A973E90"                      // Senha wifi
#define WIFI_SSID "MatheusBozzi"                      // nome wifi 
#define WIFI_PASSWORD "matheusb"                      // Senha wifi
#define FIREBASE_HOST "https://projectopicos-34007-default-rtdb.firebaseio.com/"    //link do banco de dados 
#define FIREBASE_AUTH "brBwYYj94Osmtg8NytvQj1wVPm5ApNAZFk3fklaq"                    //senha banco de dados

double *temperaturas, *tempos;
int numVirgulas = 0;
//int torrando = 0;


void modbusFunc( void * parametros);
void firebaseFunc( void * parametros);
void task_sensor( void * parametros );

/* filas (queues) */
QueueHandle_t xQueue_Firebase, xQueue_Modbus_torrando, xQueue_Modbus_temperatura;

/* semaforos utilizados */
SemaphoreHandle_t xSerial_semaphore;

void setup() {
  Serial.begin(115200);      //inicia comunicação serial
  Serial.println();          //imprime pulo de linha

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();

//  //Configurando o WiFi/
//  if (!WiFi.config(local_IP, gateway, PRIMARY_DNS, SECONDARY_DNS, subnet)) {
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

  /* Criação das filas (queues) */
  xQueue_Firebase = xQueueCreate( 1, sizeof( float ) );
  xQueue_Modbus_torrando = xQueueCreate( 1, sizeof( int ) );
  xQueue_Modbus_temperatura = xQueueCreate( 1, sizeof( float ) );

  /* Criação dos semaforos */
  xSerial_semaphore = xSemaphoreCreateMutex();
  if (xSerial_semaphore == NULL)
  {
    Serial.println("Erro: nao e possivel criar o semaforo");
  }

  xTaskCreate(
    task_sensor                     /* Funcao a qual esta implementado o que a tarefa deve fazer */
    ,  "sensor"   /* Nome (para fins de debug, se necessário) */
    ,  10000                          /* Tamanho da stack (em words) reservada para essa tarefa */
    ,  NULL                         /* Parametros passados (nesse caso, não há) */
    ,  3                            /* Prioridade */
    ,  NULL                       /* Handle da tarefa, opcional (nesse caso, não há) */
  );

  xTaskCreate(
    modbusFunc,
    "modbusFunc",
    10000,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    firebaseFunc,
    "firebaseFunc",
    10000,
    NULL,
    2,
    NULL
  );
  /* A partir deste momento, o scheduler de tarefas entra em ação e as tarefas executam */
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
  int torrando = 1;
  xQueueOverwrite(xQueue_Modbus_torrando, (void *)&torrando);
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

void loop()
{
  /* Tudo é executado nas tarefas. Há nada a ser feito aqui. */
}

/* --------------------------------------------------*/
/* ---------------------- Tarefas -------------------*/
/* --------------------------------------------------*/
void task_sensor( void *parametros )
{
  (void) parametros;
  UBaseType_t uxHighWaterMark;
  float temperatura = 0.0;

  while (1)
  {
    temperatura = (float) thermocouple.readCelsius();

    /* Envia temperatura lida para as tarefas a partir de filas */
    xQueueOverwrite(xQueue_Firebase, (void *)&temperatura);
    xQueueOverwrite(xQueue_Modbus_temperatura, (void *)&temperatura);

    /* Espera 300mili segundos */
    vTaskDelay( 300 / portTICK_PERIOD_MS );

    /* Para fins de teste de ocupação de stack, printa na serial o high water mark */
    xSemaphoreTake(xSerial_semaphore, portMAX_DELAY );

    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("task_sensor high water mark (words): ");
    Serial.println(uxHighWaterMark);
    Serial.println("---");
    xSemaphoreGive(xSerial_semaphore);
  }
}
void modbusFunc( void * parametros) {

  (void) parametros;
  float temperatura_rcv = 0.0;
  int torrando_rcv = 0;
  UBaseType_t uxHighWaterMark;

  for (;;) {
    /* Espera até algo ser recebido na queue */
    xQueueReceive(xQueue_Modbus_temperatura, (void *)&temperatura_rcv, portMAX_DELAY);
    xQueueReceive(xQueue_Modbus_torrando, (void *)&torrando_rcv, portMAX_DELAY);

    mb.task();
    mb.Ireg(2, torrando_rcv);
    mb.Ireg(3, temperatura_rcv * 100); //Dando valor da temperatura para o para o Input register com o endereço 3
    vTaskDelay(300 / portTICK_PERIOD_MS);

    xSemaphoreTake(xSerial_semaphore, portMAX_DELAY );

    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("task_lcd high water mark (words): ");
    Serial.println(uxHighWaterMark);
    Serial.println("---");
    xSemaphoreGive(xSerial_semaphore);
  }
}

void firebaseFunc( void * parametros) {

  (void) parametros;
  float temperatura_rcv = 0.0;
  int torrando = 0;
  UBaseType_t uxHighWaterMark;

  for (;;) {
    if (Firebase.getBool("/torrando")) {
      torrando = 1;
      xQueueOverwrite(xQueue_Modbus_torrando, (void *)&torrando);
    } else {
      torrando = 0;
      xQueueOverwrite(xQueue_Modbus_torrando, (void *)&torrando);

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

    xQueueReceive(xQueue_Firebase, (void *)&temperatura_rcv, portMAX_DELAY);
    Firebase.setFloat("/temperatura", temperatura_rcv);
  }
}
