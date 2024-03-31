#include <Wire.h>

#define EEPROM_ADDRESS 0x50

void writeToEEPROM(uint8_t data, uint8_t address) 
{
  Wire.beginTransmission(EEPROM_ADDRESS);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t readFromEEPROM(uint8_t address) 
{
  uint8_t dataBuffer = 0;
  
  Wire.beginTransmission(EEPROM_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(EEPROM_ADDRESS, 1);
  dataBuffer = Wire.read();
  Wire.endTransmission();

  return dataBuffer;
}


void setup() 
{  
  Wire.begin();

  pinMode(A4, OUTPUT);
  digitalWrite(A4, 1);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, 1);
}

void loop() 
{

}
