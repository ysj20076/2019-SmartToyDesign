#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int a = analogRead(A1);
  Serial.println(a);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(a);
}
