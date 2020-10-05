#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2          // what digital pin we're connected to
#define DHTTYPE DHT11     // DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float humi = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  
  if (isnan(humi) || isnan(tempC) || isnan(tempF))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  lcd.setCursor(0,0);
  lcd.print("  KLINIK BIDAN EFI  ");
  
  lcd.setCursor(0,1);
  lcd.print("Kelembaban: ");
  lcd.print(humi);
  lcd.print("%");
  
  lcd.setCursor(0,2);
  lcd.print("Suhu: ");
  lcd.print(tempC);
  lcd.print(" C");
  
  lcd.setCursor(0,3);
  lcd.print("Suhu: ");
  lcd.print(tempF);
  lcd.print(" F");
  
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(tempC);Serial.print(" *C ");
  Serial.print(tempF);Serial.println(" *F");
}
