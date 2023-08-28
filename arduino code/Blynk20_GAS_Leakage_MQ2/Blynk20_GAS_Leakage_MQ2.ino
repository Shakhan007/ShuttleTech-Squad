
//Change Blynk Authenticaation Details
#define BLYNK_TEMPLATE_ID "TMPL6hkIaOthT"
#define BLYNK_TEMPLATE_NAME "Gas Detection Alert"
#define BLYNK_AUTH_TOKEN "jhKH8nnQrVoNi8AC8AE9LfqbONlZwq99"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "GalaxyM317DAA";  // Enter your wifi name
char pass[] = "00001111";  // Enter your wifi password
int smokeA0 = A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 600)     // Change the Trashold value
  {
    // Replace your Blynk.email line with this
// Blynk.notify("Gas Leakage Detected!");

    Blynk.logEvent("gas_alert","Gas Leakage Detected");
    delay(5000);
    data = data-300;
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
