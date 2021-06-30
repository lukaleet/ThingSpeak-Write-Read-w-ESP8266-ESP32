// Sample read from Channel with alert
// Alert goes up when soil moisture is out of range
// Alert means diode blinks and then stays on until moisture goes to good level
// ESP32 based board

#include <ThingSpeak.h>

#include <WiFi.h>
WiFiClient client;

// led attached to pin 33 of the board
#define ledPin 33

const char* ssid     = "network_name";
const char* password = "password";

const char* readAPIKey = "apikey";
unsigned long channelNumber = ChannelNumberGoesHere;

void connectToWiFi() {
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection...");
  }
  
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

int readHumidity() {
  connectToWiFi();

  // humidity is being written to field '3', that's why I read field '3'
  int hum = ThingSpeak.readIntField(channelNumber, 3, readAPIKey);

  return hum;
}

bool alert(int hum) {
  if (hum >= 89 || hum <= 35) return true;

  return false;
}

void alarm() {
  digitalWrite(ledPin, HIGH);
  delay(175);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(175);
  digitalWrite(ledPin, LOW);
  delay(175);
  digitalWrite(ledPin, HIGH);
  delay(175);
  digitalWrite(ledPin, LOW);
  delay(175);
  digitalWrite(ledPin, HIGH);
  delay(175);
  digitalWrite(ledPin, LOW);
  delay(175);
  digitalWrite(ledPin, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ThingSpeak.begin(client);
  pinMode(ledPin, OUTPUT);
  Serial.println("Working...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int hum = readHumidity();
  Serial.println(hum);

  bool decision = alert(hum);

  if (decision) alarm();

  else digitalWrite(ledPin, LOW);

  delay(20000);
}
