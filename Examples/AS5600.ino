#include <Wire.h>

#define AS5600_ADDR 0x36      // AS5600 I2C address
#define RAW_ANGLE_REG 0x0C    // Register to read raw angle

void setup() {
  // Initialize communication and serial monitor
  Wire.begin();
  Serial.begin(9600);
  
  Serial.println("AS5600 Magnetic Encoder Initialized");
}

void loop() {
  // Request 2 bytes of data from the AS5600 to get the raw angle
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(RAW_ANGLE_REG);  // Set register pointer to raw angle register
  Wire.endTransmission();
  
  // Request 2 bytes from the encoder (since raw angle is a 12-bit value)
  Wire.requestFrom(AS5600_ADDR, 2);
  
  if (Wire.available() == 2) {
    uint8_t highByte = Wire.read();  // High byte of the angle data
    uint8_t lowByte = Wire.read();   // Low byte of the angle data

    // Combine high and low bytes into a 12-bit angle value
    int rawAngle = ((highByte << 8) | lowByte) & 0x0FFF;
    
    // Print the raw angle value (ranges from 0 to 4095 for a full rotation)
    Serial.print("Raw Angle: ");
    Serial.println(rawAngle);
    
    // Convert the raw angle to degrees (0 to 360 degrees)
    float angleInDegrees = (rawAngle * 360.0) / 4096.0;
    Serial.print("Angle in Degrees: ");
    Serial.println(angleInDegrees);
  }
  
  delay(500);  // Wait for 500 ms before reading again
}
