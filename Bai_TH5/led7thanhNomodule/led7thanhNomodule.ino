
const int trig = 12;     // chân trig của HC-SR04 cảm biến siêu âm
const int echo = 13;     // chân echo của HC-SR04
int count = 0 ;
bool status1 = true;

void setup() {
  for (int pin = 2 ; pin <= 9 ; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
}
void loop() {
  // hiển thị số 0
  int distance; // biến lưu khoảng các
  unsigned long duration;
  digitalWrite(trig, 0); // tắt chân tri
  delayMicroseconds(2);
  digitalWrite(trig, 1); // phát xung từ chân tri
  delayMicroseconds(5); // xung có độ dài 5 microSecond
  digitalWrite(trig, 0); // tắt chân trig
  //Tính toán thơif gian
  //đo độ rộng xung HIGH ở chân echo
  duration = pulseIn(echo, HIGH);
  //Tính khoảng cách
  distance = int(duration / 2 / 29.42);
  Serial.println(distance);

  if (distance <= 40 )
  {
    if (status1 == true)
      count ++;
    status1 = false;
    if (count == 10)
      count = 0;
  }
  else
  {
    status1 = true ;
  }
  if (count == 0 )
  {
    int n0[8] = {0, 0, 0, 1, 0, 0, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n0[pin - 2]);
    }
    delay(500);
  }

  // hiển thị số 1
  if (count == 1 )
  {
    int n1[8] = {0, 1, 1, 1, 1, 1, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n1[pin - 2]);
    }
    delay(500);
  }

  if (count == 2 )
  {
    // hiển thị số 2
    int n2[8] = {0, 0, 1, 0, 0, 0, 1, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n2[pin - 2]);
    }
    delay(500);
  }

  // hiển thị số 3

  if (count == 3 )
  {
    int n3[8] = {0, 0, 1, 0, 1, 0, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n3[pin - 2]);
    }
    delay(500);
  }
  // hiển thị số 4
  if (count == 4 )
  {
    int n4[8] = {0, 1, 0, 0, 1, 1, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n4[pin - 2]);
    }
    delay(500);
  }
  // hiển thị số 5
  if (count == 5 )
  {
    int n5[8] = {1, 0, 0, 0, 1, 0, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n5[pin - 2]);
    }
    delay(500);
  }

  // hiển thị số 6
  if (count == 6 )
  {
    int n6[8] = {1, 0, 0, 0, 0, 0, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n6[pin - 2]);
    }
    delay(500);
  }
  // hiển thị số 7
  if (count == 7 )
  {
    int n7[8] = {0, 0, 1, 1, 1, 1, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n7[pin - 2]);
    }
    delay(500);
  }
  // hiển thị số 8
  if (count == 8 )
  {
    int n8[8] = {0, 0, 0, 0, 0, 0, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n8[pin - 2]);
    }
    delay(500);
  }
  // hiển thị số 9
  if (count == 9 )
  {
    int n9[8] = {0, 0, 0, 0, 1, 1, 0, 1};
    for (int pin = 2; pin <= 9 ; pin++) {
      digitalWrite(pin, n9[pin - 2]);
    }
    delay(500);
  }
}
