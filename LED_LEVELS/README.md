<h1>Controlling LED brightness with a button (3 levels -- high, medium, low)</h1>

<h2><a href="https://www.tinkercad.com/things/dKZDIhIZkNM-amazing-kasi?sharecode=5eww1Zz4kXXiwwxScTrHQS9-ZjDU9mmJPwTSPTJyneA">TinkerCad</h2>

      input pins - pin 2 (push button)
      output pins - pin ~11 (enabled PWM) (LED)
      component list - bol(3).csv

Here Pulse width Modulation is made use to adjust the brightness to different levels.
In Arduino it is changed using analogWrite() which takes values 0-255 with 0 the same as LOW
and 255 the same as HIGH.

      Here, LOW -- 0
      MEDIUM -- 150
      HIGH --250

Initially the current state of the button is read using digitalRead().
Here the condition for the push button being pressed is checked when the previous state of the
button is LOW and the current state of the button is HIGH.

A counter variable is used to check the times the button is pressed to alter the brightness accordingly
the counter counts to 0-1 and as it counts up to 2, the value is reset to 0 and is brightness is set to 0.
The LED will remain of the same brightness even if the button is let go as the condition for button unpressed is not set.
