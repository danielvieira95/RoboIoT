// Robo IoT
// 18/06/2022
 
//-------Configurações iniciais da plataforma Blynk--------
 
#define BLYNK_PRINT Serial
 
// Insira abaixo o ID do seu template
#define BLYNK_TEMPLATE_ID "insira-aqui-o-id-do-template"
 
// Insira abaixo o seu Auth Token
char auth[] = "insira-aqui-o-auth-token";
 
// Insira abaixo o nome da sua rede WiFi
char ssid[] = "insira-aqui-o-nome-da-rede-wifi";
 
// Insira abaixo a senha da sua rede WiFi
char pass[] = "insira-aqui-a-senha-da-rede-wifi";
 
//--------Bibliotecas utilizadas no código--------
 
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Servo.h>
  
//--------Definições dos pinos--------
#define MOTORA_1     2
#define MOTORA_2     3
#define MOTORB_1     4
#define MOTORB_2     5
#define SERVO        6
#define BUZZER       7
#define RED          8
#define GREEN        9
#define BLUE         10
 
//--------Configurações iniciais do módulo ESP8266--------
#define EspSerial Serial1
#define ESP8266_BAUD 115200
ESP8266 wifi(&EspSerial);
 
//--------Configurações iniciais do servo motor--------
Servo servo;
  
//--------Setup--------
void setup(){
    
  // Inicializa a comunicação serial
  Serial.begin(115200);
  delay(5000);
 
  // Configura os pinos dos motores, buzzer e LED RGB como saídas
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
 
  // Configura o estado inicial de cada um dos pinos 
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  
  // Inicializa o servo motor
  servo.attach(SERVO);
  servo.write(90);
  delay(2000);
  servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);
  servo.write(90);
 
  // Inicializa o módulo ESP8266
  EspSerial.setPinout(0,1);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  // Inicializa o módulo ESP8266
  Blynk.begin(auth, wifi, ssid, pass);
  
  // Rotina para que indica que o robô foi ligado 
  // Faz o LED picar 5 vezes na cor vermelho e depois acende o LED na cor verde
  for (int i=0; i<5; i++){
    digitalWrite(RED,LOW);
    delay(1000);
    digitalWrite(RED,HIGH);
    delay(1000);
  }
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}
 
//--------Loop--------
void loop(){
 
  // Atualização da plataforma Blynk 
  Blynk.run();
}
  
// Rotina de controle do botão Frente
BLYNK_WRITE(V0) {
  int button = param.asInt();
  if (button == 1) {
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
  
// Rotina de controle do botão Direta
BLYNK_WRITE(V1) {
  int button = param.asInt();
  if (button == 1) {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
  
// Rotina de controle do botão Ré
BLYNK_WRITE(V2) {
  int button = param.asInt();
  if (button == 1) {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
  
// Rotina de controle do botão Esquerda
BLYNK_WRITE(V3) {
  int button = param.asInt();
  if (button == 1) {
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
  
// Rotina de controle do Buzzer
BLYNK_WRITE(V4)
{ 
  int button = param.asInt();
  if (button == 1) {
    digitalWrite(BLUE,LOW);
    tone(BUZZER, 330);
    delay(100);
    noTone(BUZZER);
    delay(100);
    tone(BUZZER, 330);
    delay(100);
    noTone(BUZZER);
    delay(100);
    tone(BUZZER, 330);
    delay(500);
    noTone(BUZZER);
    delay(100);
  }
  else {
    noTone(BUZZER);
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
  }
}
  
// Rotina de controle do servo
BLYNK_WRITE(V5)
{
 servo.write(param.asInt());
}
BLYNK_WRITE(V6)
{
 int button = param.asInt();
  if (button == 0) {
    digitalWrite(RED,LOW);
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,HIGH);
  }
  else
  {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,HIGH);
  }
}
BLYNK_WRITE(V7)
{
 int button = param.asInt();
  if (button == 0) {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,LOW);
    digitalWrite(GREEN,HIGH);
  }
  else
  {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,HIGH);
  }
}
BLYNK_WRITE(V8)
{
 int button = param.asInt();
  if (button == 0) {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,LOW);
  }
  else
  {
    digitalWrite(RED,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,HIGH);
  }
}

