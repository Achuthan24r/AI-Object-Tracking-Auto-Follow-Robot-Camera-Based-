#include "esp_camera.h"
#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";

void startCameraServer();

void setup() {
  Serial.begin(115200);

  camera_config_t config;
  config.frame_size = FRAMESIZE_QVGA;
  config.pixel_format = PIXFORMAT_JPEG;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  esp_camera_init(&config);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());
  startCameraServer();
}

void loop() {
}
