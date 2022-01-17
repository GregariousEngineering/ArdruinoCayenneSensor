#define CAYENNE_DEBUG       // Comment to disable debug messages
#define CAYENNE_PRINT Serial  // Comment to disable info

#include <WiFiNINA.h> // Compile fails if this is after CayenneMQTTWiFi...?
#include <CayenneMQTTWiFi.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#include <SimpleTimer.h> // https://playground.arduino.cc/Code/SimpleTimer/

const int DS18B20_PIN = 13; // Arduino pin connected to DS18B20 sensor's DQ pin

// WiFi network info.
const char ssid[] = "YOUR SSID";
const char wifiPassword[] = "YOUR WIFI PASS";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
const char username[] = "YOUR DEVICES USERNAME";
const char password[] = "YOUR DEVICES PASSWORD";
const char clientID[] = "YOUR DEVICES CLIENTID";

SimpleTimer timer;

OneWire oneWireDS18B20(DS18B20_PIN); // Setup a oneWire instance
DallasTemperature waterTempSensor(&oneWireDS18B20); // Pass oneWire to DallasTemperature library (DS18B20)

void setup() {
  Serial.begin(9600); // Initialize serial for console logging
  while (!Serial) ; // Wait for serial port to connect. Needed for native USB port only

  Serial.println(F("DS18B20 Cayenne Example")); Serial.println();

  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, wifiPassword) != WL_CONNECTED) {
    Serial.print(".");
    delay(5000);
  }

  Serial.println(); Serial.println("You're connected to the network"); Serial.println();
  
  Serial.println(F("Attempting to begin Cayenne client"));
  Cayenne.begin(username, password, clientID);
  
  Serial.println(F("Cayenne init complete.")); Serial.println();

  Serial.println(F("Beginning DS18B20..."));
  waterTempSensor.begin(); // Start DS18B20

  Serial.println(F("DS18B20 started. Setting timer to report sensor data."));
  timer.setInterval(28000L, sendUpdate); // Set timer to send update every 28s (plus 2s processing)

  Serial.println(); Serial.println("setup() Complete!");
}

void loop() {
  Cayenne.loop(); // Used for processing callbacks from Cayenne, e.g. Actuators
  timer.run();
}

void sendUpdate() {
  Serial.print(F("Water Temp(DS18B20):"));
  waterTempSensor.requestTemperatures(); // Get temp
  float tempFahrenheit = waterTempSensor.getTempCByIndex(0) * 9.0 / 5.0 + 32.0;
  Serial.print(tempFahrenheit, 2);  
  Serial.println();
  
  Cayenne.virtualWrite(0, tempFahrenheit);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT() {
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
