#define dirA 4
#define pwmA 5
#define pwmB 6
#define dirB 7

void forward()
{
   analogWrite(pwmA,180);
   analogWrite(pwmB,180);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
 }
 
void backward()
{
   analogWrite(pwmA,180);
   analogWrite(pwmB,180);
   digitalWrite(dirA, LOW);
   digitalWrite(dirB, HIGH);
 }

void hardright()
{
   analogWrite(pwmA,180);
   analogWrite(pwmB,180);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, HIGH);
 }

 void hardleft()
{
   analogWrite(pwmA,180);
   analogWrite(pwmB,180);
   digitalWrite(dirA, LOW);
   digitalWrite(dirB, LOW);
 }

 void softRight()
{
   analogWrite(pwmA,180);
   analogWrite(pwmB,0);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
}
 void softLeft()
{
   analogWrite(pwmA,0);
   analogWrite(pwmB,180);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
}
 
void setup() {
  pinMode(dirA, OUTPUT);
  //pinMode(pwmA, OUTPUT);
  //pinMode(pwmB, OUTPUT);
  pinMode(dirB, OUTPUT);
  softLeft();
}

void loop() 
{
  
}
