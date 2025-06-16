
// C++ code
//
const int LED_1=7;
const int LED_2=8;
const int LED_3=12;
const int LED_4=13;
const int PUSH=2;

int count=0;
int i=1;
int prev_state=LOW;
//int i=0;
//int j=0;
//int k=0;
//int l=0;

void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(PUSH, INPUT);
  Serial.begin(9600);
}
//LED_2==>2
//LED_1==>1
//LED_3==>4
//LED_4==>8

void loop()
{
int state=digitalRead(PUSH);
  
  //digitalWrite(LED_1,HIGH);
    if(count<16){
      i=1;
  	if(state==HIGH & prev_state==LOW){
      
      if((count & i)>0){
      digitalWrite(LED_1,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_1,LOW);
      }
      
      if((count & i<<1)>0){
      digitalWrite(LED_2,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_2,LOW);
      }
      
      if((count & i<<2)>0){
      digitalWrite(LED_3,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_3,LOW);
      }
      
      if((count & i<<3)>0){
      digitalWrite(LED_4,HIGH);
        Serial.println(count);
      }
      else{
        digitalWrite(LED_4,LOW);
      }
      Serial.println("low");
      
      //digitalWrite(LED_2,count & i<<1);
      //digitalWrite(LED_3,count & i<<2);
      //digitalWrite(LED_4,count & i<<3);
      
      
      //digitalWrite(LED_1,count & 0b0001);
      //digitalWrite(LED_2,count & 0b0010);
      //digitalWrite(LED_3,count & 0b0100);
      //digitalWrite(LED_4,count & 0b1000);
      
      
      //if(count & 0b0001)
      //  digitalWrite(LED_1,HIGH);
      //else
      //  digitalWrite(LED_1,LOW);
      
      //if(count & 0b0010)
      //  digitalWrite(LED_2,HIGH);
      //else
      //  digitalWrite(LED_2,LOW);
      
      //if(count & 0b0100)
      //  digitalWrite(LED_3,HIGH);
      //else
      //  digitalWrite(LED_3,LOW);
      
      //if(count & 0b1000)
      //  digitalWrite(LED_4,HIGH);
      //else
      //  digitalWrite(LED_4,LOW);
      
   	//if(i==1){
    	//i=0;
   		//digitalWrite(LED_1,HIGH);
        //}else{i++;digitalWrite(LED_1,LOW);}
    //if(j==2){
    //	j=0;
    //	digitalWrite(LED_2,HIGH);
    //    }else{j++;digitalWrite(LED_2,LOW);}
    //if(k==4){
    //	k=0;
    //	digitalWrite(LED_3,HIGH);
    //   }else{k++;digitalWrite(LED_3,LOW);}
    //if(l==7){
    //	l=1;
    //	digitalWrite(LED_4,HIGH);
    //	}else{l++;digitalWrite(LED_4,LOW);}
    	count=count+1;
    }
    
  }else{
     count=0;
     }
  prev_state=state;
  //else{
  //digitalWrite(LED_1,LOW);
  //digitalWrite(LED_2,LOW);
  //digitalWrite(LED_3,LOW);
  //digitalWrite(LED_4,LOW);
  //}
}