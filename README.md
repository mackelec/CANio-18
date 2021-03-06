# CANio-18

### CAN Bus module designed to drive analog Car gauges (Tacho, Fuel, Temp) and lamps; using stm32F103 and Arduino firmware.
 

![CANio-18](https://github.com/mackelec/CANio-18/blob/main/images/CANio-18.PNG)


### Decription

This board was designed as a general purpose module using CAN Bus to expand the number of I/O.  Inspired by my EV conversion project where This module will be controlling the existing Dashboard warning lights and gauges.  

This module is a compact, low cost, using the stm32F103C8 processor (same as BluePill), optimised for smd assembly by JLCPCB.
The module has 8 mosfet driven outputs, 4 analogue outputs, 4 analogue inputs, internal battery (12v) voltage sensor and a ttl serial port.

### Special Gauge Features

* Tacho can be set by sending RPM value
* Tacho, Fuel, and Temp gauges can be set by sending Percentage value.
* Temperature Gauge can be set by sending temperate.

### Special Tacho Features

* Tacho can be used as Ampere Gauge, by sending Current (Amps) value.
* Tacho can be used as kWatt (power) Gauge, by sending Power (kWatts) value.

### Features

* CAN bus operated.  (with 120 ohm terminator jumper.)
* STM32F103C8 processor.  64k program memory 20k RAM.
* Arduino IDE platform.
* 60mm x 100mm.
* 8 Outputs:
  * 7 outputs are Ground switching (open Drain).
  * 2 of the above outputs can be jumpered to +12 (battery) switching.
  * 1 output is PUSH PULL. (PWM)
  * 4 of the outputs are PWM able.
* 4 Analogue Outputs, specifically designed for gauges like Fuel and Temp.
* 4 Analalogue Inputs, 0 - 15v range.
  * 12 bit resolution (4096 steps)
  * 2 inputs can be configured to 0 - 5v range.
* Battery (12V) voltage sensor (internal).
* DB25 male connector.
* Each Input or Output is simply accessed by basic CAN Buss messages. 
* Software can be customised using Arduino IDE.
* Serial port (ttl).  Could be used to interface to GPS module etc.

#### Outputs

The outputs are mosfet driven which will drive modest outputs such as Dash lights and your average automotive relay (Don't directly drive loads such as the Brake light circuit).  There are 8 outputs, one is 12v PUSH PULL, the rest are Ground switching (Open Drain) with 2 that are jumperable to 12 volt switching.  

Four of the Outputs are PWM able.  The Push Pull output is PWM able but is also able to vary it's Frequency.  The intention in this case is to drive the Tachometer.

#### Analogue Outputs

Four analogue outputs specifically designed to connect to gauges such as Fuel, Temperature, Oil pressure etc.  In the case of my Bravo B2500, the gauges appears to be an internal 9v source with a 200 ohm impedance, and sensors operate in the range of 20 to 200 ohms (which is typical).  The analogue outputs are designed to match these requirements.

#### Analogue Inputs

Four 12 bit analogue inputs, diode protected, with 0-15V range inputs.  Two of the inputs can be configured to 0 - 5v inputs. (Jumper)
The module has In addition, a fifth internal sensor to measure the 12v battery.


#### Software

Software is yet to be done.

*  CAN address for each output, and an additional address for all 8 outputs.
*  CAN address for each PWM output.
*  CAN address to set Frequency of the Push Pull output.
*  CAN address to send all analogue inputs as adc value.  Scan rate to be defined.


#### DB25 Connector

I decided to use a DB25 connector because I was aiming this module to be low cost and to use a IP66 connector would have cost more than the module itself.  The DB25 is a reliable connector, contacts good for one amp, and will handle a certain amount of enviromental abuse.  I'll either be using this module inside the Cabin or I'll use grommiting to weather-seal.  

![Pinout](https://github.com/mackelec/CANio-18/blob/main/images/CANio-18%20DB25%20pinout.PNG)


#### Assembly

Very few through hole parts need to be loaded.  
*  J1 and J2 are already bridged for the analogue ports to be all set to 0 -12v range.
PCB bridge track (solder side) would need to be cut to use the jumper.
*  Capacitor C22, 470uf, could be omitted as it is in parallel with 5 x 22uF ceramic capacitors.


