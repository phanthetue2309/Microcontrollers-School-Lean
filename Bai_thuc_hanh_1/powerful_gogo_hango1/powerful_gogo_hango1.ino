  int pinLed[] = {13,12,11,10,9,8,7,6};
int i, j ;

const int BUTTON = 2;
void nhapnhay()
{
  for (i = 0 ; i <= 7 ; i++)
    digitalWrite(pinLed[i],LOW);
  delay(300);
  for (i = 0 ; i <= 7 ; i++)
    digitalWrite(pinLed[i], HIGH);
  delay(300);
}

void traisangphai()
{
  static int chay1 = 0 ;
  for (i =0 ;i < 2 ; i++)
    digitalWrite(pinLed[i],LOW);
  digitalWrite(pinLed[chay1],HIGH);
  delay(300);
  chay1 ++ ;
  if (chay1 > 2)
    chay1 = 0 ;
 
}

void tu1toi8vatu8ve1()
{
  static int i = 0 ;
  for (;i < 8 ; i++)
  {
    digitalWrite(pinLed[i],HIGH);
    delay(300);
  }
  for (; i > 0 ; i--)
  {
    digitalWrite(pinLed[i],LOW);
    delay(300);
  }
  
}
void setup()
{
  Serial.begin(9600);
  for (i=0 ; i <=7 ;i++)
    pinMode(pinLed[i], OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  // nhapnhay();
  //traisangphai();
  //tu1toi8vatu8ve1();

  static int count = 0 ;
  static int trangthai = 0 ;
  int state = digitalRead(BUTTON);
  if (state == HIGH)
  {
    delay(1000);
    count ++;
  } 
  else 
  {
    delay(100);
  }
   if (count %2 != 0 && count > 0 )
    {
      for (i = 0 ; i < 8 ; i++) 
        digitalWrite(pinLed[i],LOW); 
      traisangphai();
      
    }
    else if (count % 2 == 0 && count > 0) 
    {
        for (i = 0 ; i < 8 ; i++) 
          digitalWrite(pinLed[i],LOW);
      tu1toi8vatu8ve1();
    }
    if (count != 0)
    {
      Serial.print("count");
      Serial.println(count);
    } 
 
}
