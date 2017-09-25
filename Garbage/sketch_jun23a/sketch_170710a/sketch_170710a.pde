int y=250;
int x=0; 
int f=0;
void setup(){

  size(500,500);
  background(0);
} 

void draw(){ 
  
  if(f==0){
  
      fill(0,random(255),random(255));
      ellipse(x,y,20,20); 
      stroke(random(255),0,random(255)); 
      strokeWeight(2);
      x++; 
  }
  if(x==495){
  f=1;  
  }
  if(f==1){
  
        fill(random(255),0,0);
        ellipse(x,y,20,20); 
        stroke(random(255),random(150),0); 
        strokeWeight(2);
        x--; 
  }
  if(x==5){
  
   
    f=0;
    
  }
   
 }