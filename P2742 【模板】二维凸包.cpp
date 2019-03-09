#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
struct point
{
    double x,y;
}p[maxn],s[maxn];
int n;
double ans,mid;
double compare(point a1,point a2,point b1,point b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
double dis(point p1,point p2)
{
    return sqrt( (double)(p2.y-p1.y)*(p2.y-p1.y)*1.0+(double)(p2.x-p1.x)*(p2.x-p1.x)*1.0 );
}
bool cmp(point p1,point p2)
{
    double tmp=compare(p[1],p1,p[1],p2);
    if(tmp>0) return true;
    if(tmp==0&&dis(p[0],p1)<dis(p[0],p2)) return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(p[i].y<p[1].y)
            swap(p[1],p[i]);
    } 
    sort(p+2,p+1+n,cmp);
    s[1]=p[1];
    int tot=1;
    for(int i=2;i<=n;i++)
    {
        while(tot>1&&compare(s[tot-1],s[tot],s[tot],p[i])<=0) tot--;
        tot++;
        s[tot]=p[i];
    }
    s[tot+1]=p[1];
    for(int i=1;i<=tot;i++)
        ans+=dis(s[i],s[i+1]);
    printf("%.2lf\n",ans);
    return 0;
}