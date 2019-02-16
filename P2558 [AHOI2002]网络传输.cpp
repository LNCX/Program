#include<bits/stdc++.h>
using namespace std;
int k,p,ans[60]={0},x[60]={0,1};
int main()
{
    scanf("%d%d",&k,&p);
    while(p)
    {
        if(p&1)
        {
            for(int i=1;i<=50;i++)
                ans[i]+=x[i];
            for(int i=1;i<=49;i++)
                ans[i+1]+=ans[i]/10,ans[i]=ans[i]%10;
        }
        for(int i=1;i<=50;i++)
            x[i]*=k;
        for(int i=1;i<=49;i++)
            x[i+1]+=x[i]/10,x[i]=x[i]%10;
        p=p>>1;
    }
    for(int i=50,t=0;i>=1;i--) 
    {
        if(ans[i]) t=1;
        if(t) printf("%d",ans[i]);
    }
    return 0;
}