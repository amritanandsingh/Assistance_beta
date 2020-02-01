#include <Servo.h>
Servo myservo;
int pos = 0;  

int trigPin = 9;
int echoPin = 10;
int l=100;
int l2=100;
int l3=100;
int g,g2,g3;
int a,a2,a3,t,n;

//motor a
const int inputPin1  = 2;    // Pin 15 of L293D IC
const int inputPin2  = 3;    // Pin 10 of L293D IC
//Motor B
const int inputPin3  = 4;   // Pin  7 of L293D IC
const int inputPin4  = 5;   // Pin  2 of L293D IC
void setup() {
  Serial.begin(9600); 

   myservo.attach(7); 
   
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
pinMode(inputPin1, OUTPUT);
   pinMode(inputPin2, OUTPUT);
   pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
 
}
void loop() {
 int c=0;
l=100;
l2=100;
l3=100;
g=0;
g2=0;
g3=0;
a=0;
a2=0;
a3=0;
n=0;
t=0;

for (pos = 15; pos <= 38; pos += 1) 
{ 
   myservo.write(pos);              
    delay(5);
     long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  if(distance<l)
  l=distance;   
  if(distance>g) 
  g=distance;   
  t+=distance;
  n+=1;                
  }
  a=t/n;
  Serial.print(l);
  Serial.println("CM__");
  Serial.print(a);
  Serial.println("CM__");
  Serial.print(g);
  Serial.println("CM__");
  n=0;
  t=0;
  for (pos = 38; pos <= 71; pos += 1) 
{ 
   myservo.write(pos);              
    delay(5);
     long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  if(distance<l2)
  l2=distance;  
  if(distance>g2)
  g2=distance; 
  t+=distance;
  n+=1;                    
  }
  a2=t/n;
  Serial.print(l2);
  Serial.println("CM__");
  Serial.print(a2);
  Serial.println("CM__");
  Serial.print(g2);
  Serial.println("CM__");
  n=0;
  t=0;
  for (pos = 71; pos <= 115; pos += 1) 
{ 
   myservo.write(pos);              
    delay(5);
     long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  if(distance<l3)
  l3=distance;
  if(distance>g3)
  g3=distance;   
  t+=distance;
  n+=1;                    
  }
a3=t/n;
  Serial.print(l3);
  Serial.println("CM__");
  Serial.print(a3);
  Serial.println("CM__");
  Serial.print(g3);
  Serial.println("CM__");
  
  for (pos = 115; pos >= 15; pos -= 1) { 
    myservo.write(pos);              
    delay(5);                       
  }
  
if(l<20)
{  
 c+=1;
 digitalWrite(inputPin1, HIGH);
     digitalWrite(inputPin4, HIGH);
                delay(400);   
      digitalWrite(inputPin1, LOW);
     digitalWrite(inputPin4, LOW);
    delay(100);
       
}
else if(l3<=20)
{    c+=1;
  digitalWrite(inputPin3, HIGH);
     digitalWrite(inputPin2, HIGH);
                delay(400);   
      digitalWrite(inputPin2, LOW);
      digitalWrite(inputPin3, LOW);
       delay(100);
        }
else
 { digitalWrite(inputPin1, HIGH);
     digitalWrite(inputPin3, HIGH);
                delay(500);   
      digitalWrite(inputPin1, LOW);
      digitalWrite(inputPin3, LOW);
       // delay(500);
 }
 Serial.print(c);
 Serial.print("------------------------ONE CLCLE IS COMPLET----------------------------");

        }
