3) Use 7-segment display to count from 1 to 40 and 40 to 1 using two 7-seg displays
input pins(push buttons):
push buttons - pin ~10 (up) pin ~11(down)
7 seg decoder (ones) - pin 2 -- inp1, pin 3 -- inp2, pin 4 -- inp3, pin 7 -- inp4
7 seg decoder (tens) - pin 9 -- inp 1, pin 8 -- inp 2, pin 12 -- inp3, pin 13 -- inp4

initially, for considering that each 7-seg display has 7 input pins,
and all the digital pins of the Arduino UNO R3 has 2 through 13 pins where a few of the pins have PWM enabled for output,
making this a bit difficult to arrange the inputs and outputs.

this is made easy when we choose to use Binary coded Decimals to 7 segment converters or simply 7-seg decoders.
These take 4-bit binary input and output to the 7-segment compatible output (8 output pins each).

The logic of the code is as follows:
==> It reads the state of the push buttons and takes in the previous values of the push buttons
==> The push button states are compared and an action is performed only when the current state is HIGH,
    and the previous state is LOW which is a qualifying condition for "button pressed".
==> when the button is pressed, if the counter value is between 0-40 inclusive, to consider for the two 7-segment decoders,
    one for each digit in the two digit numbers, the quotient values of the counter are taken and converted into decimal and
    input through the input pins of the second 7-seg decoder. The remainder of the counter variable are converted to binary and are input to the first 7-seg decoder.
	- the logic for the decimal conversion is using the binary AND 
	  operator and left shift to check and pull the pin to a high(the 7-seg displays used have a common cathode)
	  else low each time the button is pressed to avoid the illusion of the counter getting stuck at the previous number.
==> while decimal inputs through different pins of the Arduino, for some which take analog inputs,
    for the ones which have PWM enabled outputs, the digitalWrite() is substituted with analogWrite() set to the value of 255 for a HIGH.
==>Finally the previous states are updated

==> Upon the press of one push button the counter can be counted up and the other push button can be pressed to count the counter down

