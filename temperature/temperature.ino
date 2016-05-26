#include <Temp.h>

Temp temp(A0);

void setup()
{
  Serial.begin(38400);
}

void loop()
{
  temp.showTemp();
  delay(300);
}
