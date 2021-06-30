// Sample code to upload and read data
// temp, soil moisture, random val
// ESP8266 board

#include <ThingSpeak.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(D5);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensor(&oneWire);

// Load Wi-Fi library
#include <ESP8266WiFi.h>
WiFiClient client;

const char* ssid     = "network";
const char* password = "pass";

const char* writeAPIKey = "key";
unsigned long channelNumber = channelnum;

void connectToWiFi() {
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection...");
  }
  
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

// get random number
int getRandom() {
  return random(1000);
}

// read temperature from sensor
float readTemp() {
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0);
}

// read moisture (aka 'hum' 'humidity' etc. I wasnt consistent with names across this program, and read example program)
int readMoisture() {
  int sensorVal = analogRead(A0);
  int percentageHumidity = map(sensorVal, 310, 570, 100, 0); 

  return percentageHumidity;
}

void post() {
  connectToWiFi();

  // read and log into serial monitor
  float temp = readTemp();
  Serial.print("Temperature is: ");
  Serial.print(temp);
  Serial.println();
  
  int randNum = getRandom();
  
  int hum = readMoisture();
  Serial.print("Soil moisture is: ");
  Serial.print(hum);
  Serial.print(" %");
  Serial.println();

  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, randNum);
  ThingSpeak.setField(3, hum);
  ThingSpeak.writeFields(channelNumber, writeAPIKey);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ThingSpeak.begin(client);
  Serial.println();
  Serial.println("Program started...");
}

void loop() {
  // put your main code here, to run repeatedly:
  post();
  
  delay(15000);
}
