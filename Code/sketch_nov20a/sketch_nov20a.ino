#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "" // YOU SSID
#define WIFI_PASSWORD "" // YOU PASSWORD

#define FIREBASE_HOST "" // YOU HOST KEY
#define FIREBASE_KEY "" // YOU FIREBASE KEY

#define ledPin D0

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    Serial.println(WiFi.localIP());
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_KEY);
}

void loop() {
    FirebaseData FB_DATA;

    Serial.println("=========");
    if(Firebase.getString(FB_DATA, "/Bed Room/LED")) {
      if (FB_DATA.stringData() == "1"){
        Serial.println("LED IS ON !");
        digitalWrite(ledPin, HIGH);
      } else {
        Serial.println("LED IS OFF !");
        digitalWrite(ledPin, LOW);
      }
    }
}
