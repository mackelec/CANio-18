
/*---------------------------------------------
 * 
 *    Really basic Scheduler
 * 
 ----------------------------------------------*/


void loop_1()
{
  readCAN();
}

void loop_10()
{
  readADC();
  //runStartup();
  proc_sendCAN();
}

void loop_50()
{
  
}

void loop_100()
{
  //sendCAN_inputs();
}

void loop_500()
{
  //sendCANVoltage();
}

void loop_1000()
{
  digitalToggle(LED);
}
void loop_3000()
{
  //sendCANupdates();
}





long mil,mil_10=0,mil_50=0,mil_100=0,mil_500,mil_1000=0,mil_3000=0;

void loop() 
{
  
  if (millis() != mil)
  {
    mil = millis();
    loop_1();
    if (mil-mil_10>9)
    {
      mil_10 = mil;
      loop_10();
      if (mil-mil_50>49)
      {
        mil_50 = mil;
        loop_50();
        if (mil-mil_100>99)
        {
          mil_100 = mil;
          loop_100();
          if (mil-mil_500>499)
          {
            mil_500 = mil;
            loop_500();
          }
          if (mil-mil_1000>999)
          {
            mil_1000 = mil;
            loop_1000();
            if (mil-mil_3000>2999)
            {
              mil_3000 = mil;
              loop_3000();
            }
          }
        }
      }
    }
  }
}



void flash()
{
  digitalToggle(LED);
}
