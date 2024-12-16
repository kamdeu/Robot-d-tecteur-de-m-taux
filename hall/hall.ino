int analogPin = A0;
int digitalPin = 2;
int buzzerPin = 13;
int digitalVal;
int analogVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buzzerPin, OUTPUT);
  pinMode (digitalPin, INPUT);
  //Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalVal = digitalRead(digitalPin);
  analogVal = analogRead(analogPin);

  if(analogVal > 485);
  {
    tone (buzzerPin, 600);
    delay (500);
    tone (buzzerPin, 900);
    delay (500);  
  }
  if(analogVal < 485);
  {
    noTone(buzzerPin);
  }
  //analogVal = analogRead(analogPin);
  Serial.println (analogVal);

  delay(100);
}
