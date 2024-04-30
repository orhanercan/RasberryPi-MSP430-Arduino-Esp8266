#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SPI.h>
#include <MFRC522.h>
#include "index_html.h"
#define RST_PIN D1
#define SS_PIN D2

const char* ssid = ""; // Wifi ID
const char* password = ""; // Wifi password

ESP8266WebServer server(80);
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   Serial.println(""); // Yeni bir satır başlatır
  Serial.print("Yerel IP Adresi: ");
  Serial.println(WiFi.localIP()); // Yerel IP adresini yazdırır
  server.on("/", handle_OnConnect);
  server.on("/rfid", handle_rfid);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  server.send(200, "text/html", MAIN_page);
}

void handle_rfid() {
  String rfidStatus = checkRFID();
  String clientTime = server.arg("time"); // Tarayıcıdan gelen zaman bilgisi
  server.send(200, "text/plain", rfidStatus + " " + clientTime);
}

String checkRFID() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(1000);
    return "No card detected";
  }
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
  if (strID == "59:FF:00:B9") {
    return "ÇALIŞAN1 SİSTEME GİRİŞ YAPTI ****** BÖLÜM :ELEKTRONİK ****** ";
  } else if (strID == "85:B0:6D:9E") {
    return "ÇALIŞAN2 SİSTEME GİRİŞ YAPTI ****** BÖLÜM :IT ****** ";
  } else {
    return "Bilinmeyen kart";
  }
}

// index_html.h içeriğiniz burada olacak
