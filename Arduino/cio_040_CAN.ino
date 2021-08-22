#define data  can.rxData.bytes
union Data 
{
  byte b[8];
  uint8_t ui8[8];
  uint16_t ui[4];
  int16_t i[4];
};


long time_Analog,time_PWM,time_Frequency,time_Voltage;

bool sentCanInputs;
bool sendingCANupdates;
bool sendingCANVoltage;



void setCanMask()
{
  can.filterMask16Init(0, CANADD_OUT0, 0x7E0);
}

void readCAN()
{
  union Data D;
  uint16_t fp,tp,r;
  can.rxMsgLen = can.receive(can.id, can.fltIdx, D.b);
  if (can.rxMsgLen<1) return;
  if (REPORT_CAN_MESSAGES) reportCAN(&can,D.b);
  switch (can.id)
  {
    case CANADD_OUT0:
      for (int i=0;i<8;i++)
      {
        //outputs[i] = (bool) can.rxData.bytes[i];
        outputs[i] = (bool) D.b[i];
      }
//        pinMode(pin_OUT5,OUTPUT);
//        pinMode(pin_OUT6,OUTPUT);
//        pinMode(pin_OUT7,OUTPUT);
//        pinMode(pin_OUT8,OUTPUT);
      digitalWrite(pin_OUT1, outputs[0]);
      digitalWrite(pin_OUT2, outputs[1]);
      digitalWrite(pin_OUT3, outputs[2]);
      digitalWrite(pin_OUT4, outputs[3]);
      digitalWrite(pin_OUT5, outputs[4]);
      digitalWrite(pin_OUT6, outputs[5]);
      digitalWrite(pin_OUT7, outputs[6]);
      digitalWrite(pin_OUT8, outputs[7]);
      break;
    case CANADD_OUT1:
      outputs[0] = (bool) D.b[0];
      digitalWrite(pin_OUT1, outputs[0]);
      break;
    case CANADD_OUT2:
      outputs[1] = (bool) D.b[0];
      digitalWrite(pin_OUT2, outputs[1]);
      break;
    case CANADD_OUT3:
      outputs[2] = (bool) D.b[0];
      digitalWrite(pin_OUT3, outputs[2]);
      break;
    case CANADD_OUT4:
      outputs[3] = (bool) D.b[0];
      digitalWrite(pin_OUT4, outputs[3]);
      break;
    case CANADD_OUT5:
      outputs[4] = (bool) D.b[0];
      pinMode(pin_OUT5,OUTPUT);
      digitalWrite(pin_OUT5, outputs[4]);
      break;
    case CANADD_OUT6:
      outputs[5] = (bool) D.b[0];
      pinMode(pin_OUT6,OUTPUT);
      digitalWrite(pin_OUT6, outputs[5]);
      break;
    case CANADD_OUT7:
      outputs[6] = (bool) D.b[0];
      pinMode(pin_OUT7,OUTPUT);
      digitalWrite(pin_OUT7, outputs[6]);
      break;
    case CANADD_OUT8:
      pinMode(pin_OUT8,OUTPUT);
      outputs[7] = (bool) D.b[0];
      //noTone(pin_OUT8);
      pinMode(pin_OUT8,OUTPUT);
      digitalWrite(pin_OUT8, outputs[7]);
      break;
    case CANADD_PWM0:
      for (int i=0;i<4;i++)
      {
        pwmOutputs[i] =  D.b[i];
      }
      analogWrite(pin_OUT5,pwmOutputs[0]);
      analogWrite(pin_OUT6,pwmOutputs[1]);
      analogWrite(pin_OUT7,pwmOutputs[2]);
      analogWrite(pin_OUT8,pwmOutputs[3]);
      break;
    case CANADD_PWM1:
      pwmOutputs[0] = D.b[0];
      analogWrite(pin_OUT5,pwmOutputs[0]);
      break;
    case CANADD_PWM2:
      pwmOutputs[1] = D.b[0];
      analogWrite(pin_OUT6,pwmOutputs[1]);
      break;
    case CANADD_PWM3:
      pwmOutputs[2] = D.b[0];
      analogWrite(pin_OUT7,pwmOutputs[2]);
      break;
    case CANADD_PWM4:
      pwmOutputs[3] = D.b[0];
      analogWrite(pin_OUT8,pwmOutputs[3]);
      break;
    case CANADD_FREQ:
      Frequency = D.ui[0];
      setTachoFreq((uint32_t)Frequency);
      break;
    case CANADD_ANALOG_OUT0:
      for (int i=0;i<4;i++)
      {
        analogOutputs[i] =  D.b[i];
      }
      analogWrite(pin_PWM1,analogOutputs[0]);
      analogWrite(pin_PWM2,analogOutputs[1]);
      analogWrite(pin_PWM3,analogOutputs[2]);
      analogWrite(pin_PWM4,analogOutputs[3]);
      break;
    case CANADD_ANALOG_OUT1:
      analogOutputs[0] = D.b[0];
      analogWrite(pin_PWM1,analogOutputs[0]);
      break; 
    case CANADD_ANALOG_OUT2:
      analogOutputs[1] = D.b[0];
      analogWrite(pin_PWM2,analogOutputs[1]);
      break; 
    case CANADD_ANALOG_OUT3:
      analogOutputs[2] = D.b[0];
      analogWrite(pin_PWM3,analogOutputs[2]);
      break; 
    case CANADD_ANALOG_OUT4:
      analogOutputs[3] = D.b[0];
      analogWrite(pin_PWM4,analogOutputs[3]);
      break;  
    case CANADD_TACHO_PERCENT:
      fp = D.ui[0];
      gauge_FrequencyP(fp);
      break;
    case CANADD_RPM:
      RPM = D.ui[0];
      Frequency = gaugeRPMLookup[RPM];
      setTachoFreq((uint32_t)Frequency);
      break;
    case CANADD_CURRENT:
    
      r = map(D.i[0],CURRENT_MIN,CURRENT_MAX,0,RPM_MAX);
      Frequency = gaugeRPMLookup[r];
      setTachoFreq((uint32_t)Frequency); 
      break;
    case CANADD_POWER:
      r = map(fp,POWER_MIN,POWER_MAX,0,RPM_MAX);
      Frequency = gaugeRPMLookup[r]; 
      setTachoFreq((uint32_t)Frequency); 
      break;
    case CANADD_TEMPERATURE:
      tp = map(D.i[0],TEMP_MIN,TEMP_MAX,0,100);
      gauge_TempP(tp);
      break;
    case CANADD_TEMP_PERCENT:
      gauge_TempP(D.ui[0]);
      break;
    case CANADD_FUEL_PERCENT:
      gauge_FuelP(D.ui[0]);
      break;
    case CANADD_GAUGES_PERCENT:
      gauge_FrequencyP(D.ui[0]);
      gauge_TempP(D.ui[1]);
      gauge_FuelP(D.ui[2]);
      break;
    case CANADD_GAUGES_VALUES:
      RPM = D.ui[0];
      fp = map(RPM,RPM_MIN,RPM_MAX,RPM_PERCENT_0,RPM_PERCENT_100);
      gauge_FrequencyP(fp);
      tp = map(D.i[1],TEMP_MIN,TEMP_MAX,TEMP_PERCENT_0,TEMP_PERCENT_100);
      gauge_TempP(tp);
      gauge_FuelP(D.ui[2]);
      break;
  }
  
}


void gauge_FrequencyP(uint16_t fp)
{
  int j = constrain(fp,0,100);
  int r = map(j,0,100,0,RPM_MAX);
  Frequency = gaugeRPMLookup[r];
  setTachoFreq((uint32_t)Frequency); 
}

void gauge_TempP(int16_t tp)
{
  int j = constrain(tp,0,100);
  analogOutputs[IDX_TEMP] = gaugeTempLookup[j];
  analogWrite(pin_GAUGE_TEMP,analogOutputs[IDX_TEMP]);
}

void gauge_FuelP(int16_t fp)
{
  int j = constrain(fp,0,100);
  analogOutputs[IDX_FUEL] = gaugeFuelLookup[j];
  analogWrite(pin_GAUGE_FUEL,analogOutputs[IDX_FUEL]);
}


void sendCANupdates()
{
  sendingCANupdates = true;
}

void sendCANVoltage()
{
  sendingCANVoltage = true;
}

void proc_sendCAN_old()
{
  static byte p=0;
  if (!sentCanInputs) return;
  if (!sendingCANupdates && !sendingCANVoltage) return;
  sentCanInputs = false;
  if (sendingCANVoltage)
  {
    sendCAN_voltage();
    sendingCANVoltage = false;
    return;
  }

  switch(p)
  {
    case 0:
      sendCAN_outputs();
      break;
    case 1:
      sendCAN_pwm();
      break;
    case 2:
      sendCAN_frequency();
      break;
    case 3:
      sendingCANupdates = false;
      p=0;
      return;
  }
  p++;
}


void proc_sendCAN()
{
  long t = millis();
  if (SEND_ANALOG)
  {
    if (t-time_Analog > SEND_ANALOG) {time_Analog = t;sendCAN_inputs();}
    return;
  }
  if(SEND_VOLTAGE)
  {
    if (t-time_Voltage > SEND_VOLTAGE) {time_Voltage = t;sendCAN_voltage();}
    return;
  }
  if(SEND_FREQUENCY)
  {
    if (t-time_Frequency > SEND_FREQUENCY) {time_Frequency = t;sendCAN_frequency();}
    return;
  }
  if(SEND_PWM)
  {
    if (t-time_PWM > SEND_PWM) {time_PWM = t;sendCAN_pwm();}
    return;
  }
}

void sendCAN_outputs()
{
  uint8_t buff[] = {0,0,0,0,0,0,0,0};
  unsigned int len = 8;
  int add = CANADD_STATE_OUT;
  for (int i=0;i<8;i++)
  {
    buff[i] = outputs[i];
  }
  bool result = can.transmit(add,buff,len);
}

void sendCAN_pwm()
{
  uint8_t buff[] = {0,0,0,0,0,0,0,0};
  unsigned int len = 8;
  int add = CANADD_STATE_PWM;
  for (int i=0;i<4;i++)
  {
    buff[i] = analogOutputs[i];
  }
  for (int i=4;i<8;i++)
  {
    buff[i] = pwmOutputs[i];
  }
  bool result = can.transmit(add,buff,len);
}

void sendCAN_inputs()
{
  //uint8_t buff[] = {0,0,0,0,0,0,0,0};
  union Data D;
  unsigned int len = 8;
  
  for (int i=0;i<4;i++)
  {
    uint16_t v = (uint16_t) (avgInputs[i] / 128);
    D.ui[i] = v;
  }
  int add = CANADD_ANALOG_IN;
  bool result = can.transmit(add,D.b,len);
  sentCanInputs = true;
}

void sendCAN_voltage()
{
  //uint8_t buff[] = {0,0,0,0,0,0,0,0};
  union Data D;
  D.ui[3] = 0;D.ui[2] = 0;
  unsigned int len = 8;
  uint16_t v = (uint16_t) (avgInputs[4] / 128);
  D.ui[1] = v;
  int x = map(v,0,4095,0,14306);
  x = constrain(x,0,14306);
  D.ui[0] = x;
  int add = CANADD_VOLTAGE;
  bool result = can.transmit(add,D.b,len);
}


void sendCAN_frequency()
{
  //uint8_t buff[] = {0,0,0,0,0,0,0,0};
  union Data D;
  unsigned int len = 8;
  D.ui[0]=0;D.ui[2]=0;D.ui[3] = 0;
  D.ui[1] = Frequency;
  int add = CANADD_STATE_FREQ;
  bool result = can.transmit(add, D.b,len);
}

void reportCAN(eXoCAN *can,byte bytes[])
{
  Serial << "CAN1 Rx <id> " << can->id << "  [" << _HEX(can->id) << "]  " << endl ;
  for (int i=0;i<can->rxMsgLen;i++)
  {
    Serial << _HEX(bytes[i]) << " " ;
  }
  Serial << endl;
}


void setTachoFreq(uint32_t freq)
{
  tachoTimer->setOverflow(freq, HERTZ_FORMAT);
  tachoTimer->setCaptureCompare(1, 50, PERCENT_COMPARE_FORMAT); // 50%
}
