#define LED 8
#define buzzer 11
#define sensorAnalog A1

int thresholdValue = 800;  // Adjust this threshold value as needed

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(sensorAnalog);

  Serial.print("Analog value: ");
  Serial.println(analogValue);

  // Map the analog reading to LED intensity
  int ledIntensity = map(analogValue, 0, 1023, 0, 255);
  analogWrite(LED, ledIntensity);

  // Determine buzzer state based on analog value
  if (analogValue > thresholdValue) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);

  }
  
  delay(100); // Add a delay for stability
}
