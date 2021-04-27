
// include the library code:
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
String stringOne, stringTwo;
// initialize the library with the numbers of the interface pins

int btn[] = {9,8,7,6};
int i,j;
void setup() {
    for (i=0;i<=3;i++)
  {
    pinMode(btn[i], INPUT);
    digitalWrite(btn[i], HIGH);
  }
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Con Heo Nu");
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);


  
stringOne = "func";
stringTwo = "";

}

void nhapnhay()
{
  for (i=0;i<=3;i++)
  {
    digitalWrite(btn[i],LOW);
    delay(300);
  }
    for (i=0;i<=3;i++)
  {
     digitalWrite(btn[i],HIGH);
    delay(300);
    
  }
}

void loop() {
//  digitalWrite(10,LOW);
//  delay(300);
//    digitalWrite(10,HIGH);
//    delay(300);
//    digitalWrite(13,LOW);
//  delay(300);
//    digitalWrite(13,HIGH);
//    delay(300);
  for (i=0;i<=3;i++)
    {
        if(digitalRead(btn[i]) == LOW)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        j=i+1; 
        stringTwo = stringOne + j;
        lcd.print(stringTwo) ;
        if (i==0)
        {
          digitalWrite(13,HIGH);
          digitalWrite(10,HIGH);
          }
        else if(i==1)
        {
          digitalWrite(10,LOW);
          digitalWrite(13,LOW);
          }
          else if (i==2)
          {
            digitalWrite(10,HIGH);
          digitalWrite(13,LOW);
            }
            else if (i==3)
          {
            digitalWrite(10,LOW);
          digitalWrite(13,HIGH);
            }
      }
    
    }
  
  


  
  
}
 
