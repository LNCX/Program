#include<bits/stdc++.h>
using namespace std;
const int N=1005,inf=0x3f3f3f3f;
struct point 
{
    double x,y;
};
point p[N],s[N];
int n;
double dir(point p1,point p2,point p3)
{
    return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);
}
double dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool comp(point p1,point p2)
{
    double te=dir(p[0],p1,p2);
    if(te<0)return 1;
    if(te==0&&dis(p[0],p1)<dis(p[0],p2))return 1;
    return 0;
}
double Graham()
{
    int pos;
    double minx,miny;
    minx=miny=inf;
    for(int i=0;i<n;i++)
    {
        if(p[i].x<minx||(p[i].x==minx&&p[i].y<miny))
        {
            minx=p[i].x;
            miny=p[i].y;
            pos=i;
        }
    }
    swap(p[0],p[pos]);
    sort(p+1,p+n,comp);
    int top=2;
    p[n]=p[0];
    s[0]=p[0],s[1]=p[1],s[2]=p[2];
    for(int i=3;i<=n;i++)
    {
        while(top>=2&&dir(s[top-1],s[top],p[i])>=0)top--;
        s[++top]=p[i];
    }
    double ans=0;
    for(int i=1;i<top-1;i++)
        ans-=dir(s[0],s[i],s[i+1]);
    return ans/2;
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>p[i].x>>p[i].y;
        printf("%.2lf",abs(Graham()));
    }
    return 0;
}