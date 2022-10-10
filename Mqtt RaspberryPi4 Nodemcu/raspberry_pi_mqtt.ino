#include <ESP8266WiFi.h> 
#include <PubSubClient.h> 
 

// WiFi
// Make sure to update this for your own WiFi network!
const char* ssid = "ACER 7421"; // enter your WiFi SSID
const char* wifi_password = "Y6123333"; // enter your WiFi password
 
// Make sure to update this for your own MQTT Broker!
const char* mqtt_server = "IP Adress of Raspberry Pi";
const char* mqtt_topic = "testTopic"; //any topic name of your choice
const char* mqtt_username = "hactao"; //type your mosquitto mqtt username
const char* mqtt_password = "velglarn1"; //type your mosquitto mqtt password
// The client id identifies the NodeMCU
const char* clientID = "ID"; // any name that identifies the client
 
 
// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;
PubSubClient client(mqtt_server, 1883, wifiClient); // 1883 is the listener port for the Broker
 

void setup() {
  
 
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Connect to the WiFi
  WiFi.begin(ssid, wifi_password);
  // Wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  // Debugging - Output the IP Address of the NodeMCU
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
   client.setServer("192.168.137.4", 1883); // type your Raspberyry Pi IP address
  // Connect to MQTT Broker
  // client.connect returns a boolean value to let us know if the connection was successful.
  // If the connection is failing, make sure you are using the correct MQTT Username and Password
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker!");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }
}
 
void loop() {
           
    client.connect(clientID, mqtt_username, mqtt_password); //connects to the broker
    //delay(10); // This delay ensures that client.publish doesn't clash with the client.connect call
    //client.publish("testTopic",(const uint8_t*)buf,4);
    client.publish("testTopic","Orhan ERCAN Hello from Nodemcu(esp8266)");
    client.subscribe("testTopic");
    delay(2000); //delay between each message
    
    
}
