#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 23  //pin DHT 23
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 or 0x3F

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  lcd.begin();
  lcd.backlight();  //เปิดไฟ backlight
  lcd.setCursor(1, 0);
  lcd.print("Idektep Cobot");
  lcd.setCursor(3, 1);
  lcd.print("Name");
  delay(500);
  lcd.clear();
}

void loop() {
    // put your main code here, to run repeatedly:
  ////// รับค่า  Sensor DHT
  float humi = dht.readHumidity();     //รับค่าความชื้น
  float temp = dht.readTemperature();  //รับค่าอุณหภูมิ
  Serial.print("Humidity: ");
  Serial.println(humi);
  Serial.print("temp: ");
  Serial.println(temp);

  lcd.setCursor(0, 0);
  lcd.print("Temp :" + String(temp, 1) + "c");
  lcd.setCursor(1, 0);
  lcd.print("Humi :" + String(humi, 1) + "%");
  delay(500);
}
