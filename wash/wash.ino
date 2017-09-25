#include <Stepper.h>  
#include "Timer.h" 

void Modes(int ); 
void Types(int ); 
void washTime(int ); 
void washSpeed(int ); 
void START(); 
void STOP(); 
void ChangeRotation();

Timer Time;

#define steps 200

Stepper pins(steps,6,7,8,9);

int pst=HIGH; 
int cst; 


int but[4]={13,12,11,10}; 
int motor[4]={2,3,4,5}; 

int count=0;

int ret[4]; 

int reset=0;

void setup(){


	Serial.begin(9600);
	for(int i=0;i<4;i++){

	pinMode(but[i],INPUT); 
	

	} 

	for(int i=0;i<4;i++){

		pinMode(motor[i],OUTPUT);

	}

} 


void loop(){


	for(int i=0;i<4;i++){
	
   ret[i]=digitalRead(but[i]);				//ret[0]=Types: ret[1]=modes: ret[2]=Time: ret[3]=speed 

	} 

	if(ret[0]!=pst){

		if(ret[0]==LOW){


	
			count++;	


		} 
			Modes(count);
			pst=ret[0]; 

			if(count>10){

			count=reset;

			}
		
	 

	if(ret[1]!=pst){

		if(ret[1]==LOW){

			count++;
		
		 } 

		Types(count); 
		pst=ret[1]; 

		
			if(count>10){

				count=reset;

			}	 
	}
		if(ret[2]!=pst){


			if(ret[2]==LOW){
				
				count++;
			
			} 

			washTime(count); 
			pst=ret[2]; 
		
			if(count>10){

				count=reset;

			} 


		
		}
	
	}
	
}
  


		void Modes(int value){

			switch(value){

			
			
				Serial.println("Welcome to  mode setting"); 

				/*Serial.println("1. -------------------------- 
						2. --------------------------
						3. --------------------------
						4. --------------------------
						5. --------------------------
						6. --------------------------
						7. --------------------------
						8. --------------------------
						9. --------------------------
						10.---------------------	");*/ 
			case 1: 
	
				Serial.println("This is mode 1..."); 
        break;
			case 2: 
				
				Serial.println("This is mode 2"); 
        break;
			case 3: 

				Serial.println("This is mode 3"); 
        break;
			case 4: 
		
				Serial.println("This is mode 4"); 
        break;
			case 5: 

				Serial.println("This is mode 5");
        break;
			case 6: 
				
				Serial.println("This is mode 6");  
        break;
			case 7: 
				
				Serial.println("This is mode 7"); 
	      break;
			case 8: 
				
				Serial.println("This is mode 8"); 
	      break;
			case 9: 

				Serial.println("This is mode 9"); 
        break;
			case 10: 

				Serial.println("This is mode 10"); 
        break;
			default : 
				
				Serial.println("Please choose a valid option");
        break;
			}


		} 



			void Types(int value){


				switch(value){

			
				case 1: 
				
					Serial.println("This is type 1 cloth"); 
          break;
				case 2: 

					Serial.println("This is type 2 cloth");
          break;
				
				case 3: 
			
					Serial.println("This is type 3 cloth"); 
          break;
          
				case 4: 

					Serial.println("This is type 4 cloth"); 
          break;
          
				case 5: 
		
					Serial.println("This is type 5 cloth") ; 
          break;
				case 6: 

					Serial.println("This is type 6  cloth") ;
          break;
				case 7: 
			
					Serial.println("This is type 7 cloth");
			     break;

				}

			} 

				void washTime(int value){

				
					Time.every(1000,START); 

					Time.after(10000*value,STOP);


				}  

					void washSpeed(int value){ 





					}

void START(){ 


		Time.every(5000,ChangeRotation); 

		for(int i=0;i<4;i++){


			digitalWrite(motor[i],HIGH); 
			i++;

		} 

		for(int i=1;i<4;i++){

			digitalWrite(motor[i],LOW); 
			i++;
		}		


} 


void STOP(){

	for(int i=0;i<4;i++){

		digitalWrite(motor[i],LOW);

	}


} 

void ChangeRotation(){

	for(int i=1;i<4;i++){

		digitalWrite(motor[i],HIGH); 
		i++;

	}

  	for(int i=0;i<4;i++){

		digitalWrite(motor[i],LOW); 
		i++;
		
	}


}

