#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
map<int,int>b;
int a[N],sum[N],ans;
int cal(int x)
{
    int cnt=0;
    for(int i=2;i*i<=x;i++)
        while(x%i==0)
        {
            x/=i;
            if(b[i]) cnt--;
            else cnt++;
        }
    if(x!=1)
    {
        if(b[x]) cnt--;
        else cnt++;
    }
    return cnt;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sum[1]=a[1];
    for(int i=2;i<=n;i++)
        sum[i]=__gcd(sum[i-1],a[i]);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        b[x]=1;
    }
    for(int i=n;i>=1;i--)
    {
        int cnt=cal(sum[i]),p=sum[i];
        for(int j=1;j<=i&&cnt<0;j++)
        {
            sum[j]/=p;
            a[j]/=p;
        }
    }
    for(int i=1;i<=n;i++) 
        ans+=cal(a[i]);
    cout<<ans<<endl;
}