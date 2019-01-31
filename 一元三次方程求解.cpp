#include<cstdio>
#include<iostream>
using namespace std;
float a,b,c,d;
float f(float x){return (a*x*x*x+b*x*x+c*x+d);}
void search(float l,float r)
{
    float mid=(l+r)/2;
    if(r-l<0.0005){printf("%.2f ",mid); return;}
    else if(f(mid)==0) printf("%.2f ",mid);
    else if(f(r)==0) printf("%.2f ",r);//不搜索l，做到不重复。
    if(f(l)*f(mid)<0) search(l,mid);
    if(f(mid)*f(r)<0) search(mid,r);
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int x=-200;x<=200;x++)
    if(f(x)*f(x+1.0)<=0)
    search(x,x+1.0);
}
