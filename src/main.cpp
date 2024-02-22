#include <Arduino.h>
#include <DHT.h>

// DHT11 sensor pin and type
#define DHTPIN A1  // Change to the actual GPIO pin the DHT11 sensor is connected to
#define DHTTYPE DHT11  // The type of DHT sensor in use

DHT dht(DHTPIN, DHTTYPE);

// Soil Moisture Sensor pin
#define SOIL_MOISTURE_PIN A2  // Change to the actual analog pin the soil moisture sensor is connected to

void setup() {
  Serial.begin(9600); // Start serial communication
  dht.begin(); // Initialize the DHT11 sensor
  pinMode(SOIL_MOISTURE_PIN, INPUT); // Set the soil moisture sensor pin to input mode
}

void loop() {
  // Reading temperature and humidity from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Checking if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Reading moisture value from the soil moisture sensor
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  // You can convert the analog value to a percentage, assuming you know the range of your sensor
  // int soilMoisturePercent = map(soilMoistureValue, dryValue, wetValue, 0, 100);

  // Printing the read data to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);
  // Uncomment below line if you've converted to percentage
  // Serial.print("Soil Moisture Percent: ");
  // Serial.println(soilMoisturePercent);

  delay(2000); // Wait for 2 seconds before reading again
}
