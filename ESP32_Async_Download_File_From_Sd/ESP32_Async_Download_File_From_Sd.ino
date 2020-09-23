#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "FS.h"
#include <SD.h>
#include <SPI.h>
  
const char* ssid = "CompEng";
const char* password = "h98a2k3?12.";

AsyncWebServer server(80);
  
void setup(){
  Serial.begin(115200);
  
  // Initialize SD card
  
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");

  }
  
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");

  }


  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  if (SD.exists("/data.csv")) {
    Serial.println("Dosya var gardas!");
  }
  
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println(WiFi.localIP());
 
  server.on("/download", HTTP_GET, [](AsyncWebServerRequest *request){
    // istek atildiginda ESP32 modulunuz SD karttaki dosyayi gonderemiyorsa
    // SD karti sonlandirip baslatin
    // eger problem yoksa yapmaya gerek yok
    SD.end();
    SD.begin();
    request->send(SD, "/data.csv", "text/csv", true);
  });
   
  
  server.begin();
}
  
void loop(){
}
