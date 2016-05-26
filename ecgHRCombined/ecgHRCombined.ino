char command='a';
long pulseTime1=0,pulseTime2=0;
float pulseTime,heartRate[3];
float heartRateAVG,heartRateTotal;
int ecgSensor[300]; 

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available()>0)
   command=Serial.read();
   else command='a';
   if(command=='b')
   {
    for(int i=0;i<299;i++)
  {
    ecgSensor[i] = analogRead(A0);
    delay(10);
  }
for(int i=0;i<299;i++)
  {
    Serial.println(ecgSensor[i]);
    delay(10);
  }
  }

  
   if(command=='c')
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
    
   //int pulseTimeavg=(pulseTime[0]+pulseTime[1]+pulseTime[3])/3;
   pulseTime=pulseTime2-pulseTime1;
   //Serial.println(pulseTime);
   heartRate[i]=60000/pulseTime;
   //Serial.println(heartRate[i]);
   }
   heartRateAVG=(heartRate[0]+heartRate[1]+heartRate[2])/3;
  //for(int i=0;i<=5;i++)
//   heartRateTotal=heartRateTotal+heartRate[i];
//   heartRateAVG=heartRateTotal/6;
   Serial.print('*');
   //if(heartRateAVG<150 && heartRateAVG>60)
   Serial.println(heartRateAVG);
    
        
       //Serial.println(255);
    //else Serial.println(0);
    //delay(10);
   }
  
}
