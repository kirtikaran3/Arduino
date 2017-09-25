#include<SoftwareSerial.h> 
#define MAX 12
SoftwareSerial FP(2,3);
 
byte Response[20];
byte Resp1[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x05}; //type=1
byte Resp2[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x03}; //type=2
byte Resp3[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x07}; //type=3
 
////////////// Set for generating TemplateNumbers in the library
byte TemplateNumCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x1d,0x00,0x21};
int TemplateNumCommandSize=12;
int TemplateNumCommandResponseCheckLength=9;
int TemplateNumCommandResponseLength=14;
int TemplateNumberResponseConfirmation=10; //confirmation byte: this must be 0
int TemplateNumbers[2];//byte 11 and 12
int TemplateNumberRespType=1;
////////////////////////////////Generate Image 1. GenImg//////////////////////////////////////////////////////////////
byte GenImgCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x01,0x00,0x05};
int GenImgCommandSize=12;
int GenImgCommandResponseCheckLength=9;
int GenImgCommandResponseLength=12;
int GenImgResponseConfirmation=9; //confirmation byte: this must be 0
//Confirmation code=01H: error when receiving package;
//Confirmation code=02H: can’t detect finger;
//Confirmation code=03H: fail to collect finger;
/////////// For converting the acquired image to character file 2. Img2Tz/////////////
byte BufferId=0x01;//0x02 for Buffer2
byte CheckSum=0x08; //for Buffer2 its 0x09;
 
byte Img2TzCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x02,BufferId,0x00,CheckSum};
int Img2TzCommandSize=13;
int Img2TzCommandResponseCheckLength=9;
int Img2TzCommandResponseLength=12;
int Img2TzRespType=2;
int Img2TzResponseConfirmation=9; //confirmation byte: this must be 0
 
////////////////////3. RegModel/////////////////////////////////////
byte RegModelCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x05,0x00,0x09};
int RegModelCommandSize=12;
int RegModelCommandResponseCheckLength=9;
int RegModelCommandResponseLength=12;
int RegModelRespType=2;
int RegModelResponseConfirmation=9; //confirmation byte: this must be 0
 
// Remember when you call this method both buffer1 and buffer2 will have same template
// before calling this method, buffer1 and buffer2 must be separately scanned and their template should be generated 
/////////////////////////
/////////////// 4. Store Template ( Uploading the template contents of buffer1/buffer2 to a specific memory location)//////////////
 
/////////////// 4. Store Template ( Uploading the template contents of buffer1/buffer2 to a specific memory location)//////////////
byte BasePageID=0x01;
byte PageID=0x00;
 
byte StoreCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x06,0x06,BufferId,PageID,0x00,0x00,Chec​kSum};
int StoreCommandSize=15;
int StoreCommandResponseCheckLength=9;
int StoreCommandResponseLength=12;
int StoreRespType=2;
int StoreResponseConfirmation=9; //confirmation byte: this must be 0
//Remember Page id is in the form LSB-MSB its 2 bytes so we are dealing with 255 images. Hence page id will vary from 0x00 to 0xFF
////////////////////////////////////////////////////Search Command/////////////////////////////////////////////////////////////////////////
//int SearchCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x08,0x04,BufferId,0x00,PageID,0x00,0x00​,0x00,CheckSum}; 
byte SearchCommand[]={0xEF,0x01,0xFF,0xFF,0xFF,0x01,0x00,0x08,0x04,BufferId,0x00,PageID,0x00,0x00,CheckSum};
int SearchCommandSize=17;
int SearchCommandResponseCheckLength=9;
int SearchCommandResponseLength=16;
int SearchRespType=3;
int SearchConfirmation=9; //confirmation byte: this must be 0
int SearchResponseConfirmation=9; 
 
void SetSearchParameters()
{
SearchCommand[10]=BufferId;
SearchCommand[12]=PageID;
 
int sum=0;
for(int i=6;i<=14;i++)
{
sum+=SearchCommand[i];
}
CheckSum=sum;
SearchCommand[16]=CheckSum;
 
}
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
void StoreChecksum()
{
int sum=0;
for(int i=6;i<=12;i++)
{
sum+=StoreCommand[i];
}
CheckSum=sum;
StoreCommand[14]=CheckSum;

}
void GetID()
{
Serial.println("Enter your ID[2 4 6 8]");
int n=-1;
do
{
n=Serial.read();
n=n-48;


}while(n<0 || n>255);
PageID=BasePageID+n;
StoreCommand[11]=PageID;
Serial.print("You entered:");
Serial.println(PageID,HEX);
}
 
///////////////////Methods//////////////////////////////////////////
 
/////////////////////////////////// Store the template in Specific flash location///////////////
int Store(int verbose,int loopbreak)
{

GetID();
StoreChecksum();
if(verbose==1)
{
Serial.println("Generated command for store ");
for(int i=0;i<storecommandsize;i++)
{
Serial.print(StoreCommand[i],HEX);
Serial.print(" ");
}
Serial.println();
}
boolean rslt=false;
int looping=0;
do
{
FP.write(StoreCommand,StoreCommandSize);
GetResponse(StoreCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(StoreRespType,StoreCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
switch(Response[StoreResponseConfirmation])
{
case 0x00: 
if(verbose==1)
{
Serial.print("\nTemplate save is address 0x00\n");
Serial.println(PageID);
 
}
return 1;


case 0x01: 
if(verbose==1)
{
Serial.println("\nError Receiving Packet\n");

 
}
return -1; 

case 0x0b: 
if(verbose==1)
{
Serial.println("\naddressing PageID is beyond the finger library\n");
 
}
return -1; 

case 0x18: 
if(verbose==1)
{
Serial.println("\nerror when writing Flash\n");
 
}
return -1;




}
Serial.println("\nUnknown error\n");
return -1;
}
 
/////////////////////////////////////////////////
 
 
////////////////Get The Response//////////////
boolean GetResponse(int len,int verbose)
{
if(FP.available()>=len)
{
for(int i=0;i<len;i++)
{
Response[i]=FP.read();
if(verbose==1)
{
Serial.print(Response[i],HEX);
Serial.print(" ");
}
}
if(verbose==1)
{
Serial.println();
}

}

}
 
////////////////////////////////////
 
/////////// Get The template Number
boolean ValidateResponse(int type,int length)
{
for(int i=0;i<length;i++)
{
if(type==1)
{
if(Response[i]!=Resp1[i])
{
return false;
}
}
if(type==2)
{
if(Response[i]!=Resp2[i])
{
return false;
}
}
if(type==3)
{
if(Response[i]!=Resp3[i])
{
return false;
}
}

}
return true;
}
/////////////////////////////////// Store the template in Specific flash location///////////////
 
 
/////////////////////////////////////////////////
 
/////////////////////// Generate Template from Buffer1 and Buffer2///////////////////
 
int RegModel(int verbose,int loopbreak)
{
boolean rslt=false;
int looping=0;
do
{
FP.write(RegModelCommand,RegModelCommandSize);
GetResponse(RegModelCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(RegModelRespType,RegModelCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
switch(Response[RegModelResponseConfirmation])
{
case 0x00: 
if(verbose==1)
{
Serial.println("\nTemplate generated from buffer1 and buffer2\n");
 
}
return 1;


case 0x01: 
if(verbose==1)
{
Serial.println("\nError Receiving Packet\n");

 
}
return -1; 

case 0x0a: 
if(verbose==1)
{
Serial.println("\nfail to combine the character files. That’s, the character files don’t belong to one finger.\n");
 
}
return -1; 

case 0x07: 
if(verbose==1)
{
Serial.println("\nfail to generate character file due to lackness of character point or over-smallness of fingerprint image\n");
 
}
return -1;




}
Serial.println("\nUnknown error\n");
return -1;
}
/////////////////////// Search command//////////////////////////////////////////////////////
int SearchCommandImplementation(int verbose,int loopbreak)
{
boolean rslt=false;
int looping=0;
SetSearchParameters();
do
{
FP.write(SearchCommand,SearchCommandSize);
if(verbose==1)
{
Serial.println("Printing the command");
for(int i=0;i<searchcommandsize;i++)
{
Serial.print(SearchCommand[i],HEX);
Serial.print(" ");
}
Serial.println();
}
GetResponse(SearchCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(SearchRespType,SearchCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
if(Response[SearchResponseConfirmation]==0x00 || Response[SearchResponseConfirmation]==0x84)
{
return 1;
}

Serial.println("\nUnknown error\n");
return -1;
}
/*
int SearchCommandImplementation(int verbose,int loopbreak)
{
boolean rslt=false;
int looping=0;
SetSearchParameters();
do
{
FP.write(SearchCommand,SearchCommandSize);
GetResponse(SearchCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(SearchRespType,SearchCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
switch(Response[SearchResponseConfirmation])
{
case 0x00: 
if(verbose==1)
{
Serial.println("\nSearch Successfull.... Matching with\n");
Serial.print(Response[SearchResponseConfirmation+1],HEX);
Serial.print(Response[SearchResponseConfirmation+2],HEX);
Serial.println("\n Matching score=");
Serial.print(Response[SearchResponseConfirmation+3],HEX);
Serial.print(Response[SearchResponseConfirmation+4],HEX);
Serial.println();
 
}
return 1;


case 0x01: 
if(verbose==1)
{
Serial.println("\nError Receiving Packet\n");

 
}
return -1; 

case 0x09: 
if(verbose==1)
{
Serial.println("\nNo matching in library. Page ID is zero and matching score=0\n");
 
}
return -1; 





}
Serial.println("\nUnknown error\n");
return -1;
}
*/
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////// Generate Character file from ImageBuffer///////////////////////
int GenImg2Tz(int verbose,int loopbreak)
{
boolean rslt=false;
int looping=0;
do
{
FP.write(Img2TzCommand,GenImgCommandSize);
GetResponse(Img2TzCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(Img2TzRespType,Img2TzCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
switch(Response[Img2TzResponseConfirmation])
{
case 0x00: 
if(verbose==1)
{
Serial.println("\nCharacter file Created from Image Buffer\n");
 
}
return 1;


case 0x01: 
if(verbose==1)
{
Serial.println("\nError Receiving Packet\n");

 
}
return -1; 

case 0x06: 
if(verbose==1)
{
Serial.println("\nfail to generate character file due to the over-disorderly fingerprint image\n");
 
}
return -1; 

case 0x07: 
if(verbose==1)
{
Serial.println("\nfail to generate character file due to lackness of character point or over-smallness of fingerprint image\n");
 
}
return -1;


case 0x15: 
if(verbose==1)
{
Serial.println("\nfail to generate the image for the lackness of valid primary image\n");
 
}
return -1;

}
Serial.println("\nUnknown error\n");
return -1;
}
///////////////////////////////////////////////////////////
int GenImg(int verbose,int loopbreak)
{
boolean rslt=false;
int looping=0;
do
{
FP.write(GenImgCommand,GenImgCommandSize);
GetResponse(GenImgCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(2,GenImgCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
switch(Response[GenImgResponseConfirmation])
{
case 0x00: 
if(verbose==1)
{
Serial.println("\nImage acquired and Stored in Image Buffer\n");
 
}
return 1;


case 0x01: 
if(verbose==1)
{
Serial.println("\nError Receiving Packet\n");

 
}
return -1; 

case 0x02: 
if(verbose==1)
{
Serial.println("\nCant Detect Finger\n");
 
}
return -1; 

case 0x03: 
if(verbose==1)
{
Serial.println("\nFailed to collect Finger\n");
 
}
return -1;

}
Serial.println("\nUnknown error\n");
return -1;
}
int GetTemplateNumber(int verbose,int loopbreak)// if the response does not arrive for loopbreak number of responses break it
{
boolean rslt=false;
int looping=0;
do
{
FP.write(TemplateNumCommand,TemplateNumCommandSize);

GetResponse(TemplateNumCommandResponseLength,verbose);//1 is verbose
rslt=ValidateResponse(1,TemplateNumCommandResponseCheckLength);
delay(500);
looping++;
if(looping>loopbreak)
{
delay(4000);
FP.end(); 
delay(1000);
FP.begin(57600);
if(verbose==1)
{
Serial.println("Cant get a valid response! Try Later");
}
return -1;
}
}while(!rslt);
if(Response[TemplateNumberResponseConfirmation]==0x00)
{
TemplateNumbers[0]=Response[TemplateNumberResponseConfirmation+1];
TemplateNumbers[1]=Response[TemplateNumberResponseConfirmation+2];
if(verbose==1)
{
Serial.println("Template Number:");
Serial.print(TemplateNumbers[0]);
Serial.print(TemplateNumbers[1]);
return 1;
}

}
else
{
return -1;
}

}
///////////////////////////////////
 
////////////////////////////////////////////////////////////////
 
void setup()
{
Serial.begin(9600);
FP.begin(57600);
}
 
 
void loop()
{
int command=0;
 
int verbose=1;
int loopend=10;
int r=-1;//for storing operation results 
delay(2000);
if(Serial.available()>0)
{
command=Serial.read();
command=command-48;
Serial.println(command);

switch(command)
{
case 1: 
r=GetTemplateNumber(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Template Number Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Template Number Operation is FAILS");
}
return;

case 2:
r=GenImg(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Image Operation is FAILS");
}
return;

case 3:
BufferId=0x01; // second scan
CheckSum=0x08;//Second scan
 
Img2TzCommand[10]=BufferId;
Img2TzCommand[12]=CheckSum;
r=GenImg2Tz(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Character buffer from Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Character buffer from Image Operation is FAILS");
}
return;
case 4:

Serial.println("Registration process");
Serial.println("Put your finger over scanner[1]");
delay(2000);

r=GenImg(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Image Operation is FAILS");
return;
}

delay(500);
BufferId=0x01; // second scan
CheckSum=0x08;//Second scan
Img2TzCommand[10]=BufferId;
Img2TzCommand[12]=CheckSum;
r=GenImg2Tz(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Character buffer from Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Character buffer from Image Operation is FAILS");
return;
}
BufferId=0x02; // second scan
CheckSum=0x09;//Second scan
Img2TzCommand[10]=BufferId;
Img2TzCommand[12]=CheckSum;
Serial.println("Remove your finger from Scanner\n");
delay(2000);
Serial.println("Place your finger on Scanner again[2]\n");
delay(2000);
r=GenImg(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Image Operation is FAILS");
return;
}

delay(500);

r=GenImg2Tz(verbose,loopend);
if(r>0)
{
Serial.println("\nGetting Character buffer from Image Operation is SUCCESS");
}
else
{
Serial.println("\nGetting Character buffer from Image Operation is FAILS");
return;
}
r=RegModel(verbose,loopend);
if(r>0)
{
Serial.println("\nGenerating template from buffer1 and buffer2 is SUCCESS");
}
else
{
Serial.println("\nGenerating template from buffer1 and buffer2 FAILS");
return;
}
/// Storage part
r=Store(verbose,loopend);
if(r>0)
{
Serial.println("\nStoring Success");
}
else
{
Serial.println("\nStoring FAILS");
return;
}
return;
case 5:
r=Store(verbose,loopend);
if(r>0)
{
Serial.println("\nStoring Success");
}
else
{
Serial.println("\nStoring FAILS");
return;
}
return;
case 6:
Serial.println("Search invoking from here");
BufferId=0x01;
GetID();
SetSearchParameters();
r=SearchCommandImplementation(verbose,loopend);
if(r>0)
{
Serial.print("\nSearch is Success:");
 
 
}
else
{
Serial.println("\nSearch FAILS");

return;
}
 
 
 
return;

}
}
}
 
