#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double h,s1,v,l,k;
    scanf("%lf%lf%lf%lf%lf%d",&h,&s1,&v,&l,&k,&n);
    double maxn=sqrt(h/5);
    double minn=sqrt((h-k)/5);
    int a=min(int(s1-minn*v+l),n),b=max(int(s1-maxn*v),0);
    cout<<a-b<<endl;
}
