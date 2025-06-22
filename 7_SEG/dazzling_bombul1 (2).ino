int count=1;
int counter=0;
int LED_ARRAY_1[]={2,3,4,5};
int LED_ARRAY_2[]={6,7,8,9};

void setup()
{
  for(int i=0;i<4;i++){
  	pinMode(LED_ARRAY_1[i],OUTPUT);
    pinMode(LED_ARRAY_2[i],OUTPUT);
  }
}
void convert_bin(int tens,int ones){
    int tens_bin[]={0,0,0,0};
    int ones_bin[]={0,0,0,0};
    for(int i=0;i<4;i++){
    tens_bin[i]=(tens & (1<<i))?1:0;
    ones_bin[i]=(ones & (1<<i))?1:0;
    digitalWrite(LED_ARRAY_1[i],ones_bin[i]);
    digitalWrite(LED_ARRAY_2[i],tens_bin[i]);
    }
}
void loop()
{
 if(counter<79)convert_bin(count/10,count%10);
 if(counter<39& count>0){
    count++;counter++;
 }else{
   count--;counter++;
 }
 
  
  delay(750);
 }