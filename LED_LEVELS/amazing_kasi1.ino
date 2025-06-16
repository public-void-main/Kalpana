// C++ code
//
const int LED_LINK=11;
const int PUSHUTTON=2;
int prev_state=LOW;
int i=0;

void setup()
{
  pinMode(PUSHUTTON,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_LINK,OUTPUT);

}

void loop()
{ // Wait for 1000 millisecond(s)
  int buttonState=digitalRead(PUSHUTTON);
  //analogWrite(LED_LINK,0);
  //delay(1000);
  
    if(i==0){
      if(buttonState==HIGH & prev_state==LOW){
  		analogWrite(LED_LINK,255);
      	i++;
      }
    }
  	else if(i==1){
      if(buttonState==HIGH & prev_state==LOW){
      	//while(buttonState==HIGH)
    	analogWrite(LED_LINK,150);
      	i++;
      }
    }
    else{
      if(buttonState==HIGH & prev_state==LOW){
      //while(buttonState==HIGH){
        analogWrite(LED_LINK,0);
       	i=0;
      }
    }
    prev_state=buttonState;
}