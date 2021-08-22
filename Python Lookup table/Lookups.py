

#  Prominent Arduino map function :)
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

def _contrain(x,in_min,in_max):
    y=x
    if x < in_min : y = in_min
    if x > in_max : y = in_max
    return y



gaugeTempCal = [[0,20],[25,32],[50,141],[75,200],[100,255]]
gaugeFuelCal= [[0,28],[25,34],[37,41],[50,52],[62,65],[75,100],[87,130],[95,170],[100,245]]
gaugeTachoCal=[[0,40,],[100,40],[260,100],[500,185],[1000,410],[2000,780],[3000,1170],[4000,1545],[5000,1900],[6000,2320]]

gaugeTempLookup = [None]*101
gaugeFuelLookup = [None]*101
gaugeRPMLookup  = [None]*6001

def testprint():
    for i in range(0,101):
        print ('Temp ', i,'% ', gaugeTempLookup[i])
    print('\n')
    for i in range(0,101):
        print ('Fuel ', i,'% ', gaugeFuelLookup[i])
    print('\n')
    for i in range(len(gaugeRPMLookup)):
        print ('RPM ', i,' ', gaugeRPMLookup[i])

#   ----  Temperature

for i in range(0,101):
    for j in range(len(gaugeTempCal)):
        if i ==  gaugeTempCal[j][0] :
            gaugeTempLookup[i] = gaugeTempCal[j][1]
            #a = gaugeTempCal[j][1]
            #gaugeTempLookup[i] = a
            break
        if j == 0 : continue
        if i>gaugeTempCal[j-1][0] and i < gaugeTempCal[j][0]:
            x = _map(i,gaugeTempCal[j-1][0],gaugeTempCal[j][0],gaugeTempCal[j-1][1],gaugeTempCal[j][1])
            gaugeTempLookup[i] = int(x)
            break
        
#    ----   Fuel

for i in range(0,101):
    for j in range(len(gaugeFuelCal)):
        if i ==  gaugeFuelCal[j][0] :
            gaugeFuelLookup[i] = gaugeFuelCal[j][1]
            break
        if j == 0 : continue
        if i>gaugeFuelCal[j-1][0] and i < gaugeFuelCal[j][0]:
            x = _map(i,gaugeFuelCal[j-1][0],gaugeFuelCal[j][0],gaugeFuelCal[j-1][1],gaugeFuelCal[j][1])
            gaugeFuelLookup[i] = int(x)
            break

#    ----  RPM

for i in range(len(gaugeRPMLookup)):
    for j in range(len(gaugeTachoCal)):
        if i ==  gaugeTachoCal[j][0] :
            gaugeRPMLookup[i] = gaugeTachoCal[j][1]
            break
        if j == 0 : continue
        if i>gaugeTachoCal[j-1][0] and i < gaugeTachoCal[j][0]:
            x = _map(i,gaugeTachoCal[j-1][0],gaugeTachoCal[j][0],gaugeTachoCal[j-1][1],gaugeTachoCal[j][1])
            gaugeRPMLookup[i] = int(x)
            break

print ("char const gaugeTempLookup[] = {")
c=0
while c<len(gaugeTempLookup):
    print ("                                       ",end=" ")
    for i in range(10):
        print(gaugeTempLookup[c],end =" ")
        c = c+1
        if c>=len(gaugeTempLookup): break
        print(',',end =" ")
    print(' ')
print('                            };')

print ("char const gaugeFuelLookup[] = {")

c=0
while c<len(gaugeFuelLookup):
    print ("                                       ",end=" ")
    for i in range(10):
        print(gaugeFuelLookup[c],end =" ")
        c = c+1
        if c>=len(gaugeFuelLookup): break
        print(',',end =" ")
    print(' ')
print('                            };')

print ("char const gaugeRPMLookup[]  = {")

c=0
while c<len(gaugeRPMLookup):
    print ("                                       ",end=" ")
    for i in range(10):
        print(gaugeRPMLookup[c],end =" ")
        c = c+1
        if c>=len(gaugeRPMLookup): break
        print(',',end =" ")
    print(' ')
print('                            };')
testprint()

