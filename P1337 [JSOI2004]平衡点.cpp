#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct point
{
    long double x,y,w;
}a[N],ans,now;
int n;
long double sx,sy;
long double cal(long double x,long double y)
{
    long double res=0;
    for(int i=1;i<=n;i++)
        res+=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y))*a[i].w;
    return res;
}
void SA()
{
    now.x=sx/n,now.y=sy/n,now.w=cal(now.x,now.y);
    long double T=2000,delta=0.995;
    while(T>1e-14)
    {   
        long double x=now.x+((rand()<<1)-RAND_MAX)*T;
        long double y=now.y+((rand()<<1)-RAND_MAX)*T;
        long double w=cal(x,y);
        long double d=w-now.w;
        if(d<0) {now=(point){x,y,w};}
        else if(exp(-d/T)*RAND_MAX>rand()) now=(point){x,y,w};
        if(ans.w>now.w) ans=now;
        T*=delta;
    }
}
void solve()
{
    ans.w=1e20+5;
        SA();
}
int main()
{
    srand(19260817),srand(rand()),srand(rand());
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%Lf%Lf%Lf",&a[i].x,&a[i].y,&a[i].w);
        sx+=a[i].x,sy+=a[i].y;
    }
    solve();
    printf("%.3Lf %.3Lf\n",ans.x,ans.y);
    return 0;
}