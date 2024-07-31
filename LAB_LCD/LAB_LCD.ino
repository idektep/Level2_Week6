#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 or 0x3F

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();  //เปิดไฟ backlight
  lcd.setCursor(1, 0);
  lcd.print("Idektep Cobot");
  lcd.setCursor(3, 1);
  lcd.print("Name");
}

void loop() {
  // put your main code here, to run repeatedly:
}
