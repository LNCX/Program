#include<bits/stdc++.h>
using namespace std;
double D,sum,d,c,p;
double q[10001][2];
int n;
int main()
{
    scanf("%lf%lf%lf%lf%d",&d,&c,&D,&p,&n);
    q[1][0]=c;
    q[1][1]=p;
    int p1=1,p2=1;
    double re=c,sum=p*c,last=0;
    for(int i=1;i<=n;++i)
    {
        double price,dis;
        scanf("%lf%lf",&dis,&price);
        double tmp=dis;
        if(i==n)
        d=d-dis;
        dis=dis-last;
        last=tmp;     
        while(dis>=D*q[p1][0])  
        {
            re-=q[p1][0];
            dis-=D*q[p1][0];
            p1++;
            if(p1>p2)  
                return puts("No Solution"),0;
        }
        re-=dis/D;
        q[p1][0]-=dis/D;
        while(price<q[p2][1]&&p2>=p1)  
        {
            sum-=q[p2][0]*q[p2][1];
            re-=q[p2][0];
            p2--;  
        }
        q[++p2][0]=c-re;
        q[p2][1]=price;
        re=c;
        sum+=q[p2][0]*q[p2][1]; 
    }
    if(c*D<d) return puts("No Solution"),0;
    while(d>=D*q[p1][0])
    {
        d-=D*q[p1][0];
        p1++;
    }
    q[p1][0]-=d/D;
    while(p1<=p2)
    sum-=q[p1][0]*q[p1][1],p1++;
    printf("%.2lf",sum);
}