// C++ code
//
int PUSH_UP=10;
int PUSH_DOWN=11;
//counters
int count=0;
int i=0;
//the ones 7-seg display
int LED_BCD_11=2;
int LED_BCD_12=3;
int LED_BCD_13=4;
int LED_BCD_14=7;
//tens 7-seg display
int LED_BCD_21=9;
int LED_BCD_22=8;
int LED_BCD_23=12;
int LED_BCD_24=13;
//prev state condition trackers
int PREV_STATE_1=LOW;
int PREV_STATE_2=LOW;

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  //set input pins
  pinMode(PUSH_UP,INPUT);
  pinMode(PUSH_DOWN,INPUT);
  //set output pins for the ones place 7-seg display(BCD)
  pinMode(LED_BCD_11,OUTPUT);
  pinMode(LED_BCD_12,OUTPUT);
  pinMode(LED_BCD_13,OUTPUT);
  pinMode(LED_BCD_14,OUTPUT);
  //set output pins for the tens place 7-seg display(BCD)
  pinMode(LED_BCD_21,OUTPUT);
  pinMode(LED_BCD_22,OUTPUT);
  pinMode(LED_BCD_23,OUTPUT);
  pinMode(LED_BCD_24,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read the button states if pressed or not 
  int STATE_1=digitalRead(PUSH_UP);
  int STATE_2=digitalRead(PUSH_DOWN);
  //max and min value condition
  if(count<=40 & count>= 0){
    //counting up and down
  	if(STATE_1==HIGH & PREV_STATE_1==LOW){
      count=count+1;
    }
     if(STATE_2==HIGH & PREV_STATE_2==LOW){
      count=count-1;
    }
    
    i=1;
    //converting to binary for the BCD input pins if the button states are high
    if((STATE_1==HIGH & PREV_STATE_1==LOW)||(PREV_STATE_2==LOW & STATE_2==HIGH)){
      //if(count/10 > 0){
      
      //tens to binary conversion for the second 7-seg diplay
      int tens=count/10;
      if((tens & i)>0){
      	analogWrite(LED_BCD_21,255);
        Serial.println(count);
      }
      else{
        analogWrite(LED_BCD_21,0);
      }
      
      if((tens & i<<1)>0){
      digitalWrite(LED_BCD_22,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_22,LOW);
      }
      
      if((tens & i<<2)>0){
      digitalWrite(LED_BCD_23,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_23,LOW);
      }
      
      if((tens & i<<3)>0){
      digitalWrite(LED_BCD_24,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_24,LOW);
      }
      ////////////////
      //conversion of ones digits to binary for the first 7-seg display
       if(((count%10) & i)>0){
      	analogWrite(LED_BCD_11,255);
        Serial.println(count);
      }
      else{
        analogWrite(LED_BCD_11,0);
      }
      
      if(((count%10) & i<<1)>0){
      digitalWrite(LED_BCD_12,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_12,LOW);
      }
      
      if(((count%10) & i<<2)>0){
      digitalWrite(LED_BCD_13,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_13,LOW);
      }
      
      if(((count%10) & i<<3)>0){
      digitalWrite(LED_BCD_14,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_BCD_14,LOW);
      }   
     // }     
    }
   }
  //updating the states
    PREV_STATE_2=STATE_2;
    PREV_STATE_1=STATE_1;
}