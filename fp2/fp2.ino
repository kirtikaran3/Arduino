#include <SoftwareSerial.h>
SoftwareSerial FP(2,3);

byte getImg[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x01,0x00,0x05};
byte imgTchr1[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x02,0x01,0x00,0x08};
byte imgTchr2[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x02,0x02,0x00,0x09};
byte temp[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x05,0x00,0x09};
byte dl1[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x08,0x01,0x00,0x0E};
byte dl2[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x08,0x02,0x00,0x0F};
byte    m[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x03,0x00,0x07};
byte dl1[]={0xEF,0X01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x08,0x01,0x00,0x0E};

byte res[100];

void setup() {
Serial.begin(9600);
FP.begin(57600);

  
// put your setup code here, to run once:
}

void loop() {

  if(Serial.available()>0){
    char ch = Serial.read();
     Serial.println("PUT F1");
     delay(2000);
     Serial.println("Start-------------------1"); 
    get_img();
   c1();
    Serial.println("PUT F2");
     delay(2000);
     Serial.println("Start-------------------2"); 
 get_img();
 
   c2();
    
     templt();
   
     down1();
       down2();
       match();
     
     
    }
  // put your main code here, to run repeatedly:

}
int getres(){
int  x=0;
  Serial.println("Getting response");
int i=1;
  
  while(FP.available()>0){
    x=1;
    delay(100);
    res[i]=FP.read();
    Serial.print(res[i],HEX);
    Serial.print("-");
    
    }
    
  Serial.println("");
  return x;
  }

void get_img(){
  int x=1;
  int c=1;
   Serial.println("Generating img ");  
   
    FP.write(getImg,12);
     delay(1000);
   getres();
 
  
  delay(1000);
   
  
   }
   
void c1(){
   Serial.println("Char 1");  
     FP.write(imgTchr1,13);
      delay(1000);
  getres();
    
    }
    void c2(){
       Serial.println("Char 2");  
     FP.write(imgTchr2,13);
      delay(1000);
  getres();
    
    }
    void templt(){
       Serial.println("Templete");  
       FP.write(temp,12);
        delay(1000);
  getres();
      
      }

      void down1(){
      Serial.println("Download 1");  
          FP.write(dl1,13);
           delay(1000);
  getres();

  
        }
          void down2(){
      Serial.println("Download 2");  
          FP.write(dl2,13);
           delay(1000);
  getres();

  
        }

         void match(){
      Serial.println("matching");  
          FP.write(m,12);
           delay(1000);
  getres();

  
        }





