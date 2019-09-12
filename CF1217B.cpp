#include<bits/stdc++.h>
using namespace std;
const int N=105;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum,ans=0,d=0,d2=0;
        scanf("%d%d",&n,&sum);
        for(int i=1;i<=n;i++)
        {
            int t1,t2;
            scanf("%d%d",&t1,&t2),d=max(d,t2-t1),d2=max(d2,t2);
        }
        if(d<sum&&d2<sum) puts("-1");
        else 
        {
            
        }
    }
    return 0;
}