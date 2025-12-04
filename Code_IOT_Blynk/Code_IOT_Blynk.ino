// Repalce below credentials for your blynk 
#define BLYNK_TEMPLATE_ID "----------------"
#define BLYNK_TEMPLATE_NAME "---------------"
#define BLYNK_AUTH_TOKEN "---------------"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "---------------";
char pass[] = "---------------";

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 23  //Add DHT pin
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 or 0x3F

#define LDR_Pin 34 //Add LDR pin
#define Buzzer_Pin 18 //Add buzzer pin
#define L_LED 16
#define R_LED 17

BlynkTimer timer;

int sw_led  = 0;
int sw_buzzer = 0;
int ldr = 0;
int LDR_value = 0;
float temp, humi;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V3) {
  sw_led = param.asInt();
}
BLYNK_WRITE(V4) {  //Add virtual pin
  sw_buzzer = param.asInt();
}
void mySensor()
{
  LDR_value = analogRead(LDR_Pin);
  ldr = map(LDR_value, 0, 4095, 0, 500);
  Serial.print("LDR_value = "); 
  Serial.println(ldr);
  Blynk.virtualWrite(V0, ldr); //Add virtual pin

  ////// รับค่า  Sensor DHT
  humi = dht.readHumidity();     //รับค่าความชื้น
  temp = dht.readTemperature();  //รับค่าอุณหภูมิ
  lcd.setCursor(0, 0);
  lcd.print("Temp :" + String(temp, 1) + "c");
  lcd.setCursor(0, 1);
  lcd.print("Humi :" + String(humi, 1) + "%");
  Blynk.virtualWrite(V1, temp); //Add virtual pin
  Blynk.virtualWrite(V2, humi); //Add virtual pin
  
  if (sw_buzzer == 1) {
    digitalWrite(Buzzer_Pin, HIGH);
  } else if (sw_buzzer == 0) {
    digitalWrite(Buzzer_Pin, LOW);
  }

  if (sw_led == 1) {
    digitalWrite(L_LED, HIGH);
    digitalWrite(R_LED, HIGH);
  } else if (sw_led == 0) {
    digitalWrite(L_LED, LOW);
    digitalWrite(R_LED, LOW);
  }

  delay(500);
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(LDR_Pin, INPUT);
  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(L_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  lcd.init();
  lcd.backlight();  //เปิดไฟ backlight
  lcd.setCursor(1, 0);
  lcd.print("Idektep Cobot");
  lcd.setCursor(3, 1);
  lcd.print("Name");
  delay(500);
  lcd.clear();
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, mySensor); 
}

void loop()
{
  Blynk.run();
  timer.run();
}