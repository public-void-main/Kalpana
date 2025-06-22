const int LED_1=7;
const int LED_2=8;
const int LED_3=12;
const int LED_4=13;

int count=0;
int i=1;

void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}
//LED_2==>2
//LED_1==>1
//LED_3==>4
//LED_4==>8

void loop()
{
    if(count<16){
      i=1;  
      
      if((count & i)>0){
      	digitalWrite(LED_1,HIGH);
      }
      else{
        digitalWrite(LED_1,LOW);
      }
      
      if((count & i<<1)>0){
      	digitalWrite(LED_2,HIGH);
      }
      else{
        digitalWrite(LED_2,LOW);
      }
      
      if(count & i<<2){
      	digitalWrite(LED_3,HIGH);
      }
      else{
        digitalWrite(LED_3,LOW);
      }
      
      if(count & i<<3){
      	digitalWrite(LED_4,HIGH);
      }
      else{
        digitalWrite(LED_4,LOW);
      }
    count++;
  }else{
     count=0;
     }
  delay(1000);
}