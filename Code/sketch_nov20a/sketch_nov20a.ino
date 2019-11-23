#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID         "input here"         // ชื่อ Wifi  
#define WIFI_PASSWORD     "input here"         // รหัสผ่าน Wifi
#define FIREBASE_HOST     "input here"         // URL Firebase
#define FIREBASE_AUTH     "input here"         // Key ลับของ Firebase

#define ledPin D0

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  String ledStatus = Firebase.getString("ledStatus");
  
  if(ledStatus == "1"){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(ledStatus);
  
  //set data:
  //Firebase.setInt("ledStatus", 1);
}
