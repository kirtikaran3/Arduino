float sine20000[]={127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,253,252,251,250,249,248,247,246,244,242,240,238,236,234,232,230,228,226,224,222,220,218,216,214,212,210,208,206,204,202,200,198,196,194,192,190,188,186,184,182,180,178,176,174,172,170,168,166,164,162,160,158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,94,92,90,88,86,84,82,80,78,76,74,72,70,68,66,64,62,60,58,56,54,52,50,48,44,43,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0};

//wavetype storage:
//0 is pulse
//1 is triangle
//2 is saw
//3 is sine
byte type = 0;//initialize as square
byte typecurrent = 8;
byte typelast;
byte typecounter[4];
byte i;

//variables for PW pot monitoring
float pulseWidth;
int pulseWidthScaled;
int PWCurrent;
byte PWTolerance = 8;  //adjust this to increase/decrease stability of PW measurement

//variables for freq pot monitoring
int frequency;
int freqCurrent;
byte freqTolerance = 2;  //adjust this to increase/decrease stability of frequency measurement
unsigned int freqscaled;

byte wave;
long t;
long samplerate;
long period;

//storage variables- I used these to cut down on the math being performed during the interrupt
int sawByte = 0;
byte sawInc;
int triByte = 0;
byte triInc;
int sinNum = 0;
int sinInc;

void setup() {
  
  //set port/pin  mode
  DDRD = 0xFF;//all outputs
  DDRC = 0x00;//all inputs
  DDRB = 0xFF;//all outputs
  //TIMER INTERRUPT SETUP
  
  cli();//disable interrupts
  //timer 1:
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  //set compare match register- 100khz to start
  OCR1A = 159; // = (16 000 000 / 100 000) - 1 = 159
  //turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 bit for 0 prescaler
  TCCR1B |= (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A); 
  
  samplerate = 100000;
  
  PORTB = 0;
  PORTB = 1<<type;
  
  //initialize variables
  frequency = analogRead(A5); //initialize frequency
  freqscaled = frequency+1; //from 1 to ~100
  period = samplerate/freqscaled;
   
  pulseWidth = analogRead(A4);//initalize pulse width
  pulseWidthScaled = int(pulseWidth/1023*period);
  
  triInc = 511/period;
  sawInc = 255/period;
  sinInc = 20000/period;
  
  sei();//enable interrupts
}

void checkFreq() {
  freqCurrent = analogRead(A5);
  if (abs(freqCurrent-frequency)>freqTolerance){//if reading from pot exceeds tolerance
    frequency = freqCurrent;//new frequency- number between 0 and 1024
    freqscaled = frequency+1;//from 1 to ~100
    period = samplerate/freqscaled;
    pulseWidthScaled = int(pulseWidth/1023*period);
    triInc = 511/period;
    if (triInc==0){
      triInc = 1;
    }
    sawInc = 255/period;
    if (sawInc==0){
      sawInc = 1;
    }
    sinInc=20000/period;
  }
}

void checkPW() {
  PWCurrent = analogRead(A4);
  if (abs(PWCurrent-pulseWidth)>PWTolerance){//if reading from pot exceeds tolerance
    pulseWidth = PWCurrent;//new pulse width, val between 0 and 1023
    pulseWidthScaled = int(pulseWidth/1023*period);
  }
}


void checkShape() {//debounce and check states of buttons
//  4 momentary switches control waveshape
//   -pulse connects to A0
//   -triangle A1
//   -saw A2
//   -sine A3
  typelast = typecurrent;
if (digitalRead(A0)==LOW){
  typecurrent  = 1;
}
else if (digitalRead(A1)==LOW){
  typecurrent = 2;
}
else if (digitalRead(A2)==LOW){
  typecurrent = 4;
}
else if (digitalRead(A3)==LOW){
  typecurrent = 8;
}

  for (i=0; i<4; i++){
    if (i==type){
    }
    else{
      if ((typecurrent & (1 << i)) ^ (typelast & (1 << i))){//current diff than prev and debounce
        if ((typecurrent & (1 << i))){//currently depressed
            type = i;//set wave type
        }
        else {
          typecounter[i] = 12;//else set debounce counter to 12
        }
      }
      else if (((typecurrent & (1 << i)) == (typelast & (1 << i )))) {//if current same as prev and diff than debounce
        if (typecounter[i] > 0 && --typecounter[i] == 0) {//decrease debounce counter and check to see if = 0
          if ((typecurrent & (1 << i))){//if debounce counter = 0 toggle debounced state
            type = i;
          }
        }
      }
    }
  }
}
    
 

ISR(TIMER1_COMPA_vect){//timer 1 interrupt
  //increment t and reset each time it reaches period
  t += 1;
  if (t >= period){
    t = 0;
  }
  switch (type) {
    case 0://pulse
    if (pulseWidthScaled <= t) {
      wave = 255;
    }
    else{
      wave = 0;
    }
    break;
    case 1://triangle
    if((period-t) > t) {
      if (t == 0){
        triByte = 0;
      }
      else{
        triByte += triInc;
      }
    }
    else{
      triByte -= triInc;
    }
    if (triByte>255){
      triByte = 255;
    }
    else if (triByte<0){
      triByte = 0;
    }
    wave = triByte;
    break;
    case 2://saw
    if (t=0){
      sawByte=0;
    }
    else{
      sawByte+=sawInc;
    }
    wave = sawByte;
    break;
    case 3://sine
    sinNum = t*sinInc;
    wave = pgm_read_byte_near(sine20000 + sinNum);
    break;
  }

  PORTD = wave;
}

void loop() {
  checkFreq();
  checkShape();
  checkPW();
  PORTB = 1<<type;
}
