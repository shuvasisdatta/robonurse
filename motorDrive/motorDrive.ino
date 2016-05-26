#include <MotorDrive.h>

MotorDrive bot(4, 5, 6, 7, 255, 255);

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  botDrive();

}

void botDrive(){
  char dir;
  if(Serial1.available()){
    dir = Serial1.read();
  }
  switch(dir){
    case 'f':
      bot.forward();
      delay(10);
      break;
    case 'b':
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
    default:
      break;
  }
}

