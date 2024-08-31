#include <WiFi.h>
#include "time.h"

const char WIFI_SSID[] = "YOUR_SSID";    // TODO change
const char WIFI_PASSWORD[] = "YOUR_PASSWORD";    // TODO change

const char NTP_SERVER[] = "pool.ntp.org";
const long  GMT_OFFSET_SEC = 3600;
const int DAYLIGHT_OFFSET_SEC = 3600;


void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
}

void loop() {
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  }
  delay(1000);
}