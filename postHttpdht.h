#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpdht() {
  Serial.println("Posting suhu udara Data...");
  String url = "http://192.168.43.83:8080/dht/add";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["suhu"] = String(suhu_udaraDataString.toFloat());
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  String data = "suhu=" + String(suhu_udaraDataString.toFloat());
  Serial.println(data);


  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int statusCode = http.POST(data);
  response = http.getString();
  Serial.println(response);
}
