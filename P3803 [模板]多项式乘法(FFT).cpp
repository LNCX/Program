#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e7+5;
const double pi=acos(-1);
int n,m,rev[maxn];
struct complex
{
    double x,y;
    complex (double a=0,double b=0)
    {
        x=a,y=b;
    }
    complex operator+ (const complex a) const
    {
        return complex(a.x+x,a.y+y);
    }
    complex operator- (const complex a) const
    {
        return complex(x-a.x,y-a.y);
    }
    complex operator* (const complex a) const
    {
        return complex(a.x*x-a.y*y,a.y*x+a.x*y);
    }
}a[maxn],b[maxn];
void FFT(complex *a,int lim,int type)
{
    for(int i=0;i<lim;i++) 
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(int i=1;i<lim;i<<=1)
    {
        complex Wn(cos(pi/i),type*sin(pi/i)); 
        for(int j=0;j<lim;j+=(i<<1))
        {
            complex w(1,0);
            for(int k=0;k<i;k++,w=w*Wn)
            {
                complex x=a[j+k],y=w*a[j+i+k];
                a[j+k]=x+y;
                a[j+i+k]=x-y;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) scanf("%lf",&a[i].x);
    for(int i=0;i<=m;i++) scanf("%lf",&b[i].x);
    int lim=1,l=0;
    while(lim<=n+m)
    {
        lim<<=1;
        l++;
    }
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    FFT(a,lim,1),FFT(b,lim,1);
    for(int i=0;i<=lim;i++)
        a[i]=a[i]*b[i];
    FFT(a,lim,-1);
    for(int i=0;i<=n+m;i++) 
        printf("%d ",(int)(a[i].x/(double)lim+0.5));
    puts("");
    return 0;
}