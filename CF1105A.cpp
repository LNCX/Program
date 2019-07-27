#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],ans=0x7fffffff,k;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int t=1;t<=1000;t++)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]+1<t) sum+=t-1-a[i];
            if(t+1<a[i]) sum+=a[i]-1-t;
        }
        if(ans>sum) ans=sum,k=t;
    }
    printf("%d %d\n",k,ans);
    return 0;
}