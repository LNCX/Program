#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL fac[25]={1},n,k,x,val[25];
bool vis[25];
void turn_1(int x)
{
    memset(vis,0,sizeof vis);
    x--;
    int j;
    for(int i=1;i<=n;i++)
    {
        int t=x/fac[n-i];
        for(j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                if(!t)
                    break;
                t--;
            }
        }
        printf("%d ",j);
        vis[j]=1;
        x%=fac[n-i];
    }
    puts("");
}
LL turn(LL x[])
{
    int p=0;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        for(int j=i+1;j<=n;j++)
            if(x[i]>x[j]) t++;
        p+=t*fac[n-i];
    }
    return p+1;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) 
        fac[i]=fac[i-1]*i;
    while(k--)
    {
        char ch;cin>>ch;
        if(ch=='P') scanf("%lld",&x),turn_1(x);
        else
        {
            for(int i=1;i<=n;i++) 
                scanf("%lld",&val[i]);
            printf("%lld\n",turn(val));
        }
    }
    return 0;
}