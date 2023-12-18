#define trig1 22
#define echo1 23
#define trig2 24
#define echo2 25
#define trig3 26
#define echo3 27
#define trig4 28
#define echo4 29
#define trig5 30
#define echo5 31
#define trig6 32
#define echo6 33

#define LedG1 34
#define LedR1 35
#define LedG2 36
#define LedR2 37
#define LedG3 38 
#define LedR3 39
#define LedG4 40 
#define LedR4 41 
#define LedG5 42
#define LedR5 43
#define LedG6 44
#define LedR6 45
#define LedG7 2
#define LedR7 3
#define LedG8 4
#define LedR8 5
#define IR1 52
#define IR2 53

#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(46,47,48,49,50,51);
Servo myServo1,myServo2;

int distance=0,t=0,distance1=0,t1=0 ,distance2=0,t2=0 ,distance3=0,t3=0 ,distance4=0,t4=0 ,distance5=0,t5=0 ,distance6=0,t6=0,cnt=0;
int currentState = 0, previousState = 0;
int currentState1 = 0, previousState1 = 0,currentState2 = 0, previousState2 = 0;
int currentState3 = 0, previousState3 = 0,currentState4 = 0, previousState4 = 0;
int currentState5 = 0, previousState5 = 0,currentState6 = 0, previousState6 = 0;

int calculeDistance(int trig , int echo , int LedG , int LedR){
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t=pulseIn(echo,HIGH);
  distance=t*0.0175;
  if(distance<=5 && distance!=0){
    digitalWrite(LedG,LOW);
    digitalWrite(LedR,HIGH);
    currentState = 0;
  }
  else if(distance>5){
    digitalWrite(LedG,HIGH);
    digitalWrite(LedR,LOW);
    currentState = 1; 
   }
  return distance,currentState;  
  }
void setup() {
  Serial.begin(9600);

  myServo1.attach(8);
  myServo1.write(90);
  myServo2.attach(9);
  myServo2.write(90);
  
  lcd.begin(16,2);
  
  lcd.setCursor(0,1);
  lcd.print("spot : ");
  
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
  pinMode(trig4,OUTPUT);
  pinMode(echo4,INPUT);
  pinMode(trig5,OUTPUT);
  pinMode(echo5,INPUT);
  pinMode(trig6,OUTPUT);
  pinMode(echo6,INPUT);
  
  pinMode(LedG1,OUTPUT);
  pinMode(LedR1,OUTPUT);
  pinMode(LedG2,OUTPUT);
  pinMode(LedR2,OUTPUT);
  pinMode(LedG3,OUTPUT);
  pinMode(LedR3,OUTPUT);
  pinMode(LedG4,OUTPUT);
  pinMode(LedR4,OUTPUT);
  pinMode(LedG5,OUTPUT);
  pinMode(LedR5,OUTPUT);
  pinMode(LedG6,OUTPUT);
  pinMode(LedR6,OUTPUT);
  pinMode(LedG7,OUTPUT);
  pinMode(LedR7,OUTPUT);
  pinMode(LedG8,OUTPUT);
  pinMode(LedR8,OUTPUT);

  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
}

void loop() {
  //barriere 1
  if((digitalRead(IR1)==LOW) && cnt!=0){
    myServo1.write(180);
    Serial.println("servo1");
    delay(2000);
    }
  else{
    myServo1.write(90);
    }
  //barriere 2
  if(digitalRead(IR2)==LOW){
    myServo2.write(180);
    Serial.println("servo2");
    delay(2000);
    }
  else{
    myServo2.write(90);
    }
  //spot 1 
  distance1,currentState1= calculeDistance(trig1 , echo1 ,LedG1 , LedR1);
  Serial.print("distance1 = ");
  Serial.println(distance1);
  if(currentState1 != previousState1){
  if(currentState1 == 1){cnt++;}
  else{cnt--;}
  previousState1 = currentState1;
  } 


  
  //spot 2 
  distance2,currentState2= calculeDistance(trig2 , echo2 ,LedG2 , LedR2);
  Serial.print("distance2 = ");
  Serial.println(distance2);
  if(currentState2 != previousState2){
  if(currentState2 == 1){cnt++;}
  else{cnt--;}
  previousState2 = currentState2; 
  } 
      //spot 3 
  distance3,currentState3= calculeDistance(trig3 , echo3 ,LedG3 , LedR3);
  Serial.print("distance3 = ");
  Serial.println(distance3); 
    if(currentState3 != previousState3){
  if(currentState3 == 1){cnt++;}
  else{cnt--;}
  previousState3 = currentState3; 
    }
      //spot 4 
  distance4,currentState4= calculeDistance(trig4 , echo4 ,LedG4 , LedR4);
  Serial.print("distance4 = ");
  Serial.println(distance4);
    if(currentState4 != previousState4){
  if(currentState4 == 1){cnt++;}
  else{cnt--;}
  previousState4 = currentState4;
    }  
        //spot 5 
  distance5,currentState5= calculeDistance(trig5 , echo5 ,LedG5 , LedR5);
  Serial.print("distance5 = ");
  Serial.println(distance5); 
    if(currentState5 != previousState5){
  if(currentState5 == 1){cnt++;}
  else{cnt--;}
  previousState5 = currentState5; 
    }
        //spot 6 
  distance6,currentState6= calculeDistance(trig6 , echo6 ,LedG6 , LedR6);
  Serial.print("distance6 = ");
  Serial.println(distance6);  
    if(currentState6 != previousState6){
  if(currentState6 == 1){cnt++;}
  else{cnt--;}
  previousState6 = currentState6;
    }
if(distance1<5 && distance2<5 && distance3<5){
  digitalWrite(LedG7,LOW);
  digitalWrite(LedR7,HIGH);
  } 
else if(distance1>=5 || distance2>=5 || distance3>=5){
  digitalWrite(LedG7,HIGH);
  digitalWrite(LedR7,LOW);
  }
if(distance4<5 && distance5<5 && distance6<5){
  digitalWrite(LedG8,LOW);
  digitalWrite(LedR8,HIGH);
  } 
else if(distance4>=5 || distance5>=5 || distance5>=5){
  digitalWrite(LedG8,HIGH);
  digitalWrite(LedR8,LOW);
  }  
lcd.setCursor(7,1);
lcd.print(cnt);
lcd.print("/6");
if(cnt > 0){
  lcd.setCursor(0,0);
  lcd.print("parking vide");    
}
else if (cnt==0){
  lcd.setCursor(0,0);
  lcd.print("parking plein");
}

}
