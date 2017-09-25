#include <openGLCD.h>
#include <include/openGLCD_GLCDv3.h> // GLCDv3 compatibilty mode
#include "fonts/allFonts.h" 
#include "RTClib.h"
#include <Wire.h>

//Switches
int sw1 = 2;      //Send cart
int sw2 = 3;      //View cart
int sw3 = 4;      //Clear cart

RTC_DS1307 RTC;
DateTime current;

char *arr1 = "3F009479D1";
char *arr2 = "3F0095A430";
char *arr3 = "3F0095FFC5";
char *arr4 = "1500114B51";
char *arr5 = "3F0094A814";
char *arr6 = "3F0095F116";
char *arr7 = "3F00923540";
char *arr8 = "3F00946C0E";
char *arr9 = "1600664C65";
char *arr10 = "160065C08E";
char *mID = "ISC:001";

//Cart variables
char *item_code[] = {"E001","E002","E003","E004","E005","E006","E007","E008","E009","E010"};
char *item_name[] = {"Pepsi","Coke","Kurkure","Melody","Parle","Ketchup","Perk","Munch","Cadbury","Lays"};
int item_price[] = {10,20,30,40,50,60,70,80,90,100};
int item_ordered[]={0,0,0,0,0,0,0,0,0,0};
int total_price=0;
int total_items=0;


int byte_count=0;
char rfid_tag[15];

int ret;
//*****************************************
void rtc_init()
{
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) 
  {
    Serial.println(F("RTC : NOT running!"));
    RTC.adjust(DateTime(__DATE__, __TIME__));
 //   lcd.clear();
 //   lcd.print("RTC..X, Init...");
    delay(2000);
  }
  else
  {
    Serial.println(F("RTC : running!"));
//    lcd.clear();
//    lcd.print("RTC Init...OK");
    delay(2000);
  }
}
//*****************************************
void showDTcurrent() 
{
  current = RTC.now();
  GLCD.CursorTo(0, 0);
  GLCD.print("                    ");
  GLCD.CursorTo(0, 0);
  GLCD.print("T: ");GLCD.print(current.hour(), DEC);GLCD.print(":");GLCD.print(current.minute(), DEC);GLCD.print(" ");GLCD.print(current.day(), DEC);GLCD.print("/");GLCD.print(current.month(), DEC);GLCD.print("/");GLCD.print(current.year(), DEC);
  Serial.print("T: ");Serial.print(current.hour(), DEC);Serial.print(":");Serial.print(current.minute(), DEC);Serial.print(" ");Serial.print(current.day(), DEC);Serial.print("/");Serial.print(current.month(), DEC);Serial.print("/");Serial.println(current.year(), DEC);
  
}
//*****************************************
int check_rfid()
{
  char temp;
  if(Serial1.available() > 0) 
  {
    Serial.println("Entered RFID Receiving");
    while(byte_count<=12)    
    {
        if(Serial1.available() > 0) 
        {
          rfid_tag[byte_count]= Serial1.read();
          //Serial.println(rfid_tag[byte_count]);
          byte_count++;
        }
    }
    rfid_tag[10]='\0';
    while(Serial1.available() > 0)
    {
      temp = Serial1.read();  
    }
    byte_count=0;
    Serial.print("TAG code is: ");   // possibly a good TAG 
    Serial.println(rfid_tag); 
    if(strcmp(arr1,rfid_tag)==0){return 1;}
    if(strcmp(arr2,rfid_tag)==0){return 2;}
    if(strcmp(arr3,rfid_tag)==0){return 3;}
    if(strcmp(arr4,rfid_tag)==0){return 4;}
    if(strcmp(arr5,rfid_tag)==0){return 5;}
    if(strcmp(arr6,rfid_tag)==0){return 6;}
    if(strcmp(arr7,rfid_tag)==0){return 7;}
    if(strcmp(arr8,rfid_tag)==0){return 8;}
    if(strcmp(arr9,rfid_tag)==0){return 9;}
    if(strcmp(arr10,rfid_tag)==0){return 10;}   
  }
  else
  {
    return 100;
  }
  return 0;        
}
//*****************************************
void switches_init()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
}
//*****************************************
void glcd_init()
{
  GLCD.Init();
}
//*****************************************
void welcome_page()
{
  GLCD.SelectFont(Arial14);
  GLCD.CursorTo(3, 0);
  GLCD.print("Welcome");
  GLCD.CursorTo(0, 3);
  GLCD.SelectFont(System5x7);
  GLCD.print("Intell. Shopping Cart");  
  delay(2500);
  GLCD.ClearScreen();
}
//*****************************************
void read_rfid()
{
  ret = check_rfid();
  if(ret==0)
  {
    Serial.println("Invalid Card");
  }
  else if(ret<=10)      //If valid card detected
  {
    Serial.print("Item : ");Serial.println(ret);
    GLCD.CursorTo(0, 2);GLCD.print("                    ");GLCD.CursorTo(0, 2);
    if(item_ordered[ret-1]==0)
    {
      item_ordered[ret-1]=1;
      GLCD.print(item_code[ret-1]);GLCD.print("-");GLCD.print(item_name[ret-1]);GLCD.print("-Rs");GLCD.print(item_price[ret-1]);
      GLCD.CursorTo(0, 4);GLCD.print("                    ");GLCD.CursorTo(0, 4);GLCD.CursorTo(0, 4);GLCD.print("Item Added !");
      total_items++;
    }
    else if(item_ordered[ret-1]==1)
    {
      item_ordered[ret-1]=0;
      GLCD.print(item_code[ret-1]);GLCD.print("-");GLCD.print(item_name[ret-1]);GLCD.print("-Rs");GLCD.print(item_price[ret-1]);
      GLCD.CursorTo(0, 4);GLCD.print("                    ");GLCD.CursorTo(0, 4);GLCD.CursorTo(0, 4);GLCD.print("Item Removed !");
      total_items--;
    }  
    delay(3000);
    GLCD.CursorTo(0, 2);GLCD.print("                    ");GLCD.CursorTo(0, 4);GLCD.print("                    ");
    while(Serial1.available() > 0) {Serial1.read();}
  }
  
}
//*****************************************
void read_switches()
{
  int i,j;
  
  //Send the cart
  if(digitalRead(sw1)==LOW)
  {
    GLCD.CursorTo(0, 3);GLCD.print("                    ");GLCD.CursorTo(0, 3);GLCD.CursorTo(0, 3);GLCD.print("Sending Cart...");delay(1000);GLCD.CursorTo(0, 3);GLCD.print("                    ");
    total_price=0;
    Serial2.print("<");
    Serial2.print(current.hour(), DEC);Serial2.print(":");Serial2.print(current.minute(), DEC);Serial2.print(" ");Serial2.print(current.day(), DEC);Serial2.print("-");Serial2.print(current.month(), DEC);Serial2.print("-");Serial2.println(current.year(), DEC);
    Serial2.print("^");Serial2.println(mID);
    for(i=0;i<=9;i++) //Check each item if ordered
    {
      if(item_ordered[i]==1)
      {
        Serial2.print("^");Serial2.print(item_code[i]);Serial2.print(" - ");Serial2.print(item_name[i]);Serial2.print(" - Rs ");Serial2.println(item_price[i]);
        total_price+=item_price[i];
      }
    }
    Serial2.print("^Total : Rs ");Serial2.println(total_price);
    Serial2.println(">");
    //TODO: Clear the cart when sent
    
  }
  
  //View the cart
  if(digitalRead(sw2)==LOW)
  {
    GLCD.CursorTo(0, 3);GLCD.print("                    ");GLCD.CursorTo(0, 3);GLCD.CursorTo(0, 3);GLCD.print("View Cart...");delay(1000);GLCD.CursorTo(0, 3);GLCD.print("                    ");
    if(total_items<=5)  //If items less than 
    {
      int row_temp=2;    
      total_price=0;
      for(i=0;i<=9;i++) //Check each item if ordered
      {
        if(item_ordered[i]==1)
        {
          GLCD.CursorTo(0, row_temp);GLCD.print("                    ");GLCD.CursorTo(0, row_temp);
          GLCD.print(item_code[i]);GLCD.print("-");GLCD.print(item_name[i]);GLCD.CursorTo(14, row_temp);GLCD.print("-Rs");GLCD.print(item_price[i]);
          row_temp++;
          total_price+=item_price[i];
        }
      }
      GLCD.CursorTo(0, 7);GLCD.print("                    ");GLCD.CursorTo(0, 7);GLCD.print("Total : Rs ");GLCD.print(total_price);
    }
    else
    {
      int row_temp=2;    
      total_price=0;
      int repeat_flag=1;
      for(i=0;i<=9;i++) //Check each item if ordered
      {
        if(item_ordered[i]==1)
        {
          GLCD.CursorTo(0, row_temp);GLCD.print("                    ");GLCD.CursorTo(0, row_temp);
          GLCD.print(item_code[i]);GLCD.print("-");GLCD.print(item_name[i]);GLCD.CursorTo(14, row_temp);GLCD.print("-Rs");GLCD.print(item_price[i]);
          row_temp++;
          total_price+=item_price[i];
          if(row_temp==6)
          {
            if(repeat_flag==1)
            {
              repeat_flag=0;
              delay(5000);
              for(j=1;j<=5;j++)
              {GLCD.CursorTo(0, i);GLCD.print("                    ");}
              row_temp=2;
            }
          }
        }
      }
      GLCD.CursorTo(0, 7);GLCD.print("                    ");GLCD.CursorTo(0, 7);GLCD.print("Total : Rs ");GLCD.print(total_price);
    }
    delay(5000);
    GLCD.ClearScreen();
  }
  
  //Clear the cart
  if(digitalRead(sw3)==LOW)
  {
    GLCD.CursorTo(0, 3);GLCD.print("                    ");GLCD.CursorTo(0, 3);GLCD.CursorTo(0, 3);GLCD.print("Clearing Cart...");delay(1000);GLCD.CursorTo(0, 3);GLCD.print("                    ");
    for(i=0;i<10;i++)
    {item_ordered[i]=0;}
    total_price=0;
    total_items=0;  
    GLCD.ClearScreen();
  }
}
//*****************************************
void setup()
{
  glcd_init();
  Serial.begin(9600); //Debugging
  Serial1.begin(9600); //Rfid
  Serial2.begin(9600); //Bluetooth
  Serial.println("Program Started");
  //Serial2.println("Program Started");
  switches_init();
  welcome_page();
  rtc_init(); 
}
//*****************************************
void loop()
{
  read_switches();
  read_rfid();
  showDTcurrent(); 
  delay(200);
}
//*****************************************
