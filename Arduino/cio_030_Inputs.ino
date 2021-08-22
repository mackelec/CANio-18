bool notNew[]={0,0,0,0,0};
uint32_t lastavg[] = {0,0,0,0,0};

void readADC()
{
  static byte p=0;
  
  switch (p)
  {
    case 0:
      adcInputs[p] = analogRead(pin_AIN1);
      break;
    case 1:
      adcInputs[p] = analogRead(pin_AIN2);
      break;
    case 2:
      adcInputs[p] = analogRead(pin_AIN3);
      break;
    case 3:
      adcInputs[p] = analogRead(pin_AIN4);
      break;
    case 4:
      adcInputs[p] = analogRead(pin_AIN_VIN);
      break;
  }
  if (!notNew[p]) 
  {
    avgInputs[p] = adcInputs[p] * 128;
    notNew[p] = true;
  }
  avgInputs[p] = smoothX128(avgInputs[p],adcInputs[p],8);
  p++;
  if (p > 5) p=0;
}


long smoothX128(long avg, int adc, int weight)
{
  long result;
  result = ( long) (avg + ((long) (adc * 128L) - avg) / (long) weight);
  return (result);
}
