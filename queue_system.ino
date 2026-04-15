#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal lcd(7,6,5,4,3,2);

int token = 1;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lcd.begin(16,2);
  lcd.print("Queue System");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  lcd.clear();
  lcd.print("Token:");
  lcd.setCursor(0,1);
  lcd.print(token);

  delay(2000);

  lcd.clear();
  lcd.print("Wait Time:");
  lcd.setCursor(0,1);
  lcd.print(token * 2);
  lcd.print(" min");

  token++;

  delay(3000);
}