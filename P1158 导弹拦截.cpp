#include<bits/stdc++.h>
#define dis(x0,y0,x1,y1) ((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1))
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||'9'<c) c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
int main()
{
    int x0=read(),y0=read(),x1=read(),y1=read(),n=read(),r0=0,r1=0;
    for(int i=1;i<=n;i++)
    { 
        int x=read(),y=read();
        int a=dis(x,y,x0,y0),b=dis(x,y,x1,y1);
        if(a<=r0||b<=r1) continue;
        if(a-r0<=b-r1) r0=a;
        else r1=b;
    }
    cout<<r1+r0<<endl;
    return 0;
}