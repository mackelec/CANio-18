## using Python to Create a Lookup table.

### Why the Lookup Table.

The Temperature and Fuel Gauges are very non-linear gauges.  (Even the tacho wasn't perfectly linear) For the purposes of driving the gauges from various other controllers within the car, over CAN bus - it is easier to linearise the gauges, say send a Percentage value to a gauge rather than some PWM value.  

A Lookup table is very effecienct to ue in realtime, the stm32F103 has lots of flash ROM not being used, so this was the direction Taken.

### Why use Python

Originally I used the arduino code to create the Lookup table.  Using python was more conveniant since you more easily get to inspect the generated table.  The script outputs are ready to copy and paste into the arduino code.

### Using the Script

The arrays:

* gaugeTempCal
* gaugeFuelCal
* gaugeTachoCal

Need to entered using the values of your gauges.  There are no limit to the number of points you add, this will just make the calibration more linear.
* Calibration elements for Temp and Fuel Gauges, The first element of the pair is percent and the second element is the PWM value.
* Calibration elements of Tacho. The first element is RPM and the second element is the frequency.
