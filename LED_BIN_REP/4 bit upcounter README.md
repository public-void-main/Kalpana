<h1>4 bit upcounter using LED's</h1>
<h2><a href="https://www.tinkercad.com/things/3CNXqCb5jN1-fantabulous-densor-vihelmo?sharecode=-e9sbMOMal6nw-ci2o3XY0Pev8COXlWHON0bgMq-V78">Tinkercad</h2>
    Output Pins--The LEDs 
    2^0 --> pin 7
    2^1 --> pin 8
    2^2 --> pin 12
    2^3 --> pin 13


In this task, each of the LED represents a position in the binary format, the rightmost one at 2 power 0 through 2 power 3
0-3 count to 4 positions which can represent numbers 0-15 (16 in number).
As the highest value of 15 is reached, the counter variable is set to zero and again starts from 1.
<list>
<li>
    The output to the pins is given by converting the counter values to binary and pulling the pin to a HIGH if the position of the 2 power has a 1 else, is pulled to a LOW
</li>
</list>

4-LED's with 220 ohm resistors in series for each of them to prevent the overcurrent and burnout of the LED's.
