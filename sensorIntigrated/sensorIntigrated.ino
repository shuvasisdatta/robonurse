#include <Servo.h>

#include <Temp.h>

#include <MotorDrive.h>

#define buzzerPin 22

Servo medicationHand;

Temp lm35(A1);

char dir;

int servoPos=180;

long pulseTime1=0,pulseTime2=0;
float pulseTime,heartRate[3];
float heartRateAVG,heartRateTotal;
int ecgSensor[300]; 

boolean medicine=LOW;

MotorDrive bot(4, 5, 6, 7, 255, 255);

void ecgRead()
{
  for(int i=0;i<299;i++)
  {
    ecgSensor[i] = analogRead(A0);
    delay(10);
  }
for(int i=0;i<299;i++)
  {
    Serial.println(ecgSensor[i]);
    delay(40);
  }
}


void heartBitRead()
{
  //for(int i;i<5;i++)
     //int pulse = analogRead(A0);
   for(int i=0;i<=2;i++)
    {
      while(1)
      {
        if(analogRead(A0)>400)
        {
          pulseTime1=millis();
          while(analogRead(A0)>400);
          while(analogRead(A0)<400);
          //while(analogRead(A0)>400);
          pulseTime2=millis();
          break;
        }
      }
    
   pulseTime=pulseTime2-pulseTime1;
   heartRate[i]=60000/pulseTime;
   }
   heartRateAVG=(heartRate[0]+heartRate[1]+heartRate[2])/3;
   Serial.print('*');
   //if(heartRateAVG<150 && heartRateAVG>60)
   Serial.println(heartRateAVG);
}



void alarm1()
{
   digitalWrite(buzzerPin,HIGH);
   medicine=HIGH;
   
   //Serial.println(servoPos);
   dir='s';
   /*
       code for lcd print
   */
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(38400);
  medicationHand.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  botDrive();
  if((analogRead(A2)<500) && medicine==HIGH)
  {
    //code for medication hand's servo
    digitalWrite(buzzerPin,LOW);
    medicine=LOW;  
    servoPos=servoPos-25; 
    medicationHand.write(servoPos);
    //Serial.println(servoPos);
    }
    else;

}

void botDrive(){
  if(Serial.available()){
    dir = Serial.read();
  }
  switch(dir){
    case 'b':
      bot.forward();
      delay(10);
      break;
    case 'f':
      bot.backward();
      delay(10);
      break;
    case 'l':
      bot.hardLeft();
      delay(10);
      break;
    case 'r':
      bot.hardRight();
      delay(10);
      break;
    case 's':
      bot.stop();
      delay(10);
      break;
    case 'e':
      bot.stop();
      ecgRead();
      //dir='s';
      break;
    case 'p':
      bot.stop();
      heartBitRead();
      //dir='s';
      break;
    case 't':
      bot.stop();
      Serial.println(lm35.getTemp());
      delay(100);
      break;
    case '1':
      alarm1();
      break;
      
    //case ''
    default:
      break;
  }
}





