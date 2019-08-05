#include<bits/stdc++.h>
using namespace std;
const int N=5005;
double x[N+5],y[N+5],x2[N+5],y2[N+5];
double t1[N+5],t2[N+5];
inline double dis(int i,int j){return sqrt((x[i]-x2[j])*(x[i]-x2[j])+(y[i]-y2[j])*(y[i]-y2[j]));}
double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,p,q,r,ans=1e18;
int main()
{
    scanf("%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By);
    scanf("%lf%lf%lf%lf",&Cx,&Cy,&Dx,&Dy);
    scanf("%lf%lf%lf",&p,&q,&r);
    double dx=(Bx-Ax)/N,dy=(By-Ay)/N;
    for(int i=0;i<=N;++i)
    {
        x[i]=Ax+dx*i,y[i]=Ay+dy*i;
        t1[i]=sqrt(dx*i*dx*i+dy*i*dy*i)/p;
    }
    dx=(Dx-Cx)/N,dy=(Dy-Cy)/N;
    for(int i=0;i<=N;++i)
    {
        x2[i]=Dx-dx*i,y2[i]=Dy-dy*i;
        t2[i]=sqrt(dx*i*dx*i+dy*i*dy*i)/q;
    }
    for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)
    ans=min(ans,t1[i]+t2[j]+dis(i,j)/r);
    printf("%.2lf\n",ans);return 0;
}