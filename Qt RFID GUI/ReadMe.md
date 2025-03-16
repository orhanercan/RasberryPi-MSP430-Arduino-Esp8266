# ESP8266 RFID & Environmental Monitoring System

A comprehensive IoT solution for tracking RFID-based employee attendance and monitoring environmental conditions (temperature/humidity) in real-time using ESP8266, MFRC522 RFID, and DHT11 sensor. Data is visualized through a Qt-based cross-platform GUI.

## ✨ Key Features
- **RFID Employee Recognition**  
  Supports multiple RFID tags with customizable employee mapping
- **Real-Time Environmental Monitoring**  
  Tracks temperature (°C) and humidity (%) with DHT11 sensor
- **Local Web Server**  
  Built-in HTTP server on ESP8266 (API endpoint: `/data`)
- **Cross-Platform GUI**  
  Qt 6 interface with SQLite logging and tabular display
- **Network Resilient**  
  Optional static IP configuration for stable LAN operation
![Qt Gui](https://github.com/user-attachments/assets/778b0006-5512-44d4-a4da-741481268927)
![Qt Gui3](https://github.com/user-attachments/assets/87bb5b77-c11d-49cd-abb7-fa53b1542731)
![Qt Gui2](https://github.com/user-attachments/assets/2f61124d-dd31-4aae-be3d-eab48c707253)

## 🛠 Hardware Components
- ESP8266 NodeMCU
- MFRC522 RFID Reader
- DHT11 Sensor
- RFID Cards/Tags
- Jumper Wires

## 📦 Software Stack
- **Firmware**  
  Arduino Core for ESP8266 (v3.1.2+)
- **GUI**  
  Qt 6 Framework (QTableView, QNetworkAccessManager)
- **Database**  
  SQLite3 for attendance logging
- **Communication**  
  HTTP REST API (JSON payload)

## 🚀 Getting Started
1. Flash ESP8266 with provided Arduino code
2. Configure WiFi credentials in `config.h`
3. Build Qt GUI using CMake:
   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_PREFIX_PATH="/path/to/Qt6/lib/cmake"
   cmake --build .

Update ESP IP in Qt application

Launch GUI and start monitoring!

## 🔧 Dependencies
Arduino MFRC522 Library

DHT Sensor Library

Qt 6 Core, Widgets, Network modules

## 🔒 Security Notes
Optional HTTP Basic Authentication
Local network operation only by default
Easy API key implementation available

## 🤝 Contribution
Open for PRs! Potential improvements:
Add MQTT support
Implement HTTPS encryption
Develop mobile companion app
System Architecture Example workflow diagram

## 📄 License: MIT
💡 Ideal For: Access control systems, smart office monitoring, IoT learning projects
