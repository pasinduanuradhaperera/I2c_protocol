#include <DHT.h>

#define DHTPIN 2            // Pin where the DHT sensor is connected
#define DHTTYPE DHT11       // Define the type of sensor (DHT11 or DHT22)

// Create a DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize the DHT sensor
  Serial.begin(9600);
  dht.begin();
  
  Serial.println("DHT Sensor Initialized");
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);
  
  // Read humidity (percent)
  float humidity = dht.readHumidity();
  
  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
