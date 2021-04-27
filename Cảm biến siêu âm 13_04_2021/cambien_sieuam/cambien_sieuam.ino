const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
const int loa = 13;     // chân cho loa
const int led = 5;     // chân cho led
int new_time ;
int new_frequency ;
float ledValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // giao tiếp Serial với baudrate 960
  pinMode(trig, OUTPUT); // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
  pinMode(loa, OUTPUT);
  pinMode(led, OUTPUT);
}

// tone(pin, frequency, duration);
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long duration; // biến đo thời gia
  int distance; // biến lưu khoảng các

  digitalWrite(trig, 0); // tắt chân tri
  delayMicroseconds(2);
  digitalWrite(trig, 1); // phát xung từ chân tri
  delayMicroseconds(5); // xung có độ dài 5 microSecond
  digitalWrite(trig, 0); // tắt chân trig

  //Tính toán thời gian
  //đo độ rộng xung HIGH ở chân echo
  duration = pulseIn(echo, HIGH);
  //Tính khoảng cách
  distance = int(duration / 2 / 29.1); // đo bằng âm thanh 340m/s

  Serial.print(distance);
  Serial.println("cm");
  if (distance < 300 && distance >= 30 )
  {

    ledValue = (300 - float(distance)) * 255 / 300 ;
    Serial.println("led = " + String(ledValue));

    new_time = 1000 * int(distance / 10) ;
    new_frequency = 1000 * int(distance / 10);
    Serial.println("TRUE : " + String(new_time) + " "  + String(new_frequency) );
    tone(13, new_frequency, new_time);
    //digitalWrite(13,HIGH);
    //digitalWrite(12,HIGH);
    analogWrite(led, ledValue);
    delay(new_time);
    digitalWrite(loa, LOW);
    delay(1000);
    //
  }
  else
  {
    digitalWrite(loa, LOW);
    digitalWrite(led, LOW);
  }

}
