const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
const int led= 5;
const int tonePin=13;
float sinVal;
int toneVal;
int dangerValue=0;
float fadeValue=0;
float x;
void setup()
{
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
    pinMode(tonePin, OUTPUT); //chân ra cho Loa
}
 
void loop()
{
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    
    if(distance<30){
      dangerValue=30-distance;
      Serial.println(dangerValue);
      fadeValue=(float)dangerValue*255/30;
      Serial.println(fadeValue);
      analogWrite(led, fadeValue);
      delay(30);
      sinVal=(sin(dangerValue*(3.1412/180)));
      toneVal=4000+(int(sinVal*1000));
      Serial.print("tone val:");
      Serial.println(toneVal);
      tone(tonePin, toneVal, 100);
      delay(30);
    }else{
      analogWrite(led, 0);
      noTone(tonePin);
      delay (30);
    }
    
    /* In kết quả ra Serial Monitor */
    Serial.print(duration);
    Serial.println(" zz ");
    delay(200);
}
