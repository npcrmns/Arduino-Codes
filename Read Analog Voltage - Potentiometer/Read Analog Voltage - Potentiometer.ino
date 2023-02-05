#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  float angle = 300 * (voltage / 5.0);
  // print out the value you read:
  Serial.println(voltage);

  lcd.setCursor(0,0);
  lcd.print("Angle (degrees)");
  lcd.setCursor(0,1);
  lcd.print(angle);

  delay(200);
  lcd.clear();
}
