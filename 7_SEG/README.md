<h1>Use 7-segment display to count from 1 to 40 and 40 to 1 using two 7-seg displays</h1>
<h2><a href="https://www.tinkercad.com/things/5mcZamV5ROZ-dazzling-bombul?sharecode=GcdYWLw-WfvktFN7FDuxCwjELswPpe5aJwxLslDMMb8"> Tinkercad </a></h2>

	7 seg decoder (ones)  
 		pin 2 -- inp1
   		pin 3 -- inp2
     	pin 4 -- inp3
       	pin 5 -- inp4
	7 seg decoder (tens) 
 		pin 6 -- inp1
   		pin 7 -- inp2
     	pin 8 -- inp3
       	pin 9 -- inp4

initially, for considering that each 7-seg display has 7 input/output pins,
and all the digital pins of the Arduino UNO R3 has 2 through 13 pins where a few of the pins have PWM enabled for output,
making this a bit difficult to arrange the inputs and outputs.

this is made easy when we choose to use Binary coded Decimals to 7 segment converter or simply 7-seg decoders.
These take 4-bit binary input and output to the 7-segment compatible output (8 output pins each).

The logic of the code is as follows:
<list>
<li>Arrays of input pins for both 7-seg displays are made LED_ARRAY_1 and LED_ARRAY_2</li>
<li>convert the count values to decimal if the counter values don't exceed 79 (0-79)</li>
<li>The binary to decimal conversion uses the binary AND 
operator and left shift to check and pull the pin to a high(the 7-seg displays used have a common cathode) 
by calling the the binary values as an array and assigning it to the LED_ARRAY_1/2 using a for loop</li>
</list>
<pre>'''
	
for(int i=0;i<4;i++){
tens_bin[i]=(tens & (1<<i))?1:0;
ones_bin[i]=(ones & (1<<i))?1:0;
digitalWrite(LED_ARRAY_1[i],ones_bin[i]);
digitalWrite(LED_ARRAY_2[i],tens_bin[i]);
}
'''</pre>
<list>
<li>The count is incremented till the counter reaches 40 and count greater than 0 and then decrements till the counter reaches 80</li>
<pre>'''
	
 if(counter<79)convert_bin(count/10,count%10);//convert_bin converts the decimal values to 4-bit binary values
 if(counter<39& count>0){
    count++;counter++;
 }else{
   count--;counter++;
 }</pre>
</list>
