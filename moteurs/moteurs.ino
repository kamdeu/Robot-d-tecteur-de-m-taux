// connect motor controller pins to Arduino digital pins
// motor one
#include <SoftwareSerial.h>
SoftwareSerial hc06(8,9);
String cmd="";
int enA = 2;
int in1 = 3;
int in2 = 4;
// motor two
int enB = 7;
int in3 = 5;
int in4 = 6;
void setup()
{
  //Initialize Serial Monitor
  Serial.begin(9600);
  hc06.begin(9600);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, 255);
  analogWrite(enB, 255); 
  
}

void loop()
{ 
  while(hc06.available()>0){
  cmd+=(char)hc06.read();
  }
  //control speed 
  //Select function with cmd
if(cmd!=""){
Serial.print("Command recieved : ");
Serial.println(cmd);
// We expect ON or OFF from bluetooth
if(cmd=="avant"){
  digitalWrite(in1, HIGH); //faire avancer la voiture
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);}
if(cmd=="arriere"){ 
 digitalWrite(in1, LOW); //faire reculer la voiture
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);}
if(cmd=="droite"){  
 digitalWrite(in1,HIGH ); //faire tourner la voiture a droite
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}
if(cmd=="gauche"){
 digitalWrite(in1, LOW); //faire tourner la voiture a gauche
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);}
if(cmd=="stop"){ 
 digitalWrite(in1, LOW); // Arreter la voiture
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}
cmd=""; //reset cmd
}
delay(100);
}
