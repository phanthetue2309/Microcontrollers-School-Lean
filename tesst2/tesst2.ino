void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    for(int i = 2; i<=7; i++){
      pinMode(i,OUTPUT);
    }
    
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  //float voltage = sensorValue * (5.0 / 1023.0);
  float brightness = sensorValue * (42.0 / 1023.0); // DO sang cua den theo bien tro
  float speed = sensorValue *(1000.0/1023.0); // Toc do cua den theo bien tro
  
  for(int i = 2; i <=  7;i++){
    analogWrite(i, brightness*(i - 1)); // Thiet do lap do sang cua den theo i
    delay(1100 - speed); // thiet lap do tre sang den
     if(i == 7){
      for(int i = 2; i <= 7; i++){
        analogWrite(i,0);
        delay(1100 - speed);// thiet lap do tre tat den
      }
     }
   Serial.println(speed);
  }
}
