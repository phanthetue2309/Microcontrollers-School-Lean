/*
shiftOut ra 1 Module LED 7 đoạn đơn
*/
//chân ST_CP của 74HC595
int latchPin = 8;
//chân SH_CP của 74HC595
int clockPin = 12;
//Chân DS của 74HC595
int dataPin = 11;
const int trig = 6;     // chân trig của HC-SR04 cảm biến siêu âm
const int echo = 7;     // chân echo của HC-SR04
int count = 0 ;
bool status1 = true;
// Ta sẽ xây dựng mảng hằng số với các giá trị cho trước
// Các bit được đánh số thứ tự (0-7) từ phải qua trái (tương ứng với A-F,DP)
// Vì ta dùng LED 7 đoạn chung cực dương nên với các bit 0
// thì các đoạn của LED 7 đoạn sẽ sáng
// với các bit 1 thì đoạn ấy sẽ tắt

//mảng có 10 số (từ 0-9) và 
const int Seg[10] = {
  0b11000000,//0 - các thanh từ a-f sáng
  0b11111001,//1 - chỉ có 2 thanh b,c sáng
  0b10100100,//2
  0b10110000,//3
  0b10011001,//4
  0b10010010,//5
  0b10000010,//6
  0b11111000,//7
  0b10000000,//8
  0b10010000,//9
};


void setup() {
  //Bạn BUỘC PHẢI pinMode các chân này là OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  pinMode(trig,OUTPUT); // chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}

void loop() {
    unsigned long duration; // biến đo thời gia
    int distance; // biến lưu khoảng các    
    digitalWrite(trig,0);// tắt chân tri
    delayMicroseconds(2);
    digitalWrite(trig,1); // phát xung từ chân tri
    delayMicroseconds(5); // xung có độ dài 5 microSecond
    digitalWrite(trig,0);// tắt chân trig
    //Tính toán thơif gian
    //đo độ rộng xung HIGH ở chân echo
    duration = pulseIn(echo,HIGH);
    //Tính khoảng cách
    distance=int(duration/2/29.42); 
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
    //shiftout - start
    digitalWrite(latchPin, LOW);
    //Xuất bảng ký tự ra cho Module LED
    shiftOut(dataPin, clockPin, MSBFIRST, Seg[count]);  
    digitalWrite(latchPin, HIGH);
    delay(200);//Đợi 0.5 s cho mỗi lần tăng số
}
