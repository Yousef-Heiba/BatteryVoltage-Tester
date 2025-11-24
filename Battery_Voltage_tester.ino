/* 1.5V DIY Battery Tester - Written by Mr. Yousef 2024.10.25
An LCD screen is using to display the voltage of a 1.5V battery 
The positive end of the battery will be connected to A0
The negative end will be connected to ground
*/
#include <LiquidCrystal.h>
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

byte emptyLeftEnd[] = {
  B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111
};

byte fullLeftEnd[] = {
  B11111, B10000, B10111, B10111, B10111, B10111, B10000, B11111
};

byte emptyMiddle[] = {
  B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111
};

byte fullMiddle[] = {
  B11111, B00000, B11111, B11111, B11111, B11111, B00000, B11111
};

byte emptyRightEnd[] = {
  B11110, B00010, B00011, B00001, B00001, B00011, B00010, B11110
};

byte fullRightEnd[] = {
  B11110, B00010, B11111, B11111, B11111, B11111, B00010, B11110
};

int batteryPin = A0;
float batteryThreshold = 0.9;
float voltageRef = 3.3;
float voltageBattery;
float batteryBar;
int ledPin = 8;

void setup() {
  analogReference(EXTERNAL);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Battery Tester");
  lcd.setCursor(2, 1);
  lcd.print("By:Yousef A.");
  delay(1000);
  lcd.clear();
  lcd.createChar(0, emptyLeftEnd);
  lcd.createChar(1, fullLeftEnd);
  lcd.createChar(2, emptyMiddle);
  lcd.createChar(3, fullMiddle);
  lcd.createChar(4, emptyRightEnd);
  lcd.createChar(5, fullRightEnd);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  
  //Calculate battery voltage
  voltageBattery = (voltageRef / 1023.0) * analogRead(batteryPin);
  
  //Convert battery voltage into 0-16 steps
  batteryBar = (int)((voltageBattery - batteryThreshold) / (1.5 - batteryThreshold) * 16);
  batteryBar = constrain(batteryBar, 0, 16);

  if (voltageBattery > 0.8) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  lcd.setCursor(0, 0);
  lcd.print(voltageBattery);
  lcd.print(" Volt:100mA");

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i == 0) {
      lcd.write(byte(0));  // empty left end
    } else if (i == 15) {
      lcd.write(byte(4));  // empty right end
    } else {
      lcd.write(byte(2));  // empty middle
    }
  }
  for (int i = 0; i < batteryBar; i++) {
    if (i == 0) {
      lcd.setCursor(i, 1);
      lcd.write(byte(1));  // full left end
    } else if (i == 15) {
      lcd.setCursor(i, 1);
      lcd.write(byte(5));  // full right end
    } else {
      lcd.setCursor(i, 1);
      lcd.write(byte(3));  // full middle
    }
  }
  delay(500);  //save system resources
}
