# SmartFactory_MQTTCommunication

The SmartFactroy_MQTTCommunication is an modular part of the SmartFactory Project.  
It establishes a WLAN-Communication with an MQTT-Broker and allows you to send and receive Messages.

## Hardware
This Code needs a WLAN-Shield to function properly.  
It's tested with an [Adafruit Feather M0 WiFi - ATSAMD21 + ATWINC1500](https://www.adafruit.com/product/3010) from Adafruit.

## Tools and Technologies

The Source-code is written in C++ with the help of the following tools;

### Doxygen
Doxygen is used for the documentation of the sourcecode 
An intorduction to *Doxygen* and how to install it can be found [here](https://github.com/LMazzole/ArdFSM#howto-use-doxygen-in-vscode).  
### VSCode PlatformIO
The used  IDE is [VSCode](https://code.visualstudio.com/) with the [PlatformIO](https://platformio.org/platformio-ide)-Extension.

### MQTT
MQTT (Message Queuing Telemetry Transport) is an lightweight  publish-subscribe messaging   protocol and requires a broker to relay the messages. It's used for M2M (machine-to-machine) communication. 
An MQTT-System always consist of a broker and one or multiple clients, which can be either subscriber or publisher. A Client can subscribe and publish to one or multiple Topics. Topics are organized in a Tree similar to a Folder-structure in Windows. For more Infos about MQTT and MQTT-Topics check out the MQTT-Wiki on [Github](https://github.com/mqtt/mqtt.github.io/wiki).

[Source: [Wiki:MQTT](https://en.wikipedia.org/wiki/MQTT), [MQTT](https://mqtt.org/) ]

<div style="page-break-after: always;"></div>

## Using SmartFactory_MQTTCommunication
MQTTCommunication establishes a WLAN-Connection and allows you to connect  
with an MQTT-Broker to send and receive Message.  
Incomming Messages need to be in an kown JSON-Format and  will be convertet into a Struct.  
These Structs are stored in an Circular-Buffer (Ring-Buffer).

### Important Functions and Files
All functions and files are Documented on the [GitHub-Page](https://lmazzole.github.io/SmartFactory_MQTTCommunication/)
#### MQTTCommunication.h  
The *MQTTCommunication.h*-File serves as Interface.
It provides the functions for:
* Network-Connection
* MQTT-Functionalities
* access the Message-Storage

#### CommunicationConfiguration.h
In the *CommunicationConfiguration.h*-File are alle important things defined:
* WLAN SSID
* WLAN password
* WLAN Shield pins
* MQTT Broker IP
* JSON parse size
* Cirrcular Buffer size

### myJSONStr.h
In the *myJSONStr.h*-File is defined how the JSON-Message and hence the struct looks like.

This is how the JSON-Message (received as String) can look like:
``` javascript
{
  "id": "hostname",
  "topic": "topic/topic",
  "status": "driving",
  "sector": "transit",
  "line": 1,
  "ack":"hostname",
  "req":"hostname",
  "cargo":"beer",
  "token":false;
  "error":false
}
```
And the corresponding Struct in which the message gets parsed:
``` cpp
struct myJSONStr {
    String id = "hostname";
    String topic = "topic/topic";
    String status = "driving";
    String sector = "transit";
    int line = 1;
    String ack = "hostname";
    String req = "hostname";
    String cargo = "beer";
    bool token = false;
    bool error = false;
};
```
<div style="page-break-after: always;"></div>

### FAQ's
I'd like to use this code in my project. What do I need to know?
> All you need to do is at the GitHub-Link to this Repo under *lib_deps* in your platformio.ini File and your good to go.

Where can I change the configurations like MQTT-Broker IP and WLAN-Credentials?  
> All the Configurationdata are stored in the *CommunicationConfiguration.h* file and can be edited there.

I'd like to change the incomming  JSON-Message. How can I do that?  
> Incoming Messages need to be in an know JSON-Format which is defined in* myJSONStr.h* and needs to match the implementation in *myJSON::parsingJSONToStruct*. If you would like to change this Format you need to adapt both files.

### Dependencies
* [PubSubClient](https://pubsubclient.knolleary.net/)
* [WiFi101](https://www.arduino.cc/en/Reference/WiFi101)
* [ArduinoJson](https://arduinojson.org/)
* [CircularBuffer](https://github.com/rlogiacco/CircularBuffer)

### ToDo's
The open ToDo's can be fund in the Documenation on the [GitHub-Page](https://lmazzole.github.io/SmartFactory_MQTTCommunication/todo.html)

### Contributors
[Luca Mazzoleni](https://github.com/LMazzole)

### Changelog
V 1.0	-	Release BA FS19	-	[Luca Mazzoleni](https://github.com/LMazzole)

## License

[TODO]
