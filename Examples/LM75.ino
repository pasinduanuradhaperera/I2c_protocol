#include <Wire.h>

#define LM75_ADDR 0x48      // LM75 I2C address
#define TEMP_REG 0x00       // Temperature register

void setup() {
  // Initialize communication and serial monitor
  Wire.begin();
  Serial.begin(9600);
  
  Serial.println("LM75 Temperature Sensor Initialized");
}

void loop() {
  // Request 2 bytes from the LM75 temperature register
  Wire.beginTransmission(LM75_ADDR);
  Wire.write(TEMP_REG);   // Set register pointer to temperature register
  Wire.endTransmission();
  
  // Request 2 bytes from the sensor
  Wire.requestFrom(LM75_ADDR, 2);
  
  if (Wire.available() == 2) {
    // Read the temperature data
    uint8_t msb = Wire.read();  // Most Significant Byte
    uint8_t lsb = Wire.read();  // Least Significant Byte

    // Combine the bytes into a 16-bit value
    int16_t tempRaw = (msb << 8) | lsb;

    // Convert the raw value to temperature in degrees Celsius
    float temperature = tempRaw / 256.0;

    // Print the temperature value
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }
  
  delay(1000);  // Wait for 1 second before reading again
}
