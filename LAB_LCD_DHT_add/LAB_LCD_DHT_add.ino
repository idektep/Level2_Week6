#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27 or 0x3F >> (GREEN)

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();  //เปิดไฟ backlight
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("x");
  delay(1000);
  lcd.setCursor(1, 0);
  lcd.print("x");
  delay(1000);
  lcd.setCursor(2, 0);
  lcd.print("x");
  delay(1000);
  lcd.setCursor(3, 0);
  lcd.print("x");
  delay(1000);
}
