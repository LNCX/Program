#include <iostream>
#include <cfloat>
#include <iomanip>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi=asin(1)*2;
double p2s(double x,double y, double x1,double y1, double x2,double y2)
{
    double dis = 0.f;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double k = -((x1 - x)*dx + (y1 - y)*dy) / ( dx*dx + dy*dy);
    double footX = k*dx + x1;
    double footY = k*dy + y1;
    if( footY >= min(y1, y2) && footY <=max(y1, y2)
        && footX >= min(x1, x2) && footX <=max(x1, x2 ) )
    {
        dis = ((footX-x)*(footX-x) + (footY-y)*(footY-y));
    }
    else
    {
        double dis1 = ((x1-x)*(x1-x) + (y1-y)*(y1-y));
        double dis2 = ((x2-x)*(x2-x) + (y2-y)*(y2-y));

        dis = ( dis1 < dis2 ? dis1 : dis2 );
    }

    return dis;
}
int main()
{
    int n;
    cin>>n;
    double x,y;
    cin>>x>>y;
    double maxer=0;
    double miner=DBL_MAX;
    double lastx ;
    double lasty ;
    double firstx;
    double firsty;
    for(int i=0;i<n;i++)
    {
        double tx,ty;
        cin>>tx>>ty;
        double temper=(tx-x)*(tx-x)+(ty-y)*(ty-y);
        if(temper+eps>maxer)
        {
            maxer=temper+eps;
        }
        if(temper-eps<miner)
        {
            miner=temper;
        }
        if(i!=0)
        {
            double temp = p2s(x,y,lastx,lasty,tx,ty);
            if(temp-eps<miner)
            {
                miner=temp;
            }
            if(i==n-1)
            {

                temp=p2s(x,y,firstx,firsty,tx,ty);

                if(temp-eps<miner)
                {
                    miner=temp;
                }
            }
        }
        else
        {
            firstx=tx;
            firsty=ty;
        }
        lastx=tx;
        lasty=ty;
    }
    cout<<fixed<<setprecision(7)<<((maxer*pi)-(miner*pi))<<endl;
    return 0;
}
