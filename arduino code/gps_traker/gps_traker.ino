#define BLYNK_TEMPLATE_ID "TMPL6Ke3Zh9FU"
#define BLYNK_TEMPLATE_NAME "NodeMCU GPS"
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Auth Token from Blynk app
char auth[] = "bvCzPMQtHb-kf8eikZ8sVtwwpRj8e37i";

// Define the software serial pins for GPS module
SoftwareSerial gpsSerial(4, 5); // RX, TX

// Create a TinyGPS++ object
TinyGPSPlus gps;

void setup() {
  // Debug console
  Serial.begin(9600);
  
  // Initialize the GPS serial port
  gpsSerial.begin(9600);
  
  // Connect to Blynk
  Blynk.begin(auth, "uiu", "12345678");
}

void loop() {
  // Read data from GPS module
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        // Latitude and Longitude in degrees
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();
        
        // Print latitude and longitude to Serial Monitor
        Serial.print("Latitude: ");
        Serial.println(latitude, 6); // Print with 6 decimal places
        Serial.print("Longitude: ");
        Serial.println(longitude, 6); // Print with 6 decimal places
        
        // Send latitude and longitude to Blynk GPS widget
        Blynk.virtualWrite(V11, latitude, longitude);
      }
    }
  }
  
  // Run the Blynk service
  Blynk.run();
}