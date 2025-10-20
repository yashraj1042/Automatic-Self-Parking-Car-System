#include <Servo.h>
const int ena = 3;
const int forward =5;
const int backward =6;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int a;
void setup() 
{
  myservo.attach(4);  // attaches the servo on pin 9 to the servo object
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  delay(1100);
  pinMode(ena,OUTPUT);
  pinMode(11,INPUT);
  pinMode(13,INPUT);
  pinMode(10,INPUT);
  delay(2000);
  Serial.begin(9600);
  myservo.write(125);
  delay(1500);
  analogWrite(ena,58);
  digitalWrite(forward,HIGH);
  a=0;
    
}

void loop() {
analogWrite(ena,57);
int obstacle=digitalRead(13);
int aut=digitalRead(11);
int ct=digitalRead(10);

if(obstacle==0)
{
 digitalWrite(forward,LOW);
 delay(2000); 
 digitalWrite(forward,HIGH);
}
if(ct==1 && a==0)
{
digitalWrite(forward,LOW);
myservo.write(160);
delay(1000);
digitalWrite(forward,HIGH);
delay(2500);
digitalWrite(forward,LOW);
myservo.write(125);
delay(1000);
myservo.write(100);
delay(1000);
digitalWrite(forward,HIGH);
delay(2700);
digitalWrite(forward,LOW);
delay(1000);
myservo.write(125);
digitalWrite(backward,HIGH);
delay(2800);
digitalWrite(backward,LOW);  
a++;
}
if(aut==0)
{
delay(1000);
myservo.write(100);
delay(1000);
digitalWrite(forward,HIGH);
delay(2500);
digitalWrite(forward,LOW);
myservo.write(150);
delay(1000);
digitalWrite(forward,HIGH);
delay(2000);
digitalWrite(forward,LOW);
delay(1000);
myservo.write(125);
}
delay(50);
}