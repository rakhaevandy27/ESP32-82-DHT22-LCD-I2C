//LIBRARY
#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

//DHT SETUP
DHTesp dht;

//LCD SETUP
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  //SERIAL INIT
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");

  //LCD INIT
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();

  //LED INDICATOR
  pinMode(BUILTIN_LED, OUTPUT);
  
  //PIN FOR DHT22
  dht.setup(14, DHTesp::DHT22); // Connect DHT sensor to GPIO 5
}

void loop()
{
  
  delay(2000);
  digitalWrite(BUILTIN_LED, LOW);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  
  //SERIAL OUT
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.println(temperature, 1);
  
  //LCD OUT
  lcd.setCursor(0,0);
  lcd.print("Temp  : ");
  lcd.print(temperature);
  lcd.print(" C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid : ");
  lcd.print(humidity);
  lcd.print(" %");
  
  //INDICATOR
  digitalWrite(BUILTIN_LED, HIGH);
  

}
