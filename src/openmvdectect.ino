#include <ArduinoJson.h>

volatile int cx;
volatile int cy;
volatile char c;
String json;

void setup(){
  cx = 0;
  cy = 0;
  c = 0;
  json = "";
  Serial.begin(115200);
}

void loop(){
  if (Serial.available() > 0) {
    c = char(Serial.read());
    json = String(json) + String(c);
    if (c == '}') {
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(json);
      if (!root.success()) {
        Serial.println("JSON failed!");
      }
      int cx = root["cx"];
      int cy = root["cy"];
      Serial.print("cx = ");
      Serial.print(cx);
      Serial.print('\t');
      Serial.print("cy = ");
      Serial.println(cy);
      json = "";
    }
  }
}
