//CODE DONE BY BOSH MACSIS && DR SURESAN PARETH
#include <IRremote.h>
#define irPin 6
 
int analogPin = A0;
int digitalPin = 2;
int buzzerPin = 13;
int digitalVal;
int analogVal;

IRrecv irrecv(irPin);
decode_results rslts;

void inits()
{
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(3,OUTPUT);

    Serial.begin(9600);
  pinMode (buzzerPin, OUTPUT);
  pinMode (digitalPin, INPUT);
  //Serial.begin(115200);
}
 
void setup() 
{
  inits();
  Serial.begin(9600);
  irrecv.enableIRIn();
}
 
void loop() {
   if (irrecv.decode(&rslts)) {
      Serial.println(rslts.value);
      
      switch (rslts.value) {
        
         case 16718055:            //  FORDWARD Button
            Forward();
            break;
 
         case 16716015:            //  LEFT Button
            Left();
            break;   
 
         case 16734885:            //  RIGHT Button
            Right();
            break;
 
         case 16730805:            //  BACK Button
            Back();
            break;
        
         case 16726215:            // STOP Button
            Stop();
            break;
   }      
   irrecv.resume();
   }
}
 
void Back()
{
            digitalWrite(3, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
}
 
void Forward()
{ 
            digitalWrite(3, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(13, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(12, LOW);
            
}    
void Left()
{
            digitalWrite(9, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(13, LOW);
            for(int i=100;i<=300;i=i+100)
            {
             delay(i);
            }
}
 
void Right()
{
            digitalWrite(3, HIGH);
            digitalWrite(13, HIGH);
            digitalWrite(11, LOW);
            for(int j=100;j<=300;j=j+100)
            {
              delay(j);
            }
} 
void Stop()
{
            digitalWrite(3, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
}
