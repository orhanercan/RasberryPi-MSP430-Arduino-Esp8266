#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SPI.h>
#include <MFRC522.h>
#include <DHT.h>

const char* ssid = "SUPERONLINE_Wi-Fi";
const char* password = "123456789";

ESP8266WebServer server(80);

#define SS_PIN D2
#define RST_PIN D1
#define DHTPIN D4
#define DHTTYPE DHT11

MFRC522 mfrc522(SS_PIN, RST_PIN);
DHT dht(DHTPIN, DHTTYPE);

String rfidUID = "none";
float temperature = 0;
float humidity = 0;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) delay(500);
    Serial.println("IP: " + WiFi.localIP().toString());

    SPI.begin();
    mfrc522.PCD_Init();
    dht.begin();

    server.on("/data", HTTP_GET, []() {
        String json = "{";
        json += "\"temperature\":" + String(temperature) + ",";
        json += "\"humidity\":" + String(humidity) + ",";
        json += "\"rfid\":\"" + rfidUID + "\"";
        json += "}";
        server.send(200, "application/json", json);
        rfidUID = "none"; // Sıfırla
    });
   
    server.begin();
}

void loop() {
    server.handleClient();
   
    // Sensör Verilerini Oku
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();
   
    if (!isnan(hum) && !isnan(temp)) {
        humidity = hum;
        temperature = temp;
    }
   
    // RFID Okuma
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        rfidUID = "";
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            rfidUID += String(mfrc522.uid.uidByte[i], HEX) + " ";
        }
        rfidUID.trim();
        rfidUID.toLowerCase();
        mfrc522.PICC_HaltA();
    }
   
    delay(1000);
}
