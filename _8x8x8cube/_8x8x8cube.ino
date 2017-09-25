
#include <SPI.h>

#define latch_pin 2
#define blank_pin 4
#define data_pin 11
#define clock_pin 13


int shift_out;
byte anode[8];


byte red0[64], red1[64], red2[64], red3[64];
byte blue0[64], blue1[64], blue2[64], blue3[64];
byte green0[64], green1[64], green2[64], green3[64];


int level=0;
int anodelevel=0;
int BAM_Bit, BAM_Counter=0; 


unsigned long start;


void setup(){

SPI.setBitOrder(MSBFIRST);//Most Significant Bit First
SPI.setDataMode(SPI_MODE0);// Mode 0 Rising edge of data, keep clock low
SPI.setClockDivider(SPI_CLOCK_DIV2);//Run the data in at 16MHz/2 - 8MHz

//Serial.begin(115200);// if you need it?
noInterrupts();// kill interrupts until everybody is set up

//We use Timer 1 to refresh the cube
TCCR1A = B00000000;//Register A all 0's since we're not toggling any pins
TCCR1B = B00001011;//bit 3 set to place in CTC mode, will call an interrupt on a counter match
//bits 0 and 1 are set to divide the clock by 64, so 16MHz/64=250kHz
TIMSK1 = B00000010;//bit 1 set to call the interrupt on an OCR1A match
OCR1A=30; // you can play with this, but I set it to 30, which means:
//our clock runs at 250kHz, which is 1/250kHz = 4us
//with OCR1A set to 30, this means the interrupt will be called every (30+1)x4us=124us, 
// which gives a multiplex frequency of about 8kHz

// here I just set up the anode array, this is what's written to the anode shift register, to enable each level
anode[0]=B00000001;
anode[1]=B00000010;
anode[2]=B00000100;
anode[3]=B00001000;
anode[4]=B00010000;
anode[5]=B00100000;
anode[6]=B01000000;
anode[7]=B10000000;
// don't hate on how I assigned the values to this register! haha

//finally set up the Outputs
pinMode(latch_pin, OUTPUT);//Latch
pinMode(data_pin, OUTPUT);//MOSI DATA
pinMode(clock_pin, OUTPUT);//SPI Clock
pinMode(blank_pin, OUTPUT);//Output Enable  important to do this last, so LEDs do not flash on boot up
SPI.begin();//start up the SPI library
interrupts();//let the show begin, this lets the multiplexing start

}


void loop(){

void rainVersionTwo();
void folder();
void sinwaveTwo();
void wipe_out();
void bouncyvTwo();
void color_wheelTWO();

}


void LED(int level, int row, int column, byte red, byte green, byte blue){ 

  if(level<0)
  level=0;
  if(level>7)
  level=7;
  if(row<0)
  row=0;
  if(row>7)
  row=7;
  if(column<0)
  column=0;
  if(column>7)
  column=7;  
    if(red<0)
  red=0;
  if(red>15)
  red=15;
  if(green<0)
  green=0;
  if(green>15)
  green=15;
  if(blue<0)
  blue=0;
  if(blue>15)
  blue=15;  
  
  
  //There are 512 LEDs in the cube, so when we write to level 2, column 5, row 4, that needs to be translated into a number from 0 to 511
  
  //This looks confusing, I know...
  int whichbyte = int(((level*64)+(row*8)+column)/8);
  
  int wholebyte=(level*64)+(row*8)+column;
//This will all make sense in a sec
 
 //This is 4 bit color resolution, so each color contains x4 64 byte arrays, explanation below:
  bitWrite(red0[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 0));
  bitWrite(red1[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 1));
  bitWrite(red2[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 2)); 
  bitWrite(red3[whichbyte], wholebyte-(8*whichbyte), bitRead(red, 3)); 

  bitWrite(green0[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 0));
  bitWrite(green1[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 1));
  bitWrite(green2[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 2)); 
  bitWrite(green3[whichbyte], wholebyte-(8*whichbyte), bitRead(green, 3));

  bitWrite(blue0[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 0));
  bitWrite(blue1[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 1));
  bitWrite(blue2[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 2)); 
  bitWrite(blue3[whichbyte], wholebyte-(8*whichbyte), bitRead(blue, 3));
  

int ISR(TIMER1_COMPA_vect){



  PORTD |= 1<<blank_pin;
  
if(BAM_Counter==8)
BAM_Bit++;
else
if(BAM_Counter==16)
BAM_Bit++;
else
if(BAM_Counter==32)
BAM_Bit++;

BAM_Counter++;//Here is where we increment the BAM counter

switch (BAM_Bit){
case 0:
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(red0[shift_out]);
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(green0[shift_out]); 
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(blue0[shift_out]);
  break;
case 1:
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(red1[shift_out]);
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(green1[shift_out]); 
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(blue1[shift_out]);
  break;
 case 2:
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(red2[shift_out]);
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(green2[shift_out]); 
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(blue2[shift_out]);
 break;
 case 3:
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(red3[shift_out]);
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(green3[shift_out]); 
 for(shift_out=level; shift_out<level+8; shift_out++)
 SPI.transfer(blue3[shift_out]);

  if(BAM_Counter==64){
  BAM_Counter=0;
  BAM_Bit=0;
  }
  break;
}
SPI.transfer(anode[anodelevel]);//finally, send out the anode level byte

PORTD |= 1<<latch_pin;//Latch pin HIGH
PORTD &= 0<<latch_pin;//Latch pin LOW
PORTD &= 0<<blank_pin;//Blank pin LOW to turn on the LEDs with the new data

anodelevel++;//inrement the anode level
level = level+8;//increment the level variable by 8, which is used to shift out data, since the next level woudl be the next 8 bytes in the arrays

if(anodelevel==8)//go back to 0 if max is reached
anodelevel=0;
if(level==64)//if you hit 64 on level, this means you just sent out all 63 bytes, so go back
level=0;
}
}
void wipe_out(){
  int xxx=0, yyy=0, zzz=0;
  int fx=random(8), fy=random(8), fz=random(8), direct, fxm=1, fym=1, fzm=1, fxo=0, fyo=0, fzo=0;
  int  ftx=random(8), fty=random(8), ftz=random(8), ftxm=1, ftym=1, ftzm=1, ftxo=0, ftyo=0, ftzo=0;
  int select, rr, gg, bb, rrt, ggt, bbt;
  for(xxx=0; xxx<8; xxx++){
  for(yyy=0; yyy<8; yyy++){
  for(zzz=0; zzz<8; zzz++){
  LED(xxx, yyy, zzz, 0, 0, 0);
  }}}
  
       select=random(3);
    if(select==0){
      rr=random(1, 16);
      gg=random(1, 16);
      bb=0;} 
     if(select==1){
      rr=random(1, 16);
      gg=0;
      bb=random(1, 16);}    
     if(select==2){
      rr=0;
      gg=random(1, 16);
      bb=random(1, 16);}
      
       select=random(3);
    if(select==0){
      rrt=random(1, 16);
      ggt=random(1, 16);
      bbt=0;} 
     if(select==1){
      rrt=random(1, 16);
      ggt=0;
      bbt=random(1, 16);}    
     if(select==2){
      rrt=0;
      ggt=random(1, 16);
      bbt=random(1, 16);}  
        start=millis();
      
  while(millis()-start<10000){
  
    //fx=random(8); fy=random(8); fz=random(8);

    LED(fxo, fyo, fzo, 0, 0, 0);
    LED(fxo, fyo, fzo+1, 0, 0, 0);
    LED(fxo, fyo, fzo-1, 0, 0, 0);
    LED(fxo+1, fyo, fzo, 0, 0, 0);
    LED(fxo-1, fyo, fzo, 0, 0, 0);
    LED(fxo, fyo+1, fzo, 0, 0, 0);
    LED(fxo, fyo-1, fzo, 0, 0, 0);
    
    LED(ftxo, ftyo, ftzo, 0, 0, 0);
    LED(ftxo, ftyo, ftzo+1, 0, 0, 0);
    LED(ftxo, ftyo, ftzo-1, 0, 0, 0);
    LED(ftxo+1, ftyo, ftzo, 0, 0, 0);
    LED(ftxo-1, ftyo, ftzo, 0, 0, 0);
    LED(ftxo, ftyo+1, ftzo, 0, 0, 0);
    LED(ftxo, ftyo-1, ftzo, 0, 0, 0);

    LED(ftx, fty, ftz, rr, gg, bb);
    LED(ftx, fty, ftz+1, rr, gg, bb);
    LED(ftx, fty, ftz-1,  rr, gg, bb);
    LED(ftx+1, fty, ftz, rr, gg, bb);
    LED(ftx-1, fty, ftz, rr, gg, bb);
    LED(ftx, fty+1, ftz, rr, gg, bb);
    LED(ftx, fty-1, ftz, rr, gg, bb);     
    
    LED(fx, fy, fz, rrt, ggt, bbt);
    LED(fx, fy, fz+1, rrt, ggt, bbt);
    LED(fx, fy, fz-1, rrt, ggt, bbt);
    LED(fx+1, fy, fz, rrt, ggt, bbt);
    LED(fx-1, fy, fz, rrt, ggt, bbt);
    LED(fx, fy+1, fz, rrt, ggt, bbt);
    LED(fx, fy-1, fz, rrt, ggt, bbt);  
    
    
     delay(10);
     
    fxo=fx;
    fyo=fy;
    fzo=fz; 
    
    ftxo=ftx;
    ftyo=fty;
    ftzo=ftz; 
 
    direct=random(3);
    if(direct==0)
    fx= fx+fxm;
    if(direct==1)
    fy= fy+fym;  
    if(direct==2)
    fz= fz+fzm;  
  if(fx<0){
    fx=0; fxm=1;}
  if(fx>7){
    fx=7; fxm=-1;}  
  if(fy<0){
    fy=0; fym=1;}
  if(fy>7){
    fy=7; fym=-1;}    
  if(fz<0){
    fz=0; fzm=1;}
  if(fz>7){
    fz=7; fzm=-1;}  
  
      direct=random(3);
    if(direct==0)
    ftx= ftx+ftxm;
    if(direct==1)
    fty= fty+ftym;  
    if(direct==2)
    ftz= ftz+ftzm;  
  if(ftx<0){
    ftx=0; ftxm=1;}
  if(ftx>7){
    ftx=7; ftxm=-1;}  
  if(fty<0){
    fty=0; ftym=1;}
  if(fty>7){
    fty=7; ftym=-1;}    
  if(ftz<0){
    ftz=0; ftzm=1;}
  if(ftz>7){
    ftz=7; ftzm=-1;} 
  }//while
    for(xxx=0; xxx<8; xxx++){
  for(yyy=0; yyy<8; yyy++){
  for(zzz=0; zzz<8; zzz++){
  LED(xxx, yyy, zzz, 0, 0, 0);
  }}}
  
}


void rainVersionTwo(){
  int x[64], y[64], z[64], addr, leds=64, bright=1, ledcolor, colowheel;
  int xx[64], yy[64], zz[64], xold[64], yold[64], zold[64], slowdown;
  
  for(addr=0; addr<64; addr++){
    x[addr]=random(8);
    y[addr]=random(8);
    z[addr]=random(8);
    xx[addr]=random(16);
    yy[addr]=random(16);
    zz[addr]=random(16);     
  }
  start=millis();
  while(millis()-start<20000){
  
if(ledcolor<200){
  for(addr=0; addr<leds; addr++){
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 0, 5, 15);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 0, 1, 9);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 0, 0, 10);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 1, 0, 11); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 3, 0, 12);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 10, 0, 15);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 10, 0, 10);
    if(z[addr]<=0)
  LED(z[addr], x[addr], y[addr], 10, 0, 1);
}}//200

  if(ledcolor>=200&&ledcolor<300){
  for(addr=0; addr<leds; addr++){
    LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
  if(z[addr]>=7)
  LED(z[addr], x[addr], y[addr], 15, 15, 0);
  if(z[addr]==6)
  LED(z[addr], x[addr], y[addr], 10, 10, 0);
   if(z[addr]==5)
  LED(z[addr], x[addr], y[addr], 15, 5, 0);
   if(z[addr]==4)
  LED(z[addr], x[addr], y[addr], 15, 2, 0); 
    if(z[addr]==3)
  LED(z[addr], x[addr], y[addr], 15, 1, 0);
    if(z[addr]==2)
  LED(z[addr], x[addr], y[addr], 15, 0, 0);
    if(z[addr]==1)
  LED(z[addr], x[addr], y[addr], 12, 0, 0);
    if(z[addr]<=0)
  LED(z[addr], x[addr], y[addr], 10, 0, 0);
}}//300

    if(ledcolor>=300&&ledcolor<400){

  }
     if(ledcolor>=500&&ledcolor<600){

}
  
  
  ledcolor++;
if(ledcolor>=300)
ledcolor=0;
  
    for(addr=0; addr<leds; addr++){
    xold[addr]=x[addr];
    yold[addr]=y[addr];
    zold[addr]=z[addr];
   } 
  
  
  delay(15);
  
  //for(addr=0; addr<leds; addr++)
  //LED(z[addr], x[addr], y[addr], 0, 0, 0);
    for(addr=0; addr<leds; addr++){
      
      //slowdown = random(2);
      //if(bitRead(z[addr],0))
  z[addr] = z[addr]-1;
  
 // x[addr] = x[addr]+1;
 // y[addr] = y[addr]+1;
  if(z[addr]<random(-100,0)){
    x[addr]=random(8);
    y[addr]=random(8);
    int select=random(3);
    if(select==0){
    xx[addr]=0;
    zz[addr]=random(16);
    yy[addr]=random(16);
    //zz[addr]=0;
    }
    if(select==1){
    xx[addr]=random(16);
    zz[addr]=0;
    yy[addr]=random(16);
    //yy[addr]=0;
    }
    if(select==2){
    xx[addr]=random(16);
    zz[addr]=random(16);
    yy[addr]=0;
    
    
    }    
   z[addr]=7; 
   
  }//-check
  }//add

  
  }//while
 
}//rainv2

void folder(){
  int xx, yy, zz, pullback[16], state=0, backorfront=7;//backorfront 7 for back 0 for front
  
  int folderaddr[16], LED_Old[16], oldpullback[16], ranx=random(16), rany=random(16), ranz=random(16), ranselect;
  int bot=0, top=1, right=0, left=0, back=0, front=0, side=0, side_select;
  
  folderaddr[0]=-7;
  folderaddr[1]=-6;
  folderaddr[2]=-5;
  folderaddr[3]=-4;
  folderaddr[4]=-3;
  folderaddr[5]=-2;
  folderaddr[6]=-1;
  folderaddr[7]=0;
  
  for(xx=0; xx<8; xx++){
  oldpullback[xx]=0;
  pullback[xx]=0;
  }
  
  
  
  start=millis();
  while(millis()-start<10000){ 
    if(top==1){
      if(side==0){
   //top to left-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(7-LED_Old[yy], yy-oldpullback[yy],xx , 0, 0, 0);
  LED(7-folderaddr[yy], yy-pullback[yy],xx , ranx, rany, ranz);
  }}}
    if(side==2){
      //top to back-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(7-LED_Old[yy], xx, yy-oldpullback[yy], 0, 0, 0);
  LED(7-folderaddr[yy], xx, yy-pullback[yy], ranx, rany, ranz);
  }}}
  if(side==3){
      //top-side to front-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(7-LED_Old[7-yy], xx, yy+oldpullback[yy], 0, 0, 0);
  LED(7-folderaddr[7-yy], xx, yy+pullback[yy], ranx, rany, ranz);
  }}}
    if(side==1){
    //top-side to right
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(7-LED_Old[7-yy], yy+oldpullback[yy],xx , 0, 0, 0);
  LED(7-folderaddr[7-yy], yy+pullback[yy],xx , ranx, rany, ranz);
  }}}
    }//top
    
    if(right==1){
    if(side==4){
   //right-side to top
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy+oldpullback[7-yy],7-LED_Old[7-yy],xx , 0, 0, 0);
  LED( yy+pullback[7-yy],7-folderaddr[7-yy],xx , ranx, rany, ranz);
  }}}
    if(side==3){
    //right-side to front-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, 7-LED_Old[7-yy],yy+oldpullback[yy], 0, 0, 0);
  LED(xx,7-folderaddr[7-yy], yy+pullback[yy], ranx, rany, ranz);
  }}}
    if(side==2){
   //right-side to back-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, 7-LED_Old[yy],yy-oldpullback[yy], 0, 0, 0);
  LED(xx,7-folderaddr[yy], yy-pullback[yy], ranx, rany, ranz);
  }}}
    if(side==5){
    //right-side to bottom
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy-oldpullback[yy],7-LED_Old[yy],xx , 0, 0, 0);
  LED( yy-pullback[yy],7-folderaddr[yy],xx , ranx, rany, ranz);
  }}}
    }//right
    
 if(left==1){
    if(side==4){
   //left-side to top
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy+oldpullback[yy],LED_Old[7-yy],xx , 0, 0, 0);
  LED( yy+pullback[yy],folderaddr[7-yy],xx , ranx, rany, ranz);
  }}}
  if(side==3){
     //left-side to front-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, LED_Old[7-yy],yy+oldpullback[yy], 0, 0, 0);
  LED(xx,folderaddr[7-yy], yy+pullback[yy], ranx, rany, ranz);
  }}}
  if(side==2){
//left-side to back-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, LED_Old[yy],yy-oldpullback[yy], 0, 0, 0);
  LED(xx,folderaddr[yy], yy-pullback[yy], ranx, rany, ranz);
  }}}
  if(side==5){
  //left-side to bottom
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy-oldpullback[yy],LED_Old[yy],xx , 0, 0, 0);
  LED( yy-pullback[yy],folderaddr[yy],xx , ranx, rany, ranz);
  }}}
  }//left
  
  
   if(back==1){
    if(side==1){
  //back-side to right-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, yy+oldpullback[yy],LED_Old[7-yy], 0, 0, 0);
  LED(xx, yy+pullback[yy],folderaddr[7-yy], ranx, rany, ranz);
  }}}
  if(side==4){
  // back-side to top-side
    for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy+oldpullback[yy],xx,LED_Old[7-yy] , 0, 0, 0);
  LED( yy+pullback[yy],xx,folderaddr[7-yy] , ranx, rany, ranz);
  }}}
  if(side==5){
  // back-side to bottom
    for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy-oldpullback[yy],xx,LED_Old[yy] , 0, 0, 0);
  LED( yy-pullback[yy],xx,folderaddr[yy] , ranx, rany, ranz);
  }}}//state1
 if(side==0){
//back-side to left-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, yy-oldpullback[yy],LED_Old[yy], 0, 0, 0);
  LED(xx, yy-pullback[yy],folderaddr[yy], ranx, rany, ranz);
  }}}
   }//back
   if(bot==1){
    if(side==1){
    // bottom-side to right-side
      for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(LED_Old[7-yy], yy+oldpullback[yy],xx , 0, 0, 0);
  LED(folderaddr[7-yy], yy+pullback[yy],xx , ranx, rany, ranz);
  }}}
  if(side==3){
  //bottom to front-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(LED_Old[7-yy], xx, yy+oldpullback[yy], 0, 0, 0);
  LED(folderaddr[7-yy], xx, yy+pullback[yy], ranx, rany, ranz);
  }}}
if(side==2){
  //bottom to back-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(LED_Old[yy], xx, yy-oldpullback[yy], 0, 0, 0);
  LED(folderaddr[yy], xx, yy-pullback[yy], ranx, rany, ranz);
  }}}
if(side==0){
  //bottom to left-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(LED_Old[yy], yy-oldpullback[yy],xx , 0, 0, 0);
  LED(folderaddr[yy], yy-pullback[yy],xx , ranx, rany, ranz);
  }}}
   }//bot
   
    if(front==1){
   if(side==0){
    //front-side to left-side
   for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, yy-oldpullback[yy],7-LED_Old[yy], 0, 0, 0);
  LED(xx, yy-pullback[yy],7-folderaddr[yy], ranx, rany, ranz);
  }}}
  if(side==5){
      // front-side to bottom
    for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy-oldpullback[yy],xx,7-LED_Old[yy] , 0, 0, 0);
  LED( yy-pullback[yy],xx,7-folderaddr[yy] , ranx, rany, ranz);
  }}}
  if(side==4){
      // front-side to top-side
    for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(yy+oldpullback[yy],xx,7-LED_Old[7-yy] , 0, 0, 0);
  LED( yy+pullback[yy],xx,7-folderaddr[7-yy] , ranx, rany, ranz);
  }}}
  if(side==1){
      //front-side to right-side
  for(yy=0; yy<8; yy++){
  for(xx=0; xx<8; xx++){
  LED(xx, yy+oldpullback[yy],7-LED_Old[7-yy], 0, 0, 0);
  LED(xx, yy+pullback[yy],7-folderaddr[7-yy], ranx, rany, ranz);
  }}}
    }//front

  


  delay(5);
  for(xx=0; xx<8; xx++){
  LED_Old[xx]=folderaddr[xx];
  oldpullback[xx]=pullback[xx];
  }
  

  
  
 
  if(folderaddr[7]==7){
   // pullback=8;
    for(zz=0; zz<8; zz++)
  pullback[zz] = pullback[zz]+1;
 
   if(pullback[7]==8){//finished with fold
   delay(10);
     //state++;
     //if(state==4)
     //state=0;
     
     ranselect= random(3);
     if(ranselect==0){
     ranx=0;
     rany=random(1,16);
     ranz=random(1,16);}
     if(ranselect==1){
     ranx=random(1,16);
     rany=0;
     ranz=random(1,16);}
     if(ranselect==2){
     ranx=random(1,16);
     rany=random(1,16);
     ranz=0;}     
     
     side_select=random(3);
     
     if(top==1){//                 TOP
     top=0; 
     if(side==0){//top to left
      left=1;
      if(side_select==0) side=2;
      if(side_select==1) side=3;
      //if(side_select==2) side=4;
      if(side_select==2) side=5;} else    
     if(side==1){//top to right
      right=1;
      if(side_select==0) side=5;
      if(side_select==1) side=2;
      if(side_select==2) side=3;
      //if(side_select==3) side=4;
    } else  
     if(side==2){//top to back
      back=1;
      if(side_select==0) side=0;
      if(side_select==1) side=1;
      if(side_select==2) side=5;
      //if(side_select==3) side=4;
    } else      
      if(side==3){//top to front
      front=1;
      if(side_select==0) side=0;
      if(side_select==1) side=1;
      if(side_select==2) side=5;
      //if(side_select==3) side=4;
    }   
     } else//top
     if(bot==1){//                 BOTTOM
     bot=0; 
     if(side==0){//bot to left
      left=1;
      if(side_select==0) side=2;
      if(side_select==1) side=3;
      if(side_select==2) side=4;
      //if(side_select==3) side=5;
    } else    
     if(side==1){//bot to right
      right=1;
      //if(side_select==0) side=5;
      if(side_select==0) side=2;
      if(side_select==1) side=3;
      if(side_select==2) side=4;} else  
     if(side==2){//bot to back
      back=1;
      if(side_select==0) side=0;
      if(side_select==1) side=1;
      //if(side_select==2) side=5;
      if(side_select==2) side=4;} else      
      if(side==3){//bot to front
      front=1;
      if(side_select==0) side=0;
      if(side_select==1) side=1;
      //if(side_select==2) side=5;
      if(side_select==2) side=4;}   
     } else//bot
          if(right==1){//                 RIGHT
     right=0; 
     if(side==4){//right to top
      top=1;
      if(side_select==0) side=2;
      if(side_select==1) side=3;
      if(side_select==2) side=0;
      //if(side_select==3) side=1;
    } else    
     if(side==5){//right to bot
      bot=1;
      if(side_select==0) side=0;
      if(side_select==1) side=2;
      if(side_select==2) side=3;
      //if(side_select==3) side=1;
    } 
      else  
     if(side==2){//right to back
      back=1;
      if(side_select==0) side=0;
      //if(side_select==1) side=1;
      if(side_select==1) side=5;
      if(side_select==2) side=4;} else      
      if(side==3){//right to front
      front=1;
      if(side_select==0) side=0;
      //if(side_select==1) side=1;
      if(side_select==1) side=5;
      if(side_select==2) side=4;}   
     } else//bot
              if(left==1){//                 LEFT
     left=0; 
     if(side==4){//left to top
      top=1;
      //if(side_select==0) side=2;
      if(side_select==0) side=3;
      if(side_select==1) side=2;
      if(side_select==2) side=1;} else    
     if(side==5){//left to bot
      bot=1;
      //if(side_select==0) side=0;
      if(side_select==0) side=2;
      if(side_select==1) side=3;
      if(side_select==2) side=1;} else  
     if(side==2){//left to back
      back=1;
      //if(side_select==0) side=0;
      if(side_select==0) side=1;
      if(side_select==1) side=5;
      if(side_select==2) side=4;} else      
      if(side==3){//left to front
      front=1;
      //if(side_select==0) side=0;
      if(side_select==0) side=1;
      if(side_select==1) side=5;
      if(side_select==2) side=4;}   
     } else//bot
              if(front==1){//                 front
     front=0; 
     if(side==4){//front to top
      top=1;
      if(side_select==0) side=2;
      //if(side_select==1) side=3;
      if(side_select==1) side=0;
      if(side_select==2) side=1;} else    
     if(side==5){//front to bot
      bot=1;
      if(side_select==0) side=0;
      if(side_select==1) side=2;
      //if(side_select==2) side=3;
      if(side_select==2) side=1;} else  
     if(side==0){//front to left
      left=1;
      if(side_select==0) side=2;
     // if(side_select==1) side=3;
      if(side_select==1) side=5;
      if(side_select==2) side=4;} else      
      if(side==1){//front to right
      right=1;
      if(side_select==0) side=2;
     // if(side_select==1) side=3;
      if(side_select==1) side=5;
      if(side_select==2) side=4;}   
     } else//bot
              if(back==1){//                 back
     back=0; 
     if(side==4){//back to top
      top=1;
      //if(side_select==0) side=2;
      if(side_select==0) side=3;
      if(side_select==1) side=0;
      if(side_select==2) side=1;} else    
     if(side==5){//back to bot
      bot=1;
      if(side_select==0) side=0;
      //if(side_select==1) side=2;
      if(side_select==1) side=3;
      if(side_select==2) side=1;} else  
     if(side==0){//back to left
      left=1;
      //if(side_select==0) side=2;
      if(side_select==0) side=3;
      if(side_select==1) side=5;
      if(side_select==2) side=4;} else      
      if(side==1){//back to right
      right=1;
      //if(side_select==0) side=2;
      if(side_select==0) side=3;
      if(side_select==1) side=5;
      if(side_select==2) side=4;}   
     } 
  for(xx=0; xx<8; xx++){
  oldpullback[xx]=0;
  pullback[xx]=0;}
 
  folderaddr[0]=-8;
  folderaddr[1]=-7;
  folderaddr[2]=-6;
  folderaddr[3]=-5;
  folderaddr[4]=-4;
  folderaddr[5]=-3;
  folderaddr[6]=-2;
  folderaddr[7]=-1;

}//pullback==7
  }//folderaddr==7    

  if(folderaddr[7]!=7)
  for(zz=0; zz<8; zz++)
  folderaddr[zz] = folderaddr[zz]+1;
  
}
  
  
  
  
  
}//folder


void bouncyvTwo(){
  int wipex, wipey, wipez, ranr, rang, ranb, select, oldx[50], oldy[50], oldz[50];
  int x[50], y[50], z[50], addr, ledcount=20, direct, direcTwo;
  int xx[50], yy[50], zz[50];
  int xbit=1, ybit=1, zbit=1;
   for(addr=0; addr<ledcount+1; addr++){
     oldx[addr]=0;
     oldy[addr]=0;
     oldz[addr]=0;
     x[addr]=0;
     y[addr]=0;
     z[addr]=0;
     xx[addr]=0;
     yy[addr]=0;
     zz[addr]=0;
 
   }
  
      start=millis();
      
  while(millis()-start<15000){
    direct = random(3);

for(addr=1; addr<ledcount+1; addr++){
LED(oldx[addr], oldy[addr],oldz[addr], 0,0,0);
LED(x[addr], y[addr], z[addr], xx[addr],yy[addr],zz[addr]);
}

for(addr=1; addr<ledcount+1; addr++){
oldx[addr]=x[addr];
oldy[addr]=y[addr];
oldz[addr]=z[addr];
}
delay(20);


//direcTwo=random(3);  
//if(direcTwo==1)



if(direct==0)
x[0]= x[0]+xbit;
if(direct==1)
y[0]= y[0]+ybit;
if(direct==2)
z[0]= z[0]+zbit;

if(direct==3)
x[0]= x[0]-xbit;
if(direct==4)
y[0]= y[0]-ybit;
if(direct==5)
z[0]= z[0]-zbit;





if(x[0]>7){
xbit=-1;
x[0]=7;
xx[0]=random(16);
yy[0]=random(16);
zz[0]=0;
//wipe_out();
}
if(x[0]<0){
xbit=1;
  x[0]=0;
xx[0]=random(16);
yy[0]=0;
zz[0]=random(16);
//wipe_out();
}
if(y[0]>7){
ybit=-1;
y[0]=7;
xx[0]=0;
yy[0]=random(16);
zz[0]=random(16);
//wipe_out();
}
if(y[0]<0){
ybit=1;
  y[0]=0;
  xx[0]=0;
yy[0]=random(16);
zz[0]=random(16);
//wipe_out();
}
if(z[0]>7){
zbit=-1;
z[0]=7;
xx[0]=random(16);
yy[0]=0;
zz[0]=random(16);
//wipe_out();
}
if(z[0]<0){
zbit=1;
  z[0]=0;
  xx[0]=random(16);
yy[0]=random(16);
zz[0]=0;
//wipe_out();
}

for(addr=ledcount; addr>0; addr--){
  x[addr]=x[addr-1];
  y[addr]=y[addr-1];
  z[addr]=z[addr-1];
  xx[addr]=xx[addr-1];
  yy[addr]=yy[addr-1];
  zz[addr]=zz[addr-1];
}


  }//while
  

  
  
  
}//bouncyv2
void sinwaveTwo(){
    int sinewavearray[8], addr, sinemult[8], colselect, rr=0, gg=0, bb=15, addrt;
  int sinewavearrayOLD[8], select, subZ=-7, subT=7, multi=0;//random(-1, 2);
  sinewavearray[0]=0;
  sinemult[0]=1;
   sinewavearray[1]=1;
  sinemult[1]=1; 
    sinewavearray[2]=2;
  sinemult[2]=1;
    sinewavearray[3]=3;
  sinemult[3]=1;
    sinewavearray[4]=4;
  sinemult[4]=1;
    sinewavearray[5]=5;
  sinemult[5]=1;
    sinewavearray[6]=6;
  sinemult[6]=1;
    sinewavearray[7]=7;
  sinemult[7]=1;
  
      start=millis();
      
  while(millis()-start<15000){
  for(addr=0; addr<8; addr++){
    if(sinewavearray[addr]==7){
    sinemult[addr]=-1;
    }
    if(sinewavearray[addr]==0){
    sinemult[addr]=1;     
    }
    sinewavearray[addr] = sinewavearray[addr] + sinemult[addr];
}//addr
     if(sinewavearray[0]==7){
     select=random(3);
    if(select==0){
      rr=random(1, 16);
      gg=random(1, 16);
      bb=0;} 
     if(select==1){
      rr=random(1, 16);
      gg=0;
      bb=random(1, 16);}    
     if(select==2){
      rr=0;
      gg=random(1, 16);
      bb=random(1, 16);}
   
 }    
   


      for(addr=0; addr<8; addr++){
    LED(sinewavearrayOLD[addr], addr, 0, 0, 0, 0);
    LED(sinewavearrayOLD[addr], 0, addr, 0, 0, 0);
    LED(sinewavearrayOLD[addr], subT-addr, 7, 0, 0, 0);
    LED(sinewavearrayOLD[addr], 7, subT-addr, 0, 0, 0);     
   LED(sinewavearray[addr], addr, 0, rr, gg, bb);
   LED(sinewavearray[addr], 0, addr, rr, gg, bb);
   LED(sinewavearray[addr], subT-addr,7, rr, gg, bb);
   LED(sinewavearray[addr], 7, subT-addr, rr, gg, bb);
    }//}
    
       for(addr=1; addr<7; addr++){   
    LED(sinewavearrayOLD[addr+multi*1], addr, 1, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*1], 1, addr, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*1], subT-addr, 6, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*1], 6, subT-addr, 0, 0, 0);  
   LED(sinewavearray[addr+multi*1], addr, 1, rr, gg, bb);
   LED(sinewavearray[addr+multi*1], 1, addr, rr, gg, bb);
   LED(sinewavearray[addr+multi*1], subT-addr,6, rr, gg, bb);
   LED(sinewavearray[addr+multi*1], 6, subT-addr, rr, gg, bb);
       }
 
        for(addr=2; addr<6; addr++){   
    LED(sinewavearrayOLD[addr+multi*2], addr, 2, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*2], 2, addr, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*2], subT-addr, 5, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*2], 5, subT-addr, 0, 0, 0);  
   LED(sinewavearray[addr+multi*2], addr, 2, rr, gg, bb);
   LED(sinewavearray[addr+multi*2], 2, addr, rr, gg, bb);
   LED(sinewavearray[addr+multi*2], subT-addr,5, rr, gg, bb);
   LED(sinewavearray[addr+multi*2], 5, subT-addr, rr, gg, bb);
       }  
             for(addr=3; addr<5; addr++){   
    LED(sinewavearrayOLD[addr+multi*3], addr, 3, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*3], 3, addr, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*3], subT-addr, 4, 0, 0, 0);
    LED(sinewavearrayOLD[addr+multi*3], 4, subT-addr, 0, 0, 0);  
   LED(sinewavearray[addr+multi*3], addr, 3, rr, gg, bb);
   LED(sinewavearray[addr+multi*3], 3, addr, rr, gg, bb);
   LED(sinewavearray[addr+multi*3], subT-addr,4, rr, gg, bb);
   LED(sinewavearray[addr+multi*3], 4, subT-addr, rr, gg, bb);
       }      
     
     for(addr=0; addr<8; addr++)
   sinewavearrayOLD[addr]=sinewavearray[addr];
    delay(30);

    
    
  }//while
  
  
}//SinewaveTwo

void color_wheel(){
  int xx, yy, zz, ww, rr=1, gg=1, bb=1, ranx, rany, swiper;
  
        start=millis();
      
  while(millis()-start<100000){
    swiper=random(3);
     ranx=random(16);
     rany=random(16);
     
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){ 
    for(zz=0;zz<8;zz++){
      
     LED(xx, yy, zz,  ranx, 0, rany);
    }}
  delay(50);
}

     ranx=random(16);
     rany=random(16);
     
    for(xx=7;xx>=0;xx--){ 
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx,yy, zz, ranx, rany, 0);
    }}
  delay(50); 
  }
       ranx=random(16);
     rany=random(16);
    for(xx=0;xx<8;xx++){ 
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
      LED(xx,yy, zz, 0, ranx, rany);
    }}
    delay(50);
  }
    
     ranx=random(16);
     rany=random(16);
    for(xx=7;xx>=0;xx--){ 
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx,yy, zz, rany, ranx, 0);
    }}
  delay(50); 
  }
    
  }//while
    
}//color wheel

void color_wheelTWO(){
  int xx, yy, zz, ww, rr=1, gg=1, bb=1, ranx, rany ,ranz, select, swiper;
  
        start=millis();
      
  while(millis()-start<10000){
    swiper=random(6);
    select=random(3);
    if(select==0){
     ranx=0;
     rany=random(16);
     ranz=random(16);}
    if(select==1){
     ranx=random(16);
     rany=0;
     ranz=random(16);}   
      if(select==2){
     ranx=random(16);
     rany=random(16);
     ranz=0;}  
    
     
    if(swiper==0){
    for(yy=0;yy<8;yy++){//left to right
    for(xx=0;xx<8;xx++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(30);
 }}
    if(swiper==1){//bot to top
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(30);
 }}  
    if(swiper==2){//back to front
    for(zz=0;zz<8;zz++){
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(30);
}}    
    if(swiper==3){
    for(yy=7;yy>=0;yy--){//right to left
    for(xx=0;xx<8;xx++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(30);
}}
    if(swiper==4){//top to bot
    for(xx=7;xx>=0;xx--){
    for(yy=0;yy<8;yy++){
    for(zz=0;zz<8;zz++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
 delay(30);
}}  
    if(swiper==5){//front to back
    for(zz=7;zz>=0;zz--){
    for(xx=0;xx<8;xx++){
    for(yy=0;yy<8;yy++){
    LED(xx, yy, zz,  ranx, ranz, rany);
    }}
  delay(30);
}}
  
  
  
  
  }
    
}

