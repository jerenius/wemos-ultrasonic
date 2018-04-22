#include <ESP8266WiFi.h>

const char* ssid = "myssid";
const char* password = "myverysecretkey";

const int trigPin = 4;
const int echoPin = 5;
const int greenLed = 12;
const int redLed = 14;

long duration;
int distance;
/*
Wemos Pins and corresponding GPIO
D0   = 16;
D1   = 5;
D2   = 4;
D3   = 0;
D4   = 2;
D5   = 14;
D6   = 12;
D7   = 13;
D8   = 15;
D9   = 3;
D10  = 1;
*/

void setup(void){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

 // WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  digitalWrite(greenLed, 1);
  digitalWrite(redLed, 0);
 }

void loop(void){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

f (distance < 10) {
  digitalWrite(greenLed, 0);
  digitalWrite(redLed, 1);
} else {
  digitalWrite(greenLed, 1);
  digitalWrite(redLed, 0);
}
}
