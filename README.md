![Image alt](https://github.com/S-Sushka/ARDUINO_24XX08/blob/main/sheme.png)

## What`s going here?
### Include Wire.h and set chip address:
```cpp
#include <Wire.h>
#define EEPROM_ADDRESS 0x50
```
### Write byte to EEPROM:
```cpp
void writeToEEPROM(uint8_t data, uint8_t address) 
{
  Wire.beginTransmission(EEPROM_ADDRESS);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}
```
### Read byte from EEPROM:
```cpp
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
```
