#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn],b[maxn];
int main()
{
    int n,cnt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;b[y]++;
    }
    for(int i=1;i<maxn;i++)
    {
        if(!cnt&&a[i]) 
            printf("%d ",i);
        cnt+=a[i]-b[i];
        if(!cnt&&b[i]) 
            printf("%d\n",i);
    }
}