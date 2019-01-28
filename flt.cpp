#include "flt.h"

Filter :: Filter(void) { Ready=0; }

Filter :: Filter(float H,float T)
{
Ready=0;
Ini(H,T);
}


void Filter :: Ini(float H,float T)
{
if(!T || (T < 2*H)) return;
V = (1.0-H /(2*T))/(1.0+H /(2*T));
W = (H /(2*T)) / (1.0+H /(2*T));
Enter = 0;
Ready = 1;
}


float Filter :: Go(float val)
{
float	valn;
if(!Ready) return(val);
if(!Enter) { last = lastf = ( (float) val*((1.-W)/(W+V))); Enter = 1; }
try {
valn = (float) (V*(float)lastf+W*((float)last+(float)val));
    }
    catch(...) {
        valn = 0;
        }
last = val;
lastf = valn;
return(valn);
}


void Filter :: Reset(void)
{
Enter = 0;
}
