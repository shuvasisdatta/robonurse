int ecgSensor[300]; 
char command='a';
void setup() {
  Serial.begin(9600);
}

void loop() {
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
  
  //Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability
}
