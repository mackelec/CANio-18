

//uint8_t  gaugeTempCal[][2] = {{0,20},{25,32},{50,141},{75,200},{100,255}};
//uint8_t  gaugeFuelCal[][2] = {{0,28},{25,34},{37,41},{50,52},{62,65},{75,100},{87,130},{95,170},{100,245}};
//uint16_t gaugeTachoCal[][2] = {{0,40},{100,40},{260,100},{500,185},{1000,410},{2000,780},{3000,1170},{4000,1545},{5000,1900},{6000,2320}};   // RPM,frequency
//
//
//uint8_t  gaugeTempLookup[101];
//uint8_t  gaugeFuelLookup[101];
////uint16_t gaugeTachoLookup[101];
//uint16_t gaugeRPMLookup[6001];
//
////  char const * msg[] = 
////  char const * const msg[] = 
//
//void fillLookups()
//{
//  int st = sizeof(gaugeTempCal)/2;
//  int sf = sizeof(gaugeFuelCal)/2;
//  int sfq = sizeof(gaugeTachoCal)/4;
//
//  
//  
//  long t1 = micros();
//
//  //---- temps
//  
//  for (int i=0;i<101;i++)
//  {
//    int x1,x2,y1,y2;
//    uint8_t x;
//    bool done=0;
//    for (int j=0;j<st;j++)
//    {
//      if (i == gaugeTempCal[j][0])
//      {
//        gaugeTempLookup[i] = gaugeTempCal[j][1];
//        break;
//      }
//      if (j==0) continue;
//      if (i > gaugeTempCal[j-1][0] && i < gaugeTempCal[j][0])
//      {
//        x = map(i,gaugeTempCal[j-1][0],gaugeTempCal[j][0],gaugeTempCal[j-1][1],gaugeTempCal[j][1]);
//        gaugeTempLookup[i] =  x;
//        break;
//      }
//    }
//  }
//  
//  //-----  Fuel
//
//  for (int i=0;i<101;i++)
//  {
//    int x1,x2,y1,y2;
//    int x;
//    bool done=0;
//    for (int j=0;j<sf;j++)
//    {
//      if (i == gaugeFuelCal[j][0])
//      {
//        gaugeFuelLookup[i] = gaugeFuelCal[j][1];
//        break;
//      }
//      if (j==0) continue;
//      x1 = gaugeFuelCal[j-1][0];
//      x2 = gaugeFuelCal[j][0];
//      if (i > gaugeFuelCal[j-1][0] && i < gaugeFuelCal[j][0])
//      {
//        x = map(i,gaugeFuelCal[j-1][0],gaugeFuelCal[j][0],gaugeFuelCal[j-1][1],gaugeFuelCal[j][1]);
//        gaugeFuelLookup[i] = (uint16_t) x;
//        break;
//      }
//    }
//  }
//
//    //--- Tacho
//  
////  for (int i=0;i<101;i++)
////  {
////    int x1,x2,y1,y2;
////    int x;
////    bool done=0;
////    for (int j=0;j<sfq;j++)
////    {
////      int p = map(gaugeTachoCal[j][0],0,RPM_MAX,0,100);
////      p= constrain(p,0,100);
////      if (i == p)
////      {
////        gaugeTachoLookup[i] = gaugeTachoCal[j][1];
////        break;
////      }
////      if (j==0) continue;
////      x1 = map(gaugeTachoCal[j-1][0],0,RPM_MAX,0,100);
////      x2 = map(gaugeTachoCal[j][0],0,RPM_MAX,0,100);
////      if (i > x1 && i < x2)
////      {
////        x = map(i,x1,x2,gaugeTachoCal[j-1][1],gaugeTachoCal[j][1]);
////        gaugeTachoLookup[i] = (uint16_t) x;
////        break;
////      }
////    }
////  }
//
////  ----  RPM
//
//  for (int i=0;i<6001;i++)
//  {
//    int x1,x2,y1,y2;
//    int x;
//    bool done=0;
//    for (int j=0;j<sfq;j++)
//    {
//      if (i == gaugeTachoCal[j][0])
//      {
//        gaugeRPMLookup[i] = gaugeTachoCal[j][1];
//        break;
//      }
//      if (j==0) continue;
//      x1 = gaugeTachoCal[j-1][0];
//      x2 = gaugeTachoCal[j][0];
//      if (i > x1 && i < x2)
//      {
//        x = map(i,x1,x2,gaugeTachoCal[j-1][1],gaugeTachoCal[j][1]);
//        gaugeRPMLookup[i] = (uint16_t) x;
//        break;
//      }
//    }
//  }
//  
//  long t2 = micros();
////  Serial << "Time taken = " << (t2-t1) << endl;
////  Serial << endl;
////  for (int i=0;i < 101 ; i++)
////  {
////    Serial << i << "% Temp gauge = " <<  gaugeTempLookup[i] << endl;
////  }
////  Serial << endl;
////  for (int i=0;i < 101 ; i++)
////  {
////    Serial << i << "% Fuel gauge = " <<  gaugeFuelLookup[i] << endl;
////  }
////  Serial << endl;
//////  for (int i=0;i < 101 ; i++)
//////  {
//////    Serial << i << "% Tacho = " <<  gaugeTachoLookup[i] << endl;
//////  }
//////  Serial << endl;
////  for (int i=0;i<6001;i++)
////  {
////    Serial << i << "% RPM = " <<  gaugeRPMLookup[i] << endl;
////  }
////  Serial << endl;
//}
