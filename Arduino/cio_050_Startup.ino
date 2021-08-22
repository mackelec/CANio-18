
bool startupDone = false;

void runStartup()
{
  digitalWrite(LAMP_GLOWPLUG,HIGH);
  delay(250);
  digitalWrite(LAMP_SEDIMENTER,HIGH);
  delay(250);
  digitalWrite(LAMP_OIL,HIGH);
  delay(250);
  digitalWrite(LAMP_ALTERNATOR,HIGH);
  delay(500);
  digitalWrite(LAMP_ALTERNATOR,LOW);
  delay(250);
  digitalWrite(LAMP_OIL,LOW);
  delay(250);
  digitalWrite(LAMP_SEDIMENTER,LOW);
  delay(250);
  digitalWrite(LAMP_GLOWPLUG,LOW);
  
}

void runStartup_test()
{
  if (startupDone) return;
  static int _freq=50;
  static int count=0;
  static int g1=0,g2=0,g3=0,g4=0;
  static bool out1=0,out2=0,out3=0,out4=0;
  static int p1=0,p2=0,p3=0;

  if (count < 255)
  {
    _freq += 10;
    g1=count;
    g2=count;
    g3=count;
    g4=count;
    p1=count;
    p2=count;
    p3=count;
    out1=true;
    out2=true;
    out3=true;
    out4=true;
  }
  else
  {
    _freq -= 10;
    g1=512 - count;
    g2=512 - count;
    g3=512 - count;
    g4=512 - count;
    p1=512 - count;
    p2=512 - count;
    p3=512 - count;
    out1=0;
    out2=0;
    out3=0;
    out4=0;
  }
  constrain(g1,0,255);
  constrain(g2,0,255);
  constrain(g3,0,255);
  constrain(g4,0,255);
  constrain(p1,0,255);
  constrain(p2,0,255);
  constrain(p3,0,255);
  analogWrite(pin_PWM1,g1);
  analogWrite(pin_PWM2,g2);
  analogWrite(pin_PWM3,g3);
  analogWrite(pin_PWM4,g4);
  analogWrite(pin_OUT5,p1);
  analogWrite(pin_OUT6,p2);
  analogWrite(pin_OUT7,p3);

  digitalWrite(pin_OUT1,out1);
  digitalWrite(pin_OUT2,out2);
  digitalWrite(pin_OUT3,out3);
  digitalWrite(pin_OUT4,out4);
  
  constrain(_freq,0,2500);
  //tone(pin_OUT8,_freq);
  count ++;
  if (count > 512) 
  {
    startupDone = true;
    tone(pin_OUT8,0);
    analogWrite(pin_PWM1,128);
    digitalWrite(pin_OUT8,0);
  }
}
