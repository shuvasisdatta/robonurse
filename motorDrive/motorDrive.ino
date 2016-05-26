#include <MotorDrive.h>

MotorDrive bot(4, 5, 6, 7, 180, 180);

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
      delay(500);
      break;
    case 'b':
      bot.backward();
      delay(500);
      break;
    case 'l':
      bot.hardLeft();
      delay(500);
      break;
    case 'r':
      bot.hardRight();
      delay(500);
      break;
    case 's':
      bot.stop();
      delay(500);
      break;
    default:
      break;
  }
}

