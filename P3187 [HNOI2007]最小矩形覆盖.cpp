#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
using namespace std;
double ans=1e60;
int n,top;
struct point
{
    double x,y;
    point(){}
    point(double _x, double _y):x(_x),y(_y){}
    friend bool operator<(point a, point b){return fabs(a.y-b.y)<eps?a.x<b.x:a.y<b.y;}
    friend bool operator==(point a, point b){return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps;}
    friend point operator+(point a, point b){return point(a.x+b.x,a.y+b.y);}
    friend point operator-(point a, point b){return point (a.x-b.x,a.y-b.y);}
    friend point operator*(point a, double b){return point (a.x*b,a.y*b);}
    friend double operator*(point a, point b){return a.x*b.y-a.y*b.x;}
    friend double operator/(point a, point b){return a.x*b.x+a.y*b.y;}
    friend double dis(point a){return sqrt(a.x*a.x+a.y*a.y);}
}p[50005],q[50005],t[5];
bool cmp(point a, point b)
{
    double t=(a-p[1])*(b-p[1]);
    if(fabs(t)<eps) return dis(p[1]-a)-dis(p[1]-b)<0;
    return t>0;
}
void Graham()
{
    for(int i=2;i<=n;i++)
        if(p[i]<p[1]) swap(p[1],p[i]);
    sort(p+2,p+n+1,cmp);
    q[++top]=p[1];
    for(int i=2;i<=n;i++)
    {
        while(top>1&&(q[top]-q[top-1])*(p[i]-q[top])<eps) top--;
        q[++top]=p[i];
    } 
    q[0]=q[top];
}
void RC()
{
    int l=1,r=1,p=1;
    double L,R,D,H;
    for(int i=0;i<top;i++)
    {
        D=dis(q[i]-q[i+1]);
        while((q[i+1]-q[i])*(q[p+1]-q[i])-(q[i+1]-q[i])*(q[p]-q[i])>-eps) p=(p+1)%top;
        while((q[i+1]-q[i])/(q[r+1]-q[i])-(q[i+1]-q[i])/(q[r]-q[i])>-eps) r=(r+1)%top;
        if(i==0) l=r;
        while ((q[i+1]-q[i])/(q[l+1]-q[i])-(q[i+1]-q[i])/(q[l]-q[i])<eps) l=(l+1)%top;
        L=(q[i+1]-q[i])/(q[l]-q[i])/D;
        R=(q[i+1]-q[i])/(q[r]-q[i])/D;
        H=(q[i+1]-q[i])*(q[p]-q[i])/D;
        double tmp=fabs(H)*(R-L);
        if(tmp<ans)
        {
            ans=tmp;
            t[0]=q[i]+(q[i+1]-q[i])*(R/D);
            t[1]=t[0]+(q[r]-t[0])*(H/dis(t[0]-q[r]));
            t[2]=t[1]-(t[0]-q[i])*((R-L)/dis(q[i]-t[0]));
            t[3]=t[2]-(t[1]-t[0]);
        }
    }
}
double turn(double x){return fabs(x-0.0)<eps?0:x;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%lf%lf",&p[i].x,&p[i].y);
    Graham();
    RC();
    printf("%.5lf\n",ans);
    int fir=0;
    for(int i=1;i<=3;i++)
        if(t[i]<t[fir]) fir=i;
    for(int i=0;i<=3;i++)
        printf("%.5lf %.5lf\n",turn(t[(i+fir)%4].x),turn(t[(i+fir)%4].y));
    return 0;
}