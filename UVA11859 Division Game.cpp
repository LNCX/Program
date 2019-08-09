#include<bits/stdc++.h>
using namespace std;
const int N=55;
int cnt[10005];
void divide()
{
    for(int n=2;n<=10000;n++)
    {
        int x=n;
        for(int i=2;i*i<=n;i++)
            if(x%i==0)
                while(x%i==0) 
                    x/=i,cnt[n]++;
        if(x>1) cnt[n]++;
    }
}
int main()
{
    divide();
    int t;
    cin>>t;
    for(int o=1;o<=t;o++)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int x,sum=0;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                sum+=cnt[x];
            }
            ans^=sum;
        }
        printf("Case #%d: ",o);
        ans==0?puts("NO"):puts("YES");
    }
    return 0;
}