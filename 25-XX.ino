#include <SPI.h>

#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13

uint8_t read_L_StatusRegister() 
{
  uint8_t result = 0x00;

  digitalWrite(MOSI_PIN, 0);
  digitalWrite(SCK_PIN, 0);
}

void setup() 
{  
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);

  Serial.begin(9600);
  
  SPI.begin();
  SPI.transfer(0x05);
  data = SPI.transfer(0);
  Serial.println(data, HEX);
}

void loop() 
{

}
