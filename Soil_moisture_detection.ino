// Soil Moisture Sensor + Relay Control

#define SOIL_PIN A0      // Analog pin connected to soil sensor A0
#define RELAY_PIN 7      // Digital pin connected to relay IN

int soilValue = 0;       // To store analog moisture value
int threshold = 650;     // Adjust this value based on your sensor calibration

void setup() {
  Serial.begin(9600);
  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Turn relay OFF initially (HIGH = off for most modules)

  Serial.println("Soil Moisture Detection System Started...");
}

void loop() {
  soilValue = analogRead(SOIL_PIN); // Read analog value from sensor
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilValue);

  // If soil is dry (value is high) => turn ON relay (pump ON)
  if (soilValue > threshold) {
    Serial.println("Soil is Dry! Pump ON");
    digitalWrite(RELAY_PIN, LOW);  // Relay ON (active LOW)
  } 
  else {
    Serial.println("Soil is Moist! Pump OFF");
    digitalWrite(RELAY_PIN, HIGH); // Relay OFF
  }

  delay(1000); // Read every 1 second
}
