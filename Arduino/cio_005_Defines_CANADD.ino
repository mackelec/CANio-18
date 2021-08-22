/*------------------------------------
 * 
 *    
 * 
 --------------------------------------*/

//--  First CAN address to instruct Outputs
#define CANADD_OUT0             0x0700

//--  First CAN address tranmitting Values and status's
#define CANADD_ANALOG_IN        CANADD_OUT0 + 29


  // ---  address to write single bit
#define CANADD_OUT1   CANADD_OUT0 + 1
#define CANADD_OUT2   CANADD_OUT0 + 2
#define CANADD_OUT3   CANADD_OUT0 + 3
#define CANADD_OUT4   CANADD_OUT0 + 4
#define CANADD_OUT5   CANADD_OUT0 + 5
#define CANADD_OUT6   CANADD_OUT0 + 6
#define CANADD_OUT7   CANADD_OUT0 + 7
#define CANADD_OUT8   CANADD_OUT0 + 8

#define CANADD_PWM0   CANADD_OUT0 + 9
#define CANADD_PWM1   CANADD_OUT0 + 10
#define CANADD_PWM2   CANADD_OUT0 + 11
#define CANADD_PWM3   CANADD_OUT0 + 12
#define CANADD_PWM4   CANADD_OUT0 + 13



#define CANADD_ANALOG_OUT0  CANADD_OUT0 + 14
#define CANADD_ANALOG_OUT1  CANADD_OUT0 + 15
#define CANADD_ANALOG_OUT2  CANADD_OUT0 + 16
#define CANADD_ANALOG_OUT3  CANADD_OUT0 + 17
#define CANADD_ANALOG_OUT4  CANADD_OUT0 + 18

#define CANADD_FREQ             CANADD_OUT0 + 19
#define CANADD_TACHO_PERCENT    CANADD_OUT0 + 20
#define CANADD_RPM              CANADD_OUT0 + 21

#define CANADD_TEMP_PERCENT     CANADD_OUT0 + 22
#define CANADD_TEMPERATURE      CANADD_OUT0 + 23
#define CANADD_FUEL_PERCENT     CANADD_OUT0 + 24
#define CANADD_GAUGES_PERCENT   CANADD_OUT0 + 25
#define CANADD_GAUGES_VALUES    CANADD_OUT0 + 26
#define CANADD_CURRENT          CANADD_OUT0 + 27
#define CANADD_POWER            CANADD_OUT0 + 28

#define CANADD_VOLTAGE          CANADD_ANALOG_IN + 1
#define CANADD_STATE_OUT        CANADD_ANALOG_IN + 2
#define CANADD_STATE_PWM        CANADD_ANALOG_IN + 3
#define CANADD_STATE_FREQ       CANADD_ANALOG_IN + 4




uint8_t fuelPercentPWM[] = {
                            1,2,3,4,5,6,7,8,9,10,
                            11,12,13,14,15,16,17,18,19,20
                            };
uint8_t tempPercentPWM[] = {
                            1,2,3,4,5,6,7,8,9,10,
                            11,12,13,14,15,16,17,18,19,20
                            };
