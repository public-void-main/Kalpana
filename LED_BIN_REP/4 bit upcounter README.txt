2) 4 bit upcounter using LED's

Output Pins--The LED's 
2^0 --> pin 7
2^1 --> pin 8
2^2 --> pin 12
2^3 --> pin 13

Input pin --> 2 (push button input)

In this task, each of the LED represents a position in the binary format, the rightmost one at 2 power 0 through 2 power 3
0-3 count to 4 positions which can represent numbers 0-15 (16 in number).

==> It makes the use of a push button to increment the values of the counter based on the different states of the push button,
    when the previous state of the push button is LOW and the current state is HIGH, it increments the counter variable till its
    less than 16 and the LED's are set to HIGH/LOW based on the counter value
-- The condition of the LED LOW/HIGH is determined using the binary AND operator. if a binary 1/2/4/8 is AND with any other number,
   its presence will give us a binary 1/2/4/8 which when enclosed in an if condition by default is taken as TRUE. On this condition,
   the LED is pulled to a HIGH.
When the counter increments to a different value and the if leads to a false then the LED is pulled to a LOW with the else of that particular if.
the LED's are pulled to a HIGH/LOW using digitalWrite()

As the highest value of 15 is reached, the counter variable is set to zero and again starts from 1.

component list: bom(1).csv

4-LED's with 500 ohm resistors in series for each of them to prevent the overcurrent and burnout of the LED's.
The push button is connected with a resistor in parallel to prevent mis-reading of the electrical signal as HIGH/LOW.
The resistor in parallel ensures that when the button is pressed, it is read as HIGH, else LOW when it is unpressed.
