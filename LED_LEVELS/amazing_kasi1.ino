const int LED_LINK=11;
const int PUSHUTTON=2;
int prev_state=LOW;
int i=0;

void setup()
{
  pinMode(PUSHUTTON,INPUT);
  pinMode(LED_LINK,OUTPUT);

}

void loop()
{ 
  int buttonState=digitalRead(PUSHUTTON);
    if(i==0){
      if(buttonState==HIGH & prev_state==LOW){
  		analogWrite(LED_LINK,255);
      	i++;
      }
    }
  	else if(i==1){
      if(buttonState==HIGH & prev_state==LOW){
    	analogWrite(LED_LINK,127);
      	i++;
      }
    }
    else{
      if(buttonState==HIGH & prev_state==LOW){
        analogWrite(LED_LINK,0);
       	i=0;
      }
    }
    prev_state=buttonState;
}