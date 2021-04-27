
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16, 2);
//LiquidCrystal_I2C lcd(0x3F,16, 2);

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
int myInts[6];
int led = 7;
void setup() {
  Serial.begin(9600);
  lcd.begin();
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.backlight();
  Serial.println("Khởi tạo thành công, đang chờ đọc thẻ…");
  pinMode(led,OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Khong co the    ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    digitalWrite(led, LOW);
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    digitalWrite(led, LOW);
    return;
  }
  digitalWrite(led, HIGH);
  //Serial.println("ID thẻ: ");
  String id = "";
  lcd.clear();
  lcd.setCursor(2, 0);
  if (mfrc522.uid.uidByte[0] == 204) {
    lcd.print("NGUYEN VAN A");
    Serial.print("NGUYEN VAN A");
    
  }
  else if (mfrc522.uid.uidByte[0] == 193)
  {
    lcd.print("NGUYEN VAN B");
    Serial.print("NGUYEN VAN B");
  }
  else 
  {
    lcd.print("NGUYEN VAN C");
    Serial.print("NGUYEN VAN C");
  }
  Serial.print(",");
  lcd.setCursor(0, 1);
  lcd.print("ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);

    for (byte i = 0; i < mfrc522.uid.size; i++) {
      disPlay(mfrc522.uid.uidByte[i], i);
    }
  }
  Serial.println("");
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(5000);
  lcd.setCursor(0, 0);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
}

void disPlay(byte number, int i) {
  byte bitHigh = number / 16;
  byte bitLow = number % 16;
  lcd.setCursor((4 + 3 * i), 1);
  convert(bitHigh);
  lcd.setCursor((5 + 3 * i), 1);
  convert(bitLow);
}

//  chuyen sang he 16

void convert(byte number) {
  if (number < 10) lcd.print(number);
  if (number == 10) lcd.print("A");
  if (number == 11) lcd.print("B");
  if (number == 12) lcd.print("C");
  if (number == 13) lcd.print("D");
  if (number == 14) lcd.print("E");
  if (number == 15) lcd.print("F");

}
