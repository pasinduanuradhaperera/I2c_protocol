#include <Wire.h>
#include <MPU6050.h>

// Create an MPU6050 object
MPU6050 mpu;

void setup() {
  // Initialize communication and serial monitor
  Wire.begin();
  Serial.begin(9600);
  
  // Initialize MPU6050
  Serial.println("Initializing MPU6050...");
  if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("Could not find MPU6050 sensor!");
    while (1);
  }
  
  // Calibrate gyro and accelerometer
  mpu.calibrateGyro();
  mpu.setThreshold(3);
  
  Serial.println("MPU6050 Initialized");
}

void loop() {
  // Read accelerometer and gyroscope data
  Vector rawAccel = mpu.readRawAccel();
  Vector rawGyro = mpu.readRawGyro();
  
  // Print Accelerometer data
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(rawAccel.XAxis);
  Serial.print(" | Y = "); Serial.print(rawAccel.YAxis);
  Serial.print(" | Z = "); Serial.println(rawAccel.ZAxis);
  
  // Print Gyroscope data
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(rawGyro.XAxis);
  Serial.print(" | Y = "); Serial.print(rawGyro.YAxis);
  Serial.print(" | Z = "); Serial.println(rawGyro.ZAxis);
  
  delay(500);  // Wait for 500 ms before reading again
}
