
#include <Streaming.h>
#include <PString.h>
#include <eXoCAN.h>

HardwareTimer *tachoTimer;

uint32_t channel8;

 
HardwareSerial Serial3(PB11,PB10);
eXoCAN can;

#define REPORT_CAN_MESSAGES     0

#define LED      PC13 //LED_BUILTIN


#define pin_AIN1  PA0
#define pin_AIN2  PA1
#define pin_AIN3  PA4
#define pin_AIN4  PA5
#define pin_AIN_VIN PB1

#define pin_PWM1  PA8
#define pin_PWM2  PA6
#define pin_PWM3  PA7
#define pin_PWM4  PB0

#define pin_OUT1  PB12
#define pin_OUT2  PB13
#define pin_OUT3  PB14
#define pin_OUT4  PB15
#define pin_OUT5  PB9
#define pin_OUT6  PB8
#define pin_OUT7  PB7
#define pin_OUT8  PB6

#define pin_GAUGE_TEMP  pin_PWM1
#define pin_GAUGE_FUEL  pin_PWM2

#define LAMP_SEDIMENTER     pin_OUT4
#define LAMP_ALTERNATOR     pin_OUT3  
#define LAMP_OIL            pin_OUT6
#define LAMP_GLOWPLUG       pin_OUT5

#define IDX_TEMP        1
#define IDX_FUEL        2

bool outputs[]          = {0,0,0,0,0,0,0,0};
byte pwmOutputs[]       = {0,0,0,0};
byte analogOutputs[]    = {0,0,0,0,0}; 
uint16_t analogInputs[] = {0,0,0,0};
uint16_t Frequency      = 0;
uint16_t RPM = 0;
int16_t temperature = 0;
uint16_t fuel = 0;

int32_t avgInputs[] = {0,0,0,0,0};
uint16_t adcInputs[] = {0,0,0,0,0};


#define RPM_PERCENT_0     1
#define RPM_PERCENT_100   2318
#define TEMP_PERCENT_0    30
#define TEMP_PERCENT_100  240
#define FUEL_PERCENT_0    30
#define FUEL_PERCENT_100  240
#define RPM_MIN           0
#define RPM_MAX           6000
#define TEMP_MIN          30 //-10
#define TEMP_MAX          70 //150
#define CURRENT_MIN       0
#define CURRENT_MAX       300
#define POWER_MIN         0
#define POWER_MAX         120



#define SEND_ANALOG           1000
#define SEND_VOLTAGE          0
#define SEND_FREQUENCY        0
#define SEND_PWM              0
//#define SEND_ANALOG_CHANGE    128  // adc change






void setup() {
    //----  CAN speed choices  
    //----  BR125K  BR250K  BR500K BR1M
  
  can.begin(STD_ID_LEN, BR125K,PORTA_11_12_XCVR);
  setCanMask();
  analogReadResolution(12);
  Serial.begin(115200);
  Serial3.begin(9600);
  
  pinMode(LED,OUTPUT);
  pinMode(pin_OUT1,OUTPUT);
  pinMode(pin_OUT2,OUTPUT);
  pinMode(pin_OUT3,OUTPUT);
  pinMode(pin_OUT4,OUTPUT);
  pinMode(pin_OUT5,OUTPUT);
  pinMode(pin_OUT6,OUTPUT);
  pinMode(pin_OUT7,OUTPUT);
  pinMode(pin_OUT8,OUTPUT);
  
  analogWriteFrequency(4000);
  setup_TachoTimer();
  digitalWrite(LED,LOW);
  Serial.println("initialising ...");
  delay(100);
  Serial.println("CANio-18 verion 003");
  runStartup();
  //fillLookups();

  
}



void setup_TachoTimer()
{
  //channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(pin_OUT8), PinMap_PWM));
  TIM_TypeDef *Instance = TIM4;
  tachoTimer = new HardwareTimer(Instance); 
  tachoTimer->setPWM(1, pin_OUT8, 1, 50);  // ch1,  , 1000 Hz,50% duty)
}
