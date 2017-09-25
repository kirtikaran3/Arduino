#include <SPI.h>

//When Using the SPI library, you only have to worry
//about picking your slave select
//By Default, 11 = MOSI, 12 = MISO, 13 = CLK
int SalSel = 10;   //SPI Slave Select

void setup()
{
  
  pinMode(SalSel, OUTPUT);
  SPI.begin();
  
}

void setLed(int reg, int level)
{
  digitalWrite(SalSel, LOW);
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SalSel, HIGH);
}

void loop()
{
  for(int i=0; i<=2; i++)
  {
    for (int j=50; j<=255; j++)
    {
      setLed(i,j);
      delay(20);
    }
    delay(500);
    for (int j=255; j>=50; j--)
    {
      setLed(i,j);
      delay(20);
    }
  }
}
