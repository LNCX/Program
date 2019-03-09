#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double ox,oy;
struct point
{
    int x,y,op;
    double angle;
    friend bool operator<(point a,point b)
    {
        return a.angle-b.angle<0;
    }
    void init()
    {
        scanf("%d%d%d",&op,&x,&y);
        angle=atan2(y-oy,x-ox);
    }
};
set<point>s;
point pre(point x)
{
    if(s.count(x)>0)
        return x;
    auto it=s.lower_bound(x);
    if(it==s.begin())
        it=s.end();
    return *--it;
}
point nxt(point x)
{
    auto it=s.upper_bound(x);
    if(it==s.end())
        it=s.begin();
    return *it;
}
ll cross(point a,point b,point o)
{
    return ll(a.x-o.x)*(b.y-o.y)-ll(b.x-o.x)*(a.y-o.y);
}
bool ask(point x)
{
    if(s.size()<3) return false;
    point p=pre(x);
    point n=nxt(x);
    return cross(p,n,x)>=0;
}
void add(point x)
{ 
    if(ask(x)) return;
    while(1)
    {
        point a=nxt(x);
        s.erase(a);
        point b=nxt(x);
        if(cross(x,b,a)<0)
        {
            s.insert(a);
            break;
        }
    }
    while(1)
    {
        point a=pre(x);
        s.erase(a);
        point b=pre(x);
        if(cross(b,x,a)<0)
        {
            s.insert(a);
            break;
        }
    }
    s.insert(x);
}
int q;
void start()
{
    point a[4];
    double t[4]={0,0.55,0.66,0.77};
    for(int i=1;i<=3;i++)
    {
        a[i].init();
        ox+=a[i].x*t[i],oy+=a[i].y*t[i];
    }
    ox/=1.98,oy/=1.98;//sum t
    q-=3;
    for(int i=1;i<=3;i++)
    {
        a[i].angle=atan2(a[i].y-oy,a[i].x-ox);
        s.insert(a[i]);
    }
}
int main()
{
    cin>>q;
    start();
    for(int i=1;i<=q;i++)
    {
        point a;
        a.init();
        if(a.op==1) add(a);
        else ask(a)?puts("YES"):puts("NO");
    }
    return 0;
}