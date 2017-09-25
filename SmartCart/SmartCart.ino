 /* Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */ 
 
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[3];
int item_first=0,item_second=0;
void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("Please scan your products"));
  Serial.print(F("The machine code is "));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE); 
  Serial.println("  ::The Machine name is NITIN:: ");
}
 
void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  Serial.println("");
  
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Please scan again"));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    
    Serial.println(F("A new product has been scanned"));
    
    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("The Bar_Code tag is:"));
    Serial.print(F("In hex: "));
     printHex(rfid.uid.uidByte, rfid.uid.size); 
     byte product[10]={(rfid.uid.uidByte,rfid.uid.size)};
    Serial.println();
    Serial.println("product is  :"); 
   if(nuidPICC[0]==0xD3){
      Serial.println("First product To be add in Bill "); 
      Serial.println("The bill is Rs 1000: "); 
        item_first=1000;
      } 
     if(nuidPICC[0]==0x35){
      Serial.println("Second product To be add in Bill "); 
      Serial.println("The bill is Rs 500: "); 
      
      item_second=500+item_first;
        
     
    Serial.print("The total bill is\n"); 
    Serial.println(item_second); 
     }
 
  }
  else Serial.println(F("Product read previously."));

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}



void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX); 
    
  }
}


