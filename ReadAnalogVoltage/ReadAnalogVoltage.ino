
int led[] = {3,5,6,9,10,11} ;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  for(int i=0;i<6;i++)
  {
    pinMode(led[i],OUTPUT);
    }
  
}

void saobang(int vol)
{
  //static int i=0;
  for(int i=0;i<6;i++)
  {
   digitalWrite(led[i],HIGH);
   delay(vol);
   }
     for(int i=0;i<6;i++)
  {
   digitalWrite(led[i],LOW);
   delay(vol);
   }
}
 
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  //analogWrite(led, voltage);
 
  int vol = 100;
  // wait for 30 milliseconds to see the dimming effect
  delay(vol);
   saobang(vol*100);
  Serial.println(vol);
  
}
