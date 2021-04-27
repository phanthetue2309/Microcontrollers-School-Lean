#include <Wire.h>

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String intro = "   Hello Teacher Duy     ";

void setup() {

   lcd.begin(16, 2);

}

void loop() {

  for (int i=0; i<intro.length()-16; i++){

    for (int j=0; j<16; j++){

      lcd.setCursor(j,0);

      lcd.print(intro[i+j]);

    }

    delay(500);

  }
}
