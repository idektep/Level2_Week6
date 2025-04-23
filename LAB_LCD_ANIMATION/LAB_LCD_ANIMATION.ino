#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27 และจอ 16x2

byte rocket[8] = {
  B00001,
  B00011,
  B10111,
  B11111,
  B10111,
  B00011,
  B00001,
  B00000
};

byte dino[8] = {
  B00100,
  B01110,
  B10101,
  B11111,
  B01110,
  B01100,
  B11100,
  B10000
};

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, rocket);  // สร้างจรวดไว้ที่ช่อง 0
  lcd.createChar(1, dino);    // สร้างไดโนเสาร์ไว้ที่ช่อง 1

  lcd.setCursor(5, 0);        // เคอร์เซอร์แถวบน คอลัมน์ 5
  lcd.write(byte(0));         // แสดงจรวด

  lcd.setCursor(9, 0);        // เคอร์เซอร์แถวบน คอลัมน์ 9
  lcd.write(byte(1));         // แสดงไดโนเสาร์
}

void loop() {
   for (int i = 0; i <= 14; i++) {  // 14 = เหลือช่องไว้สำหรับอีก 1 ตัว (2 รูปต้องมีพื้นที่)
    lcd.clear();

    lcd.setCursor(i, 0);      // วางจรวด
    lcd.write(byte(0));

    lcd.setCursor(i + 1, 0);  // วางไดโนเสาร์ข้างหลัง
    lcd.write(byte(1));

    delay(300);
   }
   for (int i = 0; i <= 14; i++) {  // 14 = เหลือช่องไว้สำหรับอีก 1 ตัว (2 รูปต้องมีพื้นที่)
    lcd.clear();

    lcd.setCursor(i, 1);      // วางจรวด
    lcd.write(byte(0));

    lcd.setCursor(i, 0);  // วางไดโนเสาร์ข้างหลัง
    lcd.write(byte(1));

    delay(300);
   }
}
