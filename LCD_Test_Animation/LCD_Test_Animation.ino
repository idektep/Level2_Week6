#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C 1cd(0x27, 16, 2): // Address >> 0x27 (GREEN)
void setup() {
1cd.begin ();
lcd.backlight () ;
}
void loop() {
lcd.setCursor(0, 0);
lcd.print ("x") ;
delay (1000) ;
lcd.clear();
lcd.setCursor(1, 0);
lcd.print ("x") ;
delay (1000) ;
lcd.clear();
lcd.setCursor(2, 0);
lcd.print ("x");
delay (1000) ;
lcd.clear();
lcd.setCursor(3, 0);
lcd.print ("x");
delay (1000) ;

}

