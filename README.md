Ardruino Uno Wifi Rev2 Cayenne Sensor Example
========================================
<img src="https://github.com/GregariousEngineering/UnoWifiRev2CayenneSensor/blob/master/images/UnoWifiRev2.png">

A simple Ardruino class demonstrating Cayenne on Ardruino Uno Wifi Rev2 (since myDevices/Cayenne have no sample for this board). 

Acknowledgements
----------------
* **Based on the the following
   * **["Sending Data of MQTT" Ardruino Turorial](https://docs.arduino.cc/tutorials/uno-wifi-rev2/uno-wifi-r2-mqtt-device-to-device)**
   * **[Cayenne WifiShield Connection Example](https://github.com/myDevicesIoT/Cayenne-MQTT-Arduino/blob/master/examples/Connections/WiFiShield/WiFiShield.ino)**
   * **[ArdruinoGettingStarted Temperature Sesnor](https://arduinogetstarted.com/tutorials/arduino-temperature-sensor)**

Repository Contents
-------------------
* **/cayenne_temp.ino** - Example Ardruino class logs DS18B20 temperature probe (or any compatible Dallas Probe; assumed to be on Digital IO 13) to Cayenne (channel 0).

Requirements/Assumptions
--------------
* **Requires Cayenne Account** - Setup a free account and add new device (which will give required username/password/clientID)
   * **[Cayenne Ardruino](https://developers.mydevices.com/cayenne/landing/jumpstart-arduino-projects-cayenne/)
* **Ardruino libraries** - Available through "Manage Libraries" in Ardruino IDE and GitHub
   * **WiFiNINA.h** - Required for Wifi as Cayenne doesn't support Uno Wifi Rev2
   * **CayenneMQTTWiFi.h** - Provides Cayenne client
   * **OneWire.h/DallasTemperature.h** - Simplifies reading temp sensor
   * **[SimpleTimer](https://playground.arduino.cc/Code/SimpleTimer/)** - Simplifies publishing to Cayenne at interval
* **Temp Sensor Wired to Digital IO 13** - Account is required to pull current weather data (no longer accepting signups.....since bought by Apple?)
   * **[Dark Sky API](https://darksky.net/dev)

License Information
-------------------

This product is _**open source**_! Distributed as-is, _**with flaws**_; absolutely no warranty implied.

**- GregariousEngineer**

<img src="https://github.com/GregariousEngineering/UnoWifiRev2CayenneSensor/blob/master/images/AeroTempMon.jpeg">
