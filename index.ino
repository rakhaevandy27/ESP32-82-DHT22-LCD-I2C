#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

DHTesp dht;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");

  //lcd init
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();

  //led indicator
  pinMode(BUILTIN_LED, OUTPUT);

  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);
  // use this instead: 
  dht.setup(14, DHTesp::DHT22); // Connect DHT sensor to GPIO 5
}

void loop()
{
  
  delay(2000);
  digitalWrite(BUILTIN_LED, LOW);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.println(temperature, 1);

  lcd.setCursor(0,0);
  lcd.print("Temp  : ");
  lcd.print(temperature);
  lcd.print(" C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid : ");
  lcd.print(humidity);
  lcd.print(" RH");
  digitalWrite(BUILTIN_LED, HIGH);
  

}