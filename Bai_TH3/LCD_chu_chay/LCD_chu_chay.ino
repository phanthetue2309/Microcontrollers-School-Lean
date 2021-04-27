
// include the library code:
#include <LiquidCrystal.h>
  String stringOne, stringTwo;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btn[] = {9,8,7,6};
int i,j;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.clear();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World");

}

void loop() {
//      lcd.scrollDisplayRight();
//      delay(150);
//    for (int position = 0; position < 1; position++)
//    {
//      // Cuộn 1 vị trí sang phải
//      lcd.scrollDisplayRight();
//      delay(150);
//    }
    for (int position=0; position<=15; position++)
    {
      lcd.clear();
      lcd.setCursor(position,0);
      lcd.print("Hello World");      
      delay(300);
    }
    


  
  
}
 
