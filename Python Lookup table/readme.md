## Creating Lookup table.

### Why the Lookup Table.

The Temperature and Fuel Gauges are very non-linear gauges.  For the purposes of driving the gauges from various other controllers within the car, over CAN bus - it is easier to linearise the gauges, say send a Percentage value to a gauge rather than some PWM value.  

One could try to create an polynomial equation to determine the 
Originally I used the arduino code to create 
