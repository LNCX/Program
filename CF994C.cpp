#include<iostream>
using namespace std;
int x1[5],y1[5],x2[5],y2[5];
int main()
{
    int min1x,min1y,max1x,max1y,min2x,min2y,max2x,max2y;
    for(int i=0;i<4;i++)
        cin>>x1[i]>>y1[i];
    min1x=min(min(x1[0],x1[1]),min(x1[2],x1[3]));
    max1x=max(max(x1[0],x1[1]),max(x1[2],x1[3]));
    min1y=min(min(y1[0],y1[1]),min(y1[2],y1[3]));
    max1y=max(max(y1[0],y1[1]),max(y1[2],y1[3]));
    for(int i=0;i<4;i++)
    {
        cin>>x2[i]>>y2[i];
        x1[i]=x2[i]+y2[i];
        y1[i]=x2[i]-y2[i];
    }
    min2x=min(min(x1[0],x1[1]),min(x1[2],x1[3]));
    max2x=max(max(x1[0],x1[1]),max(x1[2],x1[3]));
    min2y=min(min(y1[0],y1[1]),min(y1[2],y1[3]));
    max2y=max(max(y1[0],y1[1]),max(y1[2],y1[3]));
    for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
            if(min1x<=i&&i<=max1x&&min1y<=j&&j<=max1y&&min2x<=i+j&&max2x>=i+j&&min2y<=i-j&&max2y>=i-j)
            {
                cout<<"YES"<<endl;
                return 0;
            }
    cout<<"NO"<<endl;
}